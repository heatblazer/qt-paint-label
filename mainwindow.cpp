#include "mainwindow.h"
#include "radistestpaint.h"
#include "ui_mainwindow.h"

#include <QWidget>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    m_label = new RadisLabel(new RadisTestPaint(), this);
    m_label->setText("madafaka");
    m_label->setMinimumSize(QSize(320,240));

    tests[0] = new RadisTestPaint();
    tests[1] = new RadisTestPaint1();
    tests[2] = new RadisTestPaint2();

    m_timer.setInterval(1000);
    connect(&m_timer, SIGNAL(timeout()),
            this, SLOT(generateRandomPaint()));
    m_timer.start();

}

MainWindow::~MainWindow()
{

}

void MainWindow::generateRandomPaint()
{
    m_label->setRadisPainter(tests[qrand()%3]);
}
