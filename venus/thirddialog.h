#ifndef THIRDDIALOG_H
#define THIRDDIALOG_H

#include <QDialog>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string.h>
#include<bitset>
#include"ALU.h"
#include"IAG.h"
#include"Decode.h"
#include"Fetch.h"
#include"MUX_Y.h"
#include"RegistryFile.h"
#include"RegUpdate.h"
#include"MemoryAccess.h"
#include"InterStateBuffers.h"
#include<string>
#include<QFile>
#include<QTextStream>
#include <QMainWindow>
#include <QPainter>

namespace Ui {
class thirdDialog;
}

class thirdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit thirdDialog(QWidget *parent = nullptr);
    ~thirdDialog();
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();
    void updateISB(InterStateBuffers &isb);
    void updateAfterDecoder(InterStateBuffers &isb);
    void updateIfStall(InterStateBuffers &isb);
    void memory(InterStateBuffers &isb,MemoryAccess &memAccess ,MUX_Y &muxy);
    void writeBack(InterStateBuffers &isb, RegUpdate &regUpdate, Registry_File &rFile);
    void printOnTextEdit();
    void print(int i, InterStateBuffers &isb, Registry_File &rFile);
    void printSummary(InterStateBuffers &isb);

private:
    Ui::thirdDialog *ui;
    QPaintEvent *event;
    int count;
    int i=0,j=0;
    bool end=false;
    InterStateBuffers isb;
    Registry_File rFile;
    Fetch fetch;
    MUX_Y muxy;
    Decode decode;
    RegUpdate regUpdate;
    MemoryAccess *memAccess;
    ALU alu;
    IAG iag;
    QVector<QStringList>ins;
};

#endif // THIRDDIALOG_H
