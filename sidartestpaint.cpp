#include "sidartestpaint.h"
#include "sidarlabel.h"

#include <QTextDocument>
#include <QPainter>


SidarTestPaint::SidarTestPaint()
{

}


SidarTestPaint::~SidarTestPaint()
{

}

void SidarTestPaint::SidarPaint(const SidarLabel &pSidar)
{
    QPen penline(QColor(255, 0, 0));
    QPen pentext(QColor(0, 0, 255));

    QPainter pnt((QPaintDevice*)&pSidar);
    pnt.setPen(penline);
    QString s1("Left");
    QString s2("Right");
    QFont fnt(pSidar.font());
    QFontMetrics fm(fnt);
    int pixW1 = fm.width(s1);
    int pixH1 = fm.height();
    int pixW2 = fm.width(s2);

    pnt.save();
    pnt.setPen(pentext);
    pnt.drawText(0, pixW1, s1);
    pnt.setPen(penline);
    /*pixW1+pSidar.size().width()-pixW2,*/
    pnt.drawLine(QLine(pixW1, pixW1,
                       pSidar.size().width()-pixW2, pixW1));
    pnt.setPen(pentext);
    pnt.drawText(pSidar.size().width()-pixW2, pixW1, s2);
    pnt.restore();
}


SidarTestPaint1::SidarTestPaint1()
{

}


SidarTestPaint1::~SidarTestPaint1()
{

}

// No hardcoding test!!!
void SidarTestPaint1::SidarPaint(const SidarLabel &pSidar)
{
    QPen penline(QColor(70, 255, 0));
    QPen pentext(QColor(0, 167, 255));

    QSize Sidar_size = pSidar.size();
    QPainter pnt((QPaintDevice*)&pSidar);
    pnt.setPen(penline);
    QString s("WRAPPED");
    QFont fnt(pSidar.font());
    QFontMetrics fm(fnt);
    int pixW = fm.width(s);
    int pixH = fm.height(); // unused for now
    pnt.save();

    int texBegin = (Sidar_size.width()/2) - pixW/2;
    int texEnd   = (Sidar_size.width()/2) + pixW/2;

    int drawHeight = Sidar_size.height()/2;

    pnt.drawLine(QLine(0, drawHeight, texBegin, drawHeight));
    pnt.setPen(pentext);
    pnt.drawText(texBegin, drawHeight+(pixH/3), s);
    pnt.setPen(penline);
    pnt.drawLine(QLine(texEnd, drawHeight, Sidar_size.width(), drawHeight));
    pnt.restore();
}


SidarTestPaint2::SidarTestPaint2()
{

}


SidarTestPaint2::~SidarTestPaint2()
{

}

void SidarTestPaint2::SidarPaint(const SidarLabel &pSidar)
{
    QPen penline(QColor(255, 0, 0));
    QPen pentext(QColor(255, 0, 255));

    QPainter pnt((QPaintDevice*)&pSidar);
    pnt.setPen(penline);
    QString s("Custom draw");
    QFont fnt(pSidar.font());
    QFontMetrics fm(fnt);
    int pixW = fm.width(s);
    int pixH = fm.height();
    pnt.save();
    QBrush br(QColor(255, 255, 0));
    pnt.fillRect(0,0, pSidar.size().width(), pSidar.size().height(), br);
    pnt.drawLine(QLine(0, 160, 160, 160));
    pnt.setPen(pentext);
    pnt.drawText(160, 165, s);
    pnt.setPen(penline);
    pnt.drawLine(QLine(160+pixW, 160, 320, 160));
    pnt.restore();
}





SidarTestPaint3::SidarTestPaint3()
{

}

SidarTestPaint3::~SidarTestPaint3()
{

}


void SidarTestPaint3::SidarPaint(const SidarLabel &pSidar)
{
    QPen penline(QColor(70, 255, 0));
    QPen pentext(QColor(0, 167, 255));

    QSize Sidar_size = pSidar.size();
    QPainter pnt((QPaintDevice*)&pSidar);
    pnt.setPen(penline);
    QString s("PRETTY DECORATION");
    QFont fnt(pSidar.font());
    QFontMetrics fm(fnt);
    int pixW = fm.width(s);
    int pixH = fm.height(); // unused for now
    pnt.save();

    int texBegin = (Sidar_size.width()/2) - pixW/2;
    int texEnd   = (Sidar_size.width()/2) + pixW/2;

    int drawHeight = Sidar_size.height()/2;
    pnt.drawLine(QLine(0, drawHeight, texBegin, drawHeight));
    pnt.drawLine(QLine(texBegin, drawHeight-pixH, texEnd, drawHeight-pixH));
    pnt.drawLine(QLine(texBegin, drawHeight+pixH, texEnd, drawHeight+pixH));

    pnt.setPen(pentext);

    pnt.drawText(texBegin, drawHeight+(pixH/3), s);

    pnt.setPen(penline);

    pnt.drawLine(QLine(texEnd, drawHeight, Sidar_size.width(), drawHeight));
    pnt.restore();
}





SidarHTMLRender::SidarHTMLRender()
{

}

SidarHTMLRender::~SidarHTMLRender()
{

}

void SidarHTMLRender::SidarPaint(const SidarLabel &pSidar)
{
    QPainter pnt((QPaintDevice*)&pSidar);

    QTextDocument html;
    html.setHtml(QString("<body>"
                         "<h3 style='color:red;'> Hello HTML </h3>"
                         "<br/>"
                         "<img src='/home/ilian/gitprojects/qt-paint-label/assets/globe_64.jpg' width='64' height='64'/>"
                         "</body>"));

    html.drawContents(&pnt);
}
