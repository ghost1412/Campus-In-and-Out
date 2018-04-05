#ifndef ADMIN_H
#define ADMIN_H

#include <QWidget>

namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = 0);
    ~Admin();
    void start(QString);
    void logout();
private slots:
    void on_newUser_clicked();

    void on_addUser_clicked();
    void addNewUser(QString, QString, QString);
    void on_removeUser_clicked();
    void on_deleteUser_clicked();
    void on_logout_clicked();
    void changeUserPass(QString, QString);
    void on_home_clicked();
    void on_home_2_clicked();
    void on_goTochangePass_clicked();

    void on_changepass_clicked();

    void on_home_3_clicked();

private:
    Ui::Admin *ui;
    QString currentUser;
    void removeUser(QString);
};

#endif // ADMIN_H
