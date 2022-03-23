#include "bigwindow.h"
#include "./ui_bigwindow.h"

#include "iostream"
#include "string"
using namespace std;
BigWindow::BigWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BigWindow)
{
    ui->setupUi(this);


}

BigWindow::~BigWindow()
{
    delete ui;
}


void BigWindow::on_pushButton_clicked()
{
    //char new_username = '7';
    //SetGet* singolton = SetGet::Instance();
    //cout <<singolton->get_char();
}

