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
            this, SLOT(showAllPaints()));
    m_timer.start();

}

MainWindow::~MainWindow()
{

}



void MainWindow::generateRandomPaint()
{

    // demonstrates random setting of a  painting class with no deletion!
    m_label->setRadisPainter(tests[qrand()%3], false);
}

void MainWindow::showAllPaints()
{
    static int ind = 0;
    m_label->setRadisPainter(tests[ind%3]);
    ind++;
}
