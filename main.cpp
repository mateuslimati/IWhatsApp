#include "widget.h"
#include <QApplication>
#include <fstream>

#include "user.h"
#include "usermanager.h"
#include "conversas.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>

int main(int argc, char *argv[]){

    UserManager users;

    QApplication a(argc, argv);
    Widget w;
    Widget g;

    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;
    std::string username,name,pass;

    try {

      /* Create a connection */
      driver = get_driver_instance();
      con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
      /* Connect to the MySQL test database */
      con->setSchema("iwhatsapp");

      stmt = con->createStatement();
      res = stmt->executeQuery("SELECT * FROM users"); // replace with your statement
      while (res->next()) {
        name = res->getString("nome");
        username =  res->getString("username");
        pass = res->getString("password");

        User* user = new User(username);
        user->setName(name);
        user->setPass(pass);
        users.addUser(user);

        std::cout << "Usuario cadastrado" << std::endl;

      }
      delete res;
      delete stmt;
      delete con;

    } catch (sql::SQLException &e) {
        std::cout << "Erro" << std::endl;
    }

    std::map<std::string,User*> usuarios;
    usuarios = users.getUsers();

    for(auto a : usuarios){
        std::cout << a.first << std::endl;
        Conversas * c = new Conversas(a.second->getName(),"");
        for(auto b : usuarios)
            if(b.second != a.second)
                b.second->addConversa(c);
    }


    w.addUserManager(&users);
    g.addUserManager(&users);
    w.show();
    g.show();

    return a.exec();
}
