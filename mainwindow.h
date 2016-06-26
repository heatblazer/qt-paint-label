#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sidarlabel.h"
#include <QWidget>
#include <QTimer>

class SidarPaintInterface;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void generateRandomPaint(void);
    void showAllPaints(void);

    void handleSomeClicks(void);
private:
    SidarLabel* m_label;
    QTimer     m_timer;
    //
    SidarPaintInterface* tests[5];
};

#endif // MAINWINDOW_H
