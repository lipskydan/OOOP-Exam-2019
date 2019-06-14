#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sl.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAddElement_clicked();

private:
    Ui::MainWindow *ui;
    DoubleList list;

 public:
//    void listprint(SL *lst);
};

#endif // MAINWINDOW_H
