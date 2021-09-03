#ifndef CONVERSA_H
#define CONVERSA_H

#include "conversas.h"
#include "usermanager.h"
#include "adduser.h"

#include <QDialog>

namespace Ui {
class Conversa;
}

class Conversa : public QDialog
{
    Q_OBJECT
    Conversas *conversa;
    User* user;
    UserManager *uManager;
    AddUser *addUser;
    QString mCurrent = "";

public:
    explicit Conversa(User* user, UserManager *uManager, Conversas *conversa, QWidget *parent = 0);
    ~Conversa();

private slots:
    void on_send_clicked();

    void on_back_clicked();

    void on_display_destroyed();

    void on_addUser_clicked();

    void refreshMsg();

private:
    Ui::Conversa *ui;
};

#endif // CONVERSA_H
