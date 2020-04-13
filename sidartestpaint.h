#ifndef SidarTESTPAINT
#define SidarTESTPAINT

#include "sidarpaintinterface.h"
#include "quadtree.h"
#include <QTimer>
#include <QObject>

class SidarTestPaint : public SidarPaintInterface
{
public:
    SidarTestPaint();
    virtual ~SidarTestPaint();
    void sidarPaint(const SidarLabel &pSidar);
};


class SidarTestPaint1 : public SidarPaintInterface
{
public:
    SidarTestPaint1();
    virtual ~SidarTestPaint1();
    void sidarPaint(const SidarLabel &pSidar);

};


class SidarTestPaint2 : public SidarPaintInterface
{
public:
    SidarTestPaint2();
    virtual ~SidarTestPaint2();
    void sidarPaint(const SidarLabel &pSidar);
};


class SidarTestPaint3 : public SidarPaintInterface
{
public:
    SidarTestPaint3();
    virtual ~SidarTestPaint3();
    void sidarPaint(const SidarLabel &pSidar);
};


class SidarTestPaintQuad : public SidarPaintInterface
{
    FIZ<int>::QuadTree* quatt;
    QList<QRect> m_points;
    void clearTree(FIZ<int>::QuadTree** root) ;
    void preparePoints(FIZ<int>::QuadTree* root);
public:
    SidarTestPaintQuad();
    virtual ~SidarTestPaintQuad();
    void sidarPaint(const SidarLabel &pSidar);
};

class SidarHTMLRender : public SidarPaintInterface
{
public:
    SidarHTMLRender();
    virtual ~SidarHTMLRender();
    void sidarPaint(const SidarLabel &pSidar);
};


class SidarAnimation : public QObject, public SidarPaintInterface
{
    Q_OBJECT
public:
    explicit SidarAnimation(QObject* parent=nullptr);
    virtual ~SidarAnimation();
    void sidarPaint(const SidarLabel& pSidar);
private slots:
    void updateAnimation(void);
private:
    QTimer m_anim_tick;
    struct {
        QString text;
        int tex_w; // = fm.width(s);
        int tex_h; // = fm.height(); // unused for now
        int tex_x;
        int tex_y;
        int vel;

    } m_animation_object;

    int     label_w;
    int     label_h;
    bool    onetime;
};

#endif // SidarTESTPAINT

