#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "radislabel.h"
#include <QWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    RadisLabel* m_label;
};

#endif // MAINWINDOW_H
