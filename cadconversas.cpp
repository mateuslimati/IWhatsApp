#include "cadconversas.h"
#include "ui_cadconversas.h"
#include "icons.h"

#include "conversas.h"

#include <iostream>
using namespace std;

CadConversas::CadConversas(UserManager *uManager, User* user, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadConversas)
{
    this->uManager = uManager;
    this->user = user;
    ui->setupUi(this);
    setWindowTitle("Cadastro de Usuários");

    QPixmap send(sendIcon);
    QPixmap quit(backIcon);
    QPixmap clean(cleanIcon);

    ui->back->setIcon(quit.scaled(81,70, Qt::KeepAspectRatio));
    ui->send->setIcon(send.scaled(81,41, Qt::KeepAspectRatio));
    ui->clean->setIcon(clean.scaled(81,41, Qt::KeepAspectRatio));

}

CadConversas::~CadConversas()
{
    delete ui;
}

void CadConversas::on_back_clicked()
{
    QWidget *p = parentWidget();
    hide();
    p->show();
}

void CadConversas::on_clean_clicked()
{
    ui->gName->clear();
    ui->pName->clear();
}

void CadConversas::on_send_clicked()
{

    if((ui->pName->text() == "")&&(ui->gName->text() == "")&&
            (ui->icon->text() == "")){
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Cadastro malsucedido");
        box->setText("Existem campos vazios, tente de novo por favor!");
        box->setIcon(QMessageBox::Warning);
        box->exec();
        delete box;
    }
    else if(!(uManager->searchUser(ui->pName->text().toStdString()))){
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Cadastro malsucedido");
        box->setText("Usuário não encontrado, tente de novo por favor!");
        box->setIcon(QMessageBox::Warning);
        box->exec();
        delete box;
    }
    else{
        std::string icon = "/home/robertcabral/Documents/icons/" +
                ui->icon->text().toStdString();
        Conversas *conversa = new Conversas(ui->gName->text().toStdString(),
                                             icon);

        std::string name = ui->pName->text().toStdString();
        User *u = uManager->getUser(name);

        user->addConversa(conversa);
        u->addConversa(conversa);

        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Conversa cadastrada");
        box->setText("Conversa cadastrada com sucesso!");
        box->setIcon(QMessageBox::Information);
        box->exec();
        delete box;

        ui->gName->clear();
        ui->pName->clear();

        Message message(conversa->getLabel(), conversa->getIcon());
        emit updateItens(message);

        QWidget *p = parentWidget();
        hide();
        p->show();

    }
}
