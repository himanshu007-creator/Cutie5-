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
    QString sabzi = getOption(ui->Sabzi);
    QString roti = getOption(ui->Roti);
    QString peena = getOption(ui->Peena);
    QString meetha = getOption(ui->Meetha);
    QString order = "Sabzi : "+sabzi+"\r\n"+"Roti : "+roti+"\r\n"+"Beverages : "+peena+"\r\n"+"Meetha : "+meetha+"\r\n";
    QMessageBox::information(this,"Order","Things you ordered: ",order);

    accept();
}

void Dialog::on_pushButton_2_clicked()
{
    QMessageBox::critical(this,"Chetawani","Kuch samay t guzariye sath me, Fatke ajayegi hath me :)");
}

QString Dialog::getOption(QObject *obj)
{
    QString value = "None";
    QList<QRadioButton*> lst = obj->findChildren<QRadioButton*>(QString(),Qt::FindDirectChildrenOnly);
    foreach (QRadioButton *rdo, lst) {
        if(rdo->isChecked()){
            value = rdo->text();
            break;
        }
        return value;
    }

}
