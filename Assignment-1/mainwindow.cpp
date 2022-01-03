#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSubmit_clicked()
{
    QMessageBox::information(this,"Name","Kiddan "+ui->lineEdit->text());
    qDebug() <<"CLICKED!";
    qDebug() << this->close();
}
