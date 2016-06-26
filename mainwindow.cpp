#include "mainwindow.h"
#include "radistestpaint.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <QWidget>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    m_label = new RadisLabel(new RadisTestPaint(), this);
    m_label->setText("madafaka");
    m_label->setMinimumSize(QSize(240,200));

    tests[0] = new RadisTestPaint();
    tests[1] = new RadisTestPaint1();
    tests[2] = new RadisTestPaint2();
    tests[3] = new RadisTestPaint3();
    tests[4] = new RadisHTMLRender();

    m_timer.setInterval(2000);
    connect(&m_timer, SIGNAL(timeout()),
            this, SLOT(showAllPaints()));
    m_timer.start();

    connect(m_label, SIGNAL(mousePressed()),
            this, SLOT(handleSomeClicks()));

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
    m_label->setRadisPainter(tests[ind%5]);
    ind++;
}

void MainWindow::handleSomeClicks()
{
    std::cout << "Click handler!!!" << std::endl;
}
