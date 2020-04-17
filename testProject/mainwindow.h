#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QFile>
#include<QTextStream>
#include <QMainWindow>
#include<QVector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    int count;
    QVector<QStringList> ins;
};
#endif // MAINWINDOW_H
