#include "radislabel.h"
#include "radistestpaint.h"

#include <QPainter>

RadisLabel::RadisLabel(RadisPaintInterface *paint, QWidget *parent)
    : QLabel(parent), p_paint(paint)
{
    // this is experimental!
    connect(this, SIGNAL(mousePressed()),
            this, SLOT(handleMousePressed()));

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
    if (p_paint != 0) {
        delete p_paint;
        p_paint = paint;
    } else {
        p_paint = paint;
    }
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


void RadisLabel::handleMousePressed()
{
    // this is a test change
    this->setRadisPainter(new RadisTestPaint2());
    update();
}


void RadisLabel::handleMouseRelease(const QWidget *caller)
{
    (void)caller;
}


