#ifndef ADDUSER_H
#define ADDUSER_H

#include "usermanager.h"
#include "conversas.h"

#include <QDialog>

namespace Ui {
class AddUser;
}

class AddUser : public QDialog
{
    Q_OBJECT
    UserManager* uManager;
    Conversas* conversa;

public:
    explicit AddUser(UserManager* uManager, Conversas* conversa, QWidget *parent = 0);
    ~AddUser();

private slots:
    void on_back_clicked();

    void on_clean_clicked();

    void on_send_clicked();

private:
    Ui::AddUser *ui;
};

#endif // ADDUSER_H
