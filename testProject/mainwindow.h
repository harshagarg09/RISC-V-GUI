#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QPainter>
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
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int count=0;
    QVector<QStringList> ins;
};
#endif // MAINWINDOW_H
