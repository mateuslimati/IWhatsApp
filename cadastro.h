#ifndef CADASTRO_H
#define CADASTRO_H

#include <QDialog>
#include <QMessageBox>

#include "usermanager.h"

namespace Ui {
class Cadastro;
}

class Cadastro : public QDialog
{
    Q_OBJECT
    UserManager *uManager;

public:
    explicit Cadastro(QWidget *parent = 0);
    ~Cadastro();
    void addUserManager(UserManager* uManager);

private slots:
    void on_back_clicked();

    void on_clean_clicked();

    void on_send_clicked();

private:
    Ui::Cadastro *ui;
};

#endif // CADASTRO_H
