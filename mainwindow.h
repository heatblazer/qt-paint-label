#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sidarlabel.h"
#include <QWidget>
#include <QHBoxLayout>
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
    SidarLabel* m_labels[6];
    QTimer     m_timer;
    //
    QHBoxLayout m_layout;
    SidarPaintInterface* tests[5];
};

#endif // MAINWINDOW_H
