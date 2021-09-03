#include "conversa.h"
#include "ui_conversa.h"
#include "icons.h"
#include <QScrollBar>

Conversa::Conversa(User* user, UserManager *uManager, Conversas *conversa, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Conversa)
{
    this->conversa = conversa;
    this->user = user;
    this->uManager = uManager;

    ui->setupUi(this);
    QString title = QString::fromStdString(conversa->getLabel()) + " - " +
            QString::fromStdString(user->getName());
    setWindowTitle(title);

    QPixmap qt(backIcon);
    QIcon Button(qt);
    ui->back->setIcon(qt.scaled(81,80, Qt::KeepAspectRatio));

    QPixmap pix(sendIcon);
    QIcon Button2(pix);
    ui->send->setIcon(pix.scaled(81,80, Qt::KeepAspectRatio));

    QPixmap add(addIcon);
    QIcon Button3(add);
    ui->addUser->setIcon(add.scaled(81,80, Qt::KeepAspectRatio));

    std::vector<std::string> msg = conversa->getMsg();

    for(auto m: msg){
        QString mOld = QString::fromStdString(m);
        mCurrent = mCurrent + mOld;
    }
    ui->display->setText(mCurrent);
    ui->display->verticalScrollBar()->setValue(ui->display->verticalScrollBar()->maximum());


}

void Conversa::refreshMsg(){

}

Conversa::~Conversa()
{
    delete ui;
}

void Conversa::on_send_clicked(){

    QString msg = "";
    if(ui->text->toPlainText() != "")
        msg = QString::fromStdString(user->getName())
                + ":\n" + ui->text->toPlainText() +"\n";

    mCurrent = mCurrent + msg;
    conversa->addMsg(msg.toStdString());

    ui->display->setText(mCurrent);
    ui->display->verticalScrollBar()->setValue(ui->display->verticalScrollBar()->maximum());
    ui->text->setText("");

}

void Conversa::on_back_clicked()
{
    QWidget *p = parentWidget();
    p->setDisabled(true);
    p->setEnabled(true);
    hide();
    p->show();
}

void Conversa::on_display_destroyed()
{

}

void Conversa::on_addUser_clicked()
{
    hide();
    addUser = new AddUser(uManager, conversa, this);
    addUser->show();
}
