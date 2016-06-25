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
    void showAllPaints(void);

private:
    RadisLabel* m_label;
    QTimer     m_timer;
    //
    RadisPaintInterface* tests[4];
};

#endif // MAINWINDOW_H
