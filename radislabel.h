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

    void paintEvent(QPaintEvent *ev);

private:
    RadisPaintInterface* p_paint;

};


#endif // RADISLABEL_H
