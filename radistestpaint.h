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


#endif // RADISTESTPAINT

