#include "adduser.h"
#include "ui_adduser.h"
#include "icons.h"

#include "QMessageBox"

AddUser::AddUser(UserManager* uManager, Conversas* conversa, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    this->uManager = uManager;
    this->conversa = conversa;
    ui->setupUi(this);

    QPixmap send(sendIcon);
    QPixmap quit(backIcon);
    QPixmap clean(cleanIcon);

    ui->back->setIcon(quit.scaled(81,70, Qt::KeepAspectRatio));
    ui->send->setIcon(send.scaled(81,41, Qt::KeepAspectRatio));
    ui->clean->setIcon(clean.scaled(81,41, Qt::KeepAspectRatio));
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::on_back_clicked()
{
    QWidget *p = parentWidget();
    hide();
    p->show();
}


void AddUser::on_clean_clicked()
{
    ui->pName->clear();
}


void AddUser::on_send_clicked()
{
    if(!(uManager->searchUser(ui->pName->text().toStdString()))){
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Cadastro malsucedido");
        box->setText("Usuário não encontrado, tente de novo por favor!");
        box->setIcon(QMessageBox::Warning);
        box->exec();
        delete box;
    }
    else{

        std::string name = ui->pName->text().toStdString();
        User *u = uManager->getUser(name);

        u->addConversa(conversa);

        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Adicionar usuário");
        box->setText("Usuário adicionado com sucesso!");
        box->setIcon(QMessageBox::Information);
        box->exec();
        delete box;

        ui->pName->clear();

        QWidget *p = parentWidget();
        hide();
        p->show();

    }

}
