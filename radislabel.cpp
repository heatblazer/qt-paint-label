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


/** set a new radis paint interface, and delete or overwrite the old one
 * @brief RadisLabel::setRadisPainter
 * @param paint
 * @param deleteme - if we need to delete the ref to the painting class
 * ex. when you call it that way:
 *  setRadisPainger(new ImplementationOfPaintInterface());
 *  setRadisPainger(new Impl2OfPntIface(), true); // this will delete the previous
 *  in short, if you plan to use non referenced constructions alwyas use true
 *  if you have instancies of the painter interfaces and you are using only an
 *  aggregation use it without a param or default (false)
 */
void RadisLabel::setRadisPainter(RadisPaintInterface *paint, bool deleteme)
{

    if (deleteme) {
        if (p_paint != 0) {
            delete p_paint;
            p_paint = paint;
        } else {
            p_paint = paint;
        }
    } else {
        p_paint = paint;
    }
}


/** emit when  mouse press
 * @brief RadisLabel::mousePressEvent
 * @param event
 */
void RadisLabel::mousePressEvent(QMouseEvent *event)
{
    (void)event;
    emit mousePressed();
}

/** emit when  mouse releases
 * @brief RadisLabel::mouseReleaseEvent
 * @param event
 */
void RadisLabel::mouseReleaseEvent(QMouseEvent *event)
{
    (void)event;
    emit mouseReleased();
}

/** this will paint with the custom overriden class
 * @brief RadisLabel::paintEvent
 * @param ev
 */
void RadisLabel::paintEvent(QPaintEvent *ev)
{
    (void)ev;
    p_paint->radisPaint(*this);
    update();
}


void RadisLabel::handleMousePressed(const QWidget *caller)
{
    (void)caller;
}


void RadisLabel::handleMouseRelease(const QWidget *caller)
{
    (void)caller;
}


