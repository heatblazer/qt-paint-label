#ifndef SidarTESTPAINT
#define SidarTESTPAINT

#include "sidarpaintinterface.h"


class SidarTestPaint : public SidarPaintInterface
{
public:
    SidarTestPaint();
    virtual ~SidarTestPaint();
    void SidarPaint(const SidarLabel &pSidar);
};


class SidarTestPaint1 : public SidarPaintInterface
{
public:
    SidarTestPaint1();
    virtual ~SidarTestPaint1();
    void SidarPaint(const SidarLabel &pSidar);

};


class SidarTestPaint2 : public SidarPaintInterface
{
public:
    SidarTestPaint2();
    virtual ~SidarTestPaint2();
    void SidarPaint(const SidarLabel &pSidar);
};


class SidarTestPaint3 : public SidarPaintInterface
{
public:
    SidarTestPaint3();
    virtual ~SidarTestPaint3();
    void SidarPaint(const SidarLabel &pSidar);
};


class SidarHTMLRender : public SidarPaintInterface
{
public:
    SidarHTMLRender();
    virtual ~SidarHTMLRender();
    void SidarPaint(const SidarLabel &pSidar);
};

#endif // SidarTESTPAINT

