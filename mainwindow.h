#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "radislabel.h"
#include <QWidget>
#include <QTimer>

class RadisPaintInterface;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void generateRandomPaint(void);

private:
    RadisLabel* m_label;
    QTimer     m_timer;
    //
    RadisPaintInterface* tests[3];
};

#endif // MAINWINDOW_H
