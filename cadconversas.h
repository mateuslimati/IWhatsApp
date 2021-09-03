#ifndef CADCONVERSAS_H
#define CADCONVERSAS_H

#include <QDialog>
#include <QMessageBox>

#include "usermanager.h"
#include "user.h"
#include "conversas.h"
#include "message.h"

namespace Ui {
class CadConversas;
}

class CadConversas : public QDialog
{
    Q_OBJECT
    UserManager *uManager;
    User *user;

public:
    explicit CadConversas(UserManager *uManager, User* user, QWidget *parent = 0);
    ~CadConversas();

private slots:
    void on_back_clicked();

    void on_clean_clicked();

    void on_send_clicked();

signals:
    void updateItens(Message& message);

private:
    Ui::CadConversas *ui;
};

#endif // CADCONVERSAS_H
