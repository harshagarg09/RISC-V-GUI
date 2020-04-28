#ifndef SECWINDOW_H
#define SECWINDOW_H

#include <QMainWindow>

namespace Ui {
class secWindow;
}

class secWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit secWindow(QWidget *parent = nullptr);
    ~secWindow();

private:
    Ui::secWindow *ui;
};

#endif // SECWINDOW_H
