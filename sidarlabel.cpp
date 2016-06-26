#include "sidarlabel.h"
#include "sidartestpaint.h"

#include <QPainter>

SidarLabel::SidarLabel(SidarPaintInterface *paint, QWidget *parent)
    : QLabel(parent), p_paint(paint)
{
    // this is experimental!
    setStyleSheet("border:solid;border-width:2px;");

}

SidarLabel::SidarLabel(const QString &text, QWidget *parent)
    : QLabel(parent)
{
    setText(text);
}


SidarLabel::~SidarLabel()
{

}


/** set a new Sidar paint interface, and delete or overwrite the old one
 * @brief SidarLabel::setSidarPainter
 * @param paint
 * @param deleteme - if we need to delete the ref to the painting class
 * ex. when you call it that way:
 *  setSidarPainger(new ImplementationOfPaintInterface());
 *  setSidarPainger(new Impl2OfPntIface(), true); // this will delete the previous
 *  in short, if you plan to use non referenced constructions alwyas use true
 *  if you have instancies of the painter interfaces and you are using only an
 *  aggregation use it without a param or default (false)
 */
void SidarLabel::setSidarPainter(SidarPaintInterface *paint, bool deleteme)
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
 * @brief SidarLabel::mousePressEvent
 * @param event
 */
void SidarLabel::mousePressEvent(QMouseEvent *event)
{
    (void)event;
    emit mousePressed();
}

/** emit when  mouse releases
 * @brief SidarLabel::mouseReleaseEvent
 * @param event
 */
void SidarLabel::mouseReleaseEvent(QMouseEvent *event)
{
    (void)event;
    emit mouseReleased();
}

/** this will paint with the custom overriden class
 * @brief SidarLabel::paintEvent
 * @param ev
 */
void SidarLabel::paintEvent(QPaintEvent *ev)
{
    (void)ev;
    p_paint->SidarPaint(*this);
    update();
}

// TODO: handle the resize of the label
void SidarLabel::resizeEvent(QResizeEvent *ev)
{
    (void)ev;
    // call paint class spcific here
}


void SidarLabel::handleMousePressed(const QWidget *caller)
{
    (void)caller;
    // we can add handler if we want to change something private on click
    // like if we want to make our custom button
}


void SidarLabel::handleMouseRelease(const QWidget *caller)
{
    (void)caller;
}


