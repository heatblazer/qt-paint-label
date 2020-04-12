#include "sidartestpaint.h"
#include "sidarlabel.h"

#include <QTextDocument>
#include <QPainter>

#include <iostream>

SidarTestPaint::SidarTestPaint()
{

}


SidarTestPaint::~SidarTestPaint()
{

}

void SidarTestPaint::sidarPaint(const SidarLabel &pSidar)
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
void SidarTestPaint1::sidarPaint(const SidarLabel &pSidar)
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

void SidarTestPaint2::sidarPaint(const SidarLabel &pSidar)
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


void SidarTestPaint3::sidarPaint(const SidarLabel &pSidar)
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

void SidarHTMLRender::sidarPaint(const SidarLabel &pSidar)
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


// experimental animation
SidarAnimation::SidarAnimation(QObject *parent) : QObject(parent),
    onetime(false), label_h(0), label_w(0)
{
    // init animation
    m_animation_object.text = "MOVTEX";
    m_animation_object.tex_x = 0;
    m_animation_object.tex_y = 0;

    m_anim_tick.setInterval(300);
    connect(&m_anim_tick, SIGNAL(timeout()),
            this, SLOT(updateAnimation()));
    m_anim_tick.start();
}



SidarAnimation::~SidarAnimation()
{

}

void SidarAnimation::sidarPaint(const SidarLabel &pSidar)
{
    QPen pentext(QColor(255, 0, 0));
    QPainter pnt((QPaintDevice*)&pSidar);

    if (!onetime) {
        onetime = true;
        label_h = pSidar.size().height();
        label_w = pSidar.size().width();
        QFont fnt(pSidar.font());
        QFontMetrics fm(fnt);
        m_animation_object.tex_w = fm.width(m_animation_object.text);
        m_animation_object.tex_h = fm.height();

    }
    pnt.save();

    pnt.setPen(pentext);
    pnt.drawText(m_animation_object.tex_x, m_animation_object.tex_w, m_animation_object.text);
    pnt.restore();
}

void SidarAnimation::updateAnimation()
{

    std::cout << "Anim tick" << std::endl;
    if (m_animation_object.tex_x+m_animation_object.tex_w >= label_w) {
        m_animation_object.vel = -1;
    }
    if (m_animation_object.tex_x <= 0) {
        m_animation_object.vel = 1;
    }

    m_animation_object.tex_x+=30 * m_animation_object.vel;

}

void SidarTestPaintQuad::preparePoints(FIZ<int>::QuadTree *root)
{
    if (!root) return;
    QRect r(QPoint(root->dim.topLeft.x, root->dim.topLeft.y),
            QPoint(root->dim.bottomRight.x, root->dim.bottomRight.y));
    m_points.append(r);

    preparePoints(root->topLeft);
    preparePoints(root->topRight);
    preparePoints(root->bottomLeft);
    preparePoints(root->bottomRight);
}

SidarTestPaintQuad::SidarTestPaintQuad() :
    quatt(FIZ<int>::Dimension(
              FIZ<int>::Point(0,0), FIZ<int>::Point(100,100)))
{
    quatt.insert(FIZ<int>::Point(10,10));
    quatt.insert(FIZ<int>::Point(40,40));
    quatt.insert(FIZ<int>::Point(30,70));
    quatt.insert(FIZ<int>::Point(20,70));

}

SidarTestPaintQuad::~SidarTestPaintQuad()
{

}

void SidarTestPaintQuad::sidarPaint(const SidarLabel &pSidar)
{
    this->preparePoints(&quatt);
    QPen penline(QColor(255, 0, 0));
    QPen pentext(QColor(0, 0, 255));

    QPainter pnt((QPaintDevice*)&pSidar);
    pnt.setPen(penline);
    QString s("QuadTree");
    QFont fnt(pSidar.font());
    QFontMetrics fm(fnt);
    int pixW = fm.width(s);
    int pixH = fm.height();
    pnt.save();
    QBrush br(QColor(255, 255, 0));
    for(auto rect : m_points) {
        pnt.drawRect(rect);
    }
    pnt.restore();
}
