#include "radistestpaint.h"

#include "radislabel.h"

#include <QTextDocument>
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
    QString s1("Left");
    QString s2("Right");
    QFont fnt(pradis.font());
    QFontMetrics fm(fnt);
    int pixW1 = fm.width(s1);
    int pixH1 = fm.height();
    int pixW2 = fm.width(s2);

    pnt.save();
    pnt.setPen(pentext);
    pnt.drawText(0, pixW1, s1);
    pnt.setPen(penline);
    /*pixW1+pradis.size().width()-pixW2,*/
    pnt.drawLine(QLine(pixW1, pixW1,
                       pradis.size().width()-pixW2, pixW1));
    pnt.setPen(pentext);
    pnt.drawText(pradis.size().width()-pixW2, pixW1, s2);
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
    QString s("WRAPPED");
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
    QPen penline(QColor(255, 0, 0));
    QPen pentext(QColor(255, 0, 255));

    QPainter pnt((QPaintDevice*)&pradis);
    pnt.setPen(penline);
    QString s("Custom draw");
    QFont fnt(pradis.font());
    QFontMetrics fm(fnt);
    int pixW = fm.width(s);
    int pixH = fm.height();
    pnt.save();
    QBrush br(QColor(255, 255, 0));
    pnt.fillRect(0,0, pradis.size().width(), pradis.size().height(), br);
    pnt.drawLine(QLine(0, 160, 160, 160));
    pnt.setPen(pentext);
    pnt.drawText(160, 165, s);
    pnt.setPen(penline);
    pnt.drawLine(QLine(160+pixW, 160, 320, 160));
    pnt.restore();
}





RadisTestPaint3::RadisTestPaint3()
{

}

RadisTestPaint3::~RadisTestPaint3()
{

}


void RadisTestPaint3::radisPaint(const RadisLabel &pradis)
{
    QPen penline(QColor(70, 255, 0));
    QPen pentext(QColor(0, 167, 255));

    QSize radis_size = pradis.size();
    QPainter pnt((QPaintDevice*)&pradis);
    pnt.setPen(penline);
    QString s("PRETTY DECORATION");
    QFont fnt(pradis.font());
    QFontMetrics fm(fnt);
    int pixW = fm.width(s);
    int pixH = fm.height(); // unused for now
    pnt.save();

    int texBegin = (radis_size.width()/2) - pixW/2;
    int texEnd   = (radis_size.width()/2) + pixW/2;

    int drawHeight = radis_size.height()/2;
    pnt.drawLine(QLine(0, drawHeight, texBegin, drawHeight));
    pnt.drawLine(QLine(texBegin, drawHeight-pixH, texEnd, drawHeight-pixH));
    pnt.drawLine(QLine(texBegin, drawHeight+pixH, texEnd, drawHeight+pixH));

    pnt.setPen(pentext);

    pnt.drawText(texBegin, drawHeight+(pixH/3), s);

    pnt.setPen(penline);

    pnt.drawLine(QLine(texEnd, drawHeight, radis_size.width(), drawHeight));
    pnt.restore();
}





RadisHTMLRender::RadisHTMLRender()
{

}

RadisHTMLRender::~RadisHTMLRender()
{

}

void RadisHTMLRender::radisPaint(const RadisLabel &pradis)
{
    QPainter pnt((QPaintDevice*)&pradis);

    QTextDocument html;
    html.setHtml(QString("<body>"
                         "<h3 style='color:red;'> Hello HTML </h3>"
                         "</body>"));

    html.drawContents(&pnt);
}
