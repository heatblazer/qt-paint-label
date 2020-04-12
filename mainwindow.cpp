#include "mainwindow.h"
#include "sidartestpaint.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <QWidget>


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    m_labels[0] = new SidarLabel(new SidarTestPaint(), this);
    m_labels[0]->setText("madafaka");
    m_labels[0]->setMinimumSize(QSize(240,200));

    m_labels[1] = new SidarLabel(new SidarHTMLRender(), this);
    m_labels[1]->setText("madafaka");
    m_labels[1]->setMinimumSize(QSize(240,200));

    m_labels[2] = new SidarLabel(new SidarTestPaint1(), this);
    m_labels[2]->setText("madafaka");
    m_labels[2]->setMinimumSize(QSize(240,200));

    m_labels[3] = new SidarLabel(new SidarAnimation(), this);
    m_labels[3]->setText("madafaka");
    m_labels[3]->setMinimumSize(QSize(240,200));

    m_labels[4] = new SidarLabel(new SidarTestPaint3(), this);
    m_labels[4]->setText("madafaka");
    m_labels[4]->setMinimumSize(QSize(240,200));

    m_labels[5] = new SidarLabel(new SidarTestPaintQuad(), this);
    m_labels[5]->setText("quadtree");
    m_labels[5]->setMinimumSize(QSize(240,200));


#if 0
    tests[0] = new SidarTestPaint();
    tests[1] = new SidarTestPaint1();
    tests[2] = new SidarTestPaint2();
    tests[3] = new SidarTestPaint3();
    tests[4] = new SidarHTMLRender();
#endif

    m_layout.addWidget(m_labels[0]);
    m_layout.addWidget(m_labels[1]);
    m_layout.addWidget(m_labels[2]);
    m_layout.addWidget(m_labels[3]);
    m_layout.addWidget(m_labels[4]);
    m_layout.addWidget(m_labels[5]);

    m_layout.setAlignment(this, Qt::AlignCenter);

 //   m_timer.setInterval(2000);
 //   connect(&m_timer, SIGNAL(timeout()),
 //           this, SLOT(showAllPaints()));
 //   m_timer.start();

    connect(m_labels[0], SIGNAL(mousePressed()),
            this, SLOT(handleSomeClicks()));
    connect(m_labels[1], SIGNAL(mousePressed()),
            this, SLOT(handleSomeClicks()));
    connect(m_labels[2], SIGNAL(mousePressed()),
            this, SLOT(handleSomeClicks()));
    connect(m_labels[3], SIGNAL(mousePressed()),
            this, SLOT(handleSomeClicks()));
    connect(m_labels[4], SIGNAL(mousePressed()),
            this, SLOT(handleSomeClicks()));



    this->setLayout(&m_layout);

}

MainWindow::~MainWindow()
{

}



void MainWindow::generateRandomPaint()
{

    // demonstrates random setting of a  painting class with no deletion!
    //m_label->setsidarPainter(tests[qrand()%3], false);
}

void MainWindow::showAllPaints()
{
    static int ind = 0;
    //m_label->setsidarPainter(tests[ind%5]);
    ind++;
}

void MainWindow::handleSomeClicks()
{
    std::cout << "Click handler!!!" << std::endl;
}
