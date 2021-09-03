#ifndef GRUPOS_H
#define GRUPOS_H

#include <QDialog>
#include "user.h"
#include "vector"

#include "usermanager.h"
#include "conversa.h"
#include "cadconversas.h"
#include "message.h"

namespace Ui {
class Grupos;
}

class Grupos : public QDialog
{
    Q_OBJECT
    User *user;
    Conversa *g;
    UserManager *uManager;
    CadConversas *addConversas;

public:
    explicit Grupos(User* user, UserManager *uManager, QWidget *parent = 0);
    ~Grupos();
    void setUser(User* user);
    void addItem(std::string gName, std::string icon);

private slots:
    void on_pushButton_clicked();

    void passTime();

    void updateGroups(int a);

    void on_listWidget_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void update(Message &);

    void on_refresh_clicked();

private:
    Ui::Grupos *ui;
};

#endif // GRUPOS_H
