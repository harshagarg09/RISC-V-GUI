#ifndef DIALOG_H
#define DIALOG_H
#include"RegistryFile.h"

#include <QDialog>
#include <QPainter>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Registry_File rFile;
    int i=0;

};

#endif // DIALOG_H
