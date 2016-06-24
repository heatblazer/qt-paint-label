#ifndef RADISTESTPAINT
#define RADISTESTPAINT

#include "radispaintinterface.h"


class RadisTestPaint : public RadisPaintInterface
{
public:
    RadisTestPaint();
    virtual ~RadisTestPaint();
    void radisPaint(const RadisLabel &pradis);
};


class RadisTestPaint1 : public RadisPaintInterface
{
public:
    RadisTestPaint1();
    virtual ~RadisTestPaint1();
    void radisPaint(const RadisLabel &pradis);
};


class RadisTestPaint2 : public RadisPaintInterface
{
public:
    RadisTestPaint2();
    virtual ~RadisTestPaint2();
    void radisPaint(const RadisLabel &pradis);
};

#endif // RADISTESTPAINT

