#include "cadastro.h"
#include "ui_cadastro.h"
#include "icons.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>

Cadastro::Cadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cadastro)
{
    ui->setupUi(this);
    setWindowTitle("Cadastro de usuários");

    QPixmap send(sendIcon);
    QPixmap quit(backIcon);
    QPixmap clean(cleanIcon);

    QIcon Button(send);
    QIcon Button2(quit);
    QIcon Button3(clean);

    ui->back->setIcon(quit.scaled(81,70, Qt::KeepAspectRatio));
    ui->send->setIcon(send.scaled(81,41, Qt::KeepAspectRatio));
    ui->clean->setIcon(clean.scaled(81,41, Qt::KeepAspectRatio));

}

Cadastro::~Cadastro()
{
    delete ui;
}

void Cadastro::addUserManager(UserManager* uManager){
    this->uManager = uManager;
}


void Cadastro::on_back_clicked()
{
    QWidget *p = parentWidget();
    hide();
    p->show();
}

void Cadastro::on_clean_clicked()
{
    ui->name->clear();
    ui->username->clear();
    ui->pass1->clear();
    ui->pass2->clear();

}

void Cadastro::on_send_clicked()
{
    User *user = new User;
    user->setName(ui->name->text().toStdString());
    user->setUsername(ui->username->text().toStdString());
    user->setPass(ui->pass1->text().toStdString());

    if((ui->name->text() == "")&&(ui->username->text() == "")&&
            (ui->pass1->text() == "")&&(ui->pass2->text() == "")){
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Cadastro malsucedido");
        box->setText("Existem campos vazios, tente de novo por favor!");
        box->setIcon(QMessageBox::Warning);
        box->exec();
        delete box;
    }
    else if(ui->pass1->text() != ui->pass2->text()){
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Cadastro malsucedido");
        box->setText("As senhas não coincidem, tente de novo por favor!");
        box->setIcon(QMessageBox::Warning);
        box->exec();
        delete box;
    }
    else if(!uManager->addUser(user)){
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Cadastro malsucedido");
        box->setText("Esse usuário já existe, tente de novo por favor!");
        box->setIcon(QMessageBox::Warning);
        box->exec();
        delete box;
    }
    else{
        QMessageBox *box = new QMessageBox(this);
        box->setWindowTitle("Cadastrado de usuário");
        box->setText("Usuário cadastrado com sucesso!");
        box->setIcon(QMessageBox::Information);
        box->exec();
        delete box;

        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        try {

            driver = get_driver_instance();
            con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
            con->setSchema("iwhatsapp");

            stmt = con->createStatement();
            stmt->execute("insert into users(nome,username,password) "
                          "values(\""+user->getName()+"\",\""+user->getUsername()+"\",\""+ui->pass1->text().toStdString()+"\");");

            delete stmt;
            delete con;

        } catch (sql::SQLException &e) {
            std::cout << "Erro" << std::endl;
        }

        ui->name->clear();
        ui->username->clear();
        ui->pass1->clear();
        ui->pass2->clear();

        QWidget *p = parentWidget();
        hide();
        p->show();

    }
}
