#ifndef RADISLABEL_H
#define RADISLABEL_H
#include "radispaintinterface.h"

#include <QLabel>


// derived class to extend the functionality to be a clickable
class RadisPaintInterface;

class RadisLabel : public QLabel
{
    Q_OBJECT
public:
    explicit RadisLabel(QWidget* parent=0);
    explicit RadisLabel(RadisPaintInterface* paint, QWidget* parent=0);
    explicit RadisLabel(const QString& text="", QWidget* parent=0);
    virtual ~RadisLabel(); // we may derive better labesl

    void setRadisPainter(RadisPaintInterface* paint, bool deleteme=false);

signals:
    // for now leave the double click
    //void mouse2xClicked();
    void mouseReleased();
    void mousePressed();

public slots:
    virtual void handleMousePressed(const QWidget* caller);
    virtual void handleMouseRelease(const QWidget* caller);

protected:
    // don`t remiplement mouse 2x click
    //void mouseDoubleClickEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    // this is the method to override
    void paintEvent(QPaintEvent *ev);

    // this will handle the resizes if needed
    // add an abstract function to the interface to handle the resize changes
    void resizeEvent(QResizeEvent *ev);

private:
    // this is the paint interface
    // easier to derive different paint classes then just pass them to the
    // painter
    RadisPaintInterface* p_paint;

};


#endif // RADISLABEL_H
