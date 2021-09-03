#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

#include "grupos.h"
#include "usermanager.h"
#include "cadastro.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
private:
    Q_OBJECT
    UserManager *uManager;
    QMessageBox *box;
    Ui::Widget *ui;
    Grupos *g;
    Cadastro *c;

public:    
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void addUserManager(UserManager* uManager);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_send_clicked();

    void on_account_clicked();
};

#endif // WIDGET_H
