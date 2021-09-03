#include "grupos.h"
#include "ui_grupos.h"
#include "icons.h"

#include <QTimer>
#include <QDateTime>
#include <iostream>
using namespace std;

#include <QPixmap>

Grupos::Grupos(User* user, UserManager *uManager, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grupos)
{
    this->user = user;
    this->uManager = uManager;
    ui->setupUi(this);

    setWindowTitle("Conversas");

    std::vector<Conversas*> conversas = user->getConversas();

    for(auto conversa: conversas){
        QListWidgetItem *item = new QListWidgetItem(QIcon(QString::fromStdString(conversa->getIcon())), QString::fromStdString(conversa->getLabel()));
        ui->listWidget->addItem(item);
    }

    QPixmap qt(backIcon);
    QIcon Button(qt);
    ui->pushButton->setIcon(qt.scaled(81,80, Qt::KeepAspectRatio));

    QPixmap pix(chatIcon);
    QIcon Button2(pix);
    ui->pushButton_2->setIcon(pix.scaled(81,80, Qt::KeepAspectRatio));


}

void Grupos::passTime(){
    cout << "pass Time" << endl;
}

void Grupos::addItem(std::string gName, std::string icon){

    QListWidgetItem *item = new QListWidgetItem(QIcon(QString::fromStdString(icon)), QString::fromStdString(gName));
    ui->listWidget->addItem(item);
}

void Grupos::setUser(User* user){
    this->user = user;
}


void Grupos::update(Message &message){
    QListWidgetItem *item = new QListWidgetItem(QIcon(QString::fromStdString(message.getIcon())), QString::fromStdString(message.getLabel()));
    ui->listWidget->addItem(item);
}

Grupos::~Grupos()
{
    delete ui;
}

void Grupos::on_pushButton_clicked()
{
    QWidget *p = parentWidget();
    hide();
    p->show();
}

void Grupos::on_listWidget_clicked(const QModelIndex &index){

    std::vector<Conversas*> conversas = user->getConversas();
    if(index.row() < conversas.size()){
        Conversas *conversa = conversas[index.row()];
        hide();
        g = new Conversa(user,uManager, conversa, this);
        g->show();

    }
}

void Grupos::on_pushButton_2_clicked()
{
    hide();
    addConversas = new CadConversas(uManager, user, this);
    connect(addConversas, &CadConversas::updateItens, this, &Grupos::update);
    addConversas->show();
}

void Grupos::on_refresh_clicked()
{
    ui->listWidget->clear();
    std::vector<Conversas*> conversas = user->getConversas();

    for(auto conversa: conversas){
        QListWidgetItem *item = new QListWidgetItem(QIcon(QString::fromStdString(conversa->getIcon())), QString::fromStdString(conversa->getLabel()));
        ui->listWidget->addItem(item);
    }
}
