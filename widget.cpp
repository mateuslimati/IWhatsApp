#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include "icons.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("iWhatsApp");

    QPixmap wpp(wppIcon);
    ui->icon->setPixmap(wpp.scaled(161,111,Qt::KeepAspectRatio));

    QPixmap pix(sendIcon);
    QPixmap qt(quitIcon);
    QPixmap acc(wppIconLow);

    QIcon Button2(qt);
    QIcon ButtonIcon(pix);
    QIcon ButtonAcc(acc);

    ui->pushButton_2->setIcon(qt.scaled(81,70, Qt::KeepAspectRatio));
    ui->send->setIcon(pix.scaled(81,41, Qt::KeepAspectRatio));
    ui->account->setIcon(acc.scaled(81,41, Qt::KeepAspectRatio));

}

Widget::~Widget()
{
    delete ui;
}


void Widget::addUserManager(UserManager* uManager){
    this->uManager = uManager;
}


void Widget::on_send_clicked(){

    QString username = ui->login->text();
    QString pass = ui->pass->text();


    if(uManager->login(username.toStdString(),pass.toStdString())){

        User *user = uManager->getUser(username.toStdString());
        QString msgLogin = "Bem vindo, " + QString::fromStdString(user->getName());

        box = new QMessageBox(this);
        box->setWindowTitle("Login");
        box->setText(msgLogin);
        box->setIcon(QMessageBox::Information);
        box->exec();
        delete box;

        if(ui->checkBox->checkState() != 2){
            ui->login->clear();
            ui->pass->clear();
        }

        hide();
        g = new Grupos(user, uManager, this);
        g->show();
    }
    else{
        box = new QMessageBox(this);
        box->setWindowTitle("Login");
        box->setText("Login malsucedido, tente de novo por favor!");
        box->setIcon(QMessageBox::Warning);
        box->exec();
        delete box;
    }
}

void Widget::on_pushButton_2_clicked()
{
    int resp = QMessageBox::warning(this, "Sair", "Deseja sair do programa?",
                           QMessageBox::Ok, QMessageBox::Cancel);
    if(resp == QMessageBox::Ok)
        qApp->quit();
}

void Widget::on_account_clicked()
{

    if(ui->checkBox->checkState() != 2){
        ui->login->clear();
        ui->pass->clear();
    }
    hide();
    c = new Cadastro(this);
    c->addUserManager(uManager);
    c->show();

}
