#include "radislabel.h"
#include "radistestpaint.h"

#include <QPainter>

RadisLabel::RadisLabel(RadisPaintInterface *paint, QWidget *parent)
    : QLabel(parent), p_paint(paint)
{
    // this is experimental!

}

RadisLabel::RadisLabel(const QString &text, QWidget *parent)
    : QLabel(parent)
{
    setText(text);
}


RadisLabel::~RadisLabel()
{

}

void RadisLabel::setRadisPainter(RadisPaintInterface *paint)
{
    // delete the class created without a handler
#if 0
    if (p_paint != 0) {
        delete p_paint;
        p_paint = paint;
    } else {
        p_paint = paint;
    }
#endif
    p_paint = paint;
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
    update();
}


void RadisLabel::handleMousePressed()
{

}


void RadisLabel::handleMouseRelease(const QWidget *caller)
{
    (void)caller;
}


