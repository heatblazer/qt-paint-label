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
    QString s("LINE 3");
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


RadisTestPaint1::RadisTestPaint1()
{

}


RadisTestPaint1::~RadisTestPaint1()
{

}

// No hardcoding test!!!
void RadisTestPaint1::radisPaint(const RadisLabel &pradis)
{
    QPen penline(QColor(70, 255, 0));
    QPen pentext(QColor(0, 167, 255));

    QSize radis_size = pradis.size();
    QPainter pnt((QPaintDevice*)&pradis);
    pnt.setPen(penline);
    QString s("MADAFAKAAA000110");
    QFont fnt(pradis.font());
    QFontMetrics fm(fnt);
    int pixW = fm.width(s);
    int pixH = fm.height(); // unused for now
    pnt.save();

    int texBegin = (radis_size.width()/2) - pixW/2;
    int texEnd   = (radis_size.width()/2) + pixW/2;

    int drawHeight = radis_size.height()/2;

    pnt.drawLine(QLine(0, drawHeight, texBegin, drawHeight));
    pnt.setPen(pentext);
    pnt.drawText(texBegin, drawHeight+(pixH/3), s);
    pnt.setPen(penline);
    pnt.drawLine(QLine(texEnd, drawHeight, radis_size.width(), drawHeight));
    pnt.restore();
}


RadisTestPaint2::RadisTestPaint2()
{

}


RadisTestPaint2::~RadisTestPaint2()
{

}

void RadisTestPaint2::radisPaint(const RadisLabel &pradis)
{
    QPen penline(QColor(255, 255, 0));
    QPen pentext(QColor(255, 0, 255));

    QPainter pnt((QPaintDevice*)&pradis);
    pnt.setPen(penline);
    QString s("LINE 12312");
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
