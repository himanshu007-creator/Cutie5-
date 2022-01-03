#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString Donegoals;
    QObjectList goals = this->children();
    qDebug() <<this->children();
    foreach (QObject* obj, goals) {
        if(obj->inherits("QCheckBox"))
        {
         QCheckBox* goal = qobject_cast<QCheckBox*>(obj);
         if(goal && goal->isChecked()) Donegoals += goal->text() + "\r\n";
        }
    }
    qDebug() <<"goals: "<<Donegoals;
    QMessageBox::information(this,"Goals","Accomplished:- \n"+Donegoals);
    accept();
}
