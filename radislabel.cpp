#include "radislabel.h"

#include <QPainter>

RadisLabel::RadisLabel(RadisPaintInterface *paint, QWidget *parent)
    : QLabel(parent), p_paint(paint)
{

}

RadisLabel::RadisLabel(const QString &text, QWidget *parent)
    : QLabel(parent)
{
    setText(text);
}


RadisLabel::~RadisLabel()
{

}


void RadisLabel::mousePressEvent(QMouseEvent *event)
{
    (void)event;
    emit mousePressed();
}


void RadisLabel::mouseReleaseEvent(QMouseEvent *event)
{
    (void)event;
    emit mouseReleased();
}

void RadisLabel::paintEvent(QPaintEvent *ev)
{
    (void)ev;
    p_paint->radisPaint(*this);
//    update();
}


void RadisLabel::handleMousePressed(const QWidget *caller)
{
    (void)caller;
}


void RadisLabel::handleMouseRelease(const QWidget *caller)
{
    (void)caller;
}


