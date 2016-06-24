#include "radistestpaint.h"

#include <radislabel.h>
#include <QPainter>

RadisTestPaint::RadisTestPaint()
{

}


RadisTestPaint::~RadisTestPaint()
{

}

void RadisTestPaint::radisPaint(const RadisLabel &pradis)
{
    QPen penline(QColor(255, 0, 0));
    QPen pentext(QColor(0, 0, 255));

    QPainter pnt((QPaintDevice*)&pradis);
    pnt.setPen(penline);
    QString s("LINE 2");
    QFont fnt(pradis.font());
    QFontMetrics fm(fnt);
    int pixW = fm.width(s);
    int pixH = fm.height();
    pnt.save();
    pnt.drawLine(QLine(0, 160, 160, 160));
    pnt.setPen(pentext);
    pnt.drawText(160, 165, s);
    pnt.setPen(penline);
    pnt.drawLine(QLine(160+pixW, 160, 320, 160));
    pnt.restore();
}
