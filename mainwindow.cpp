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

}

MainWindow::~MainWindow()
{

}
