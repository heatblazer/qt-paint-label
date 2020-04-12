#ifndef sidarPaintINTERFACE
#define sidarPaintINTERFACE

class SidarLabel;

// interface class to declare the custom paint methids
class SidarPaintInterface
{
public:
    SidarPaintInterface();
    virtual ~SidarPaintInterface() = 0;
    virtual void sidarPaint(const SidarLabel& pSidar) = 0;
    // TODO add function for resize if needed
};

#endif // sidarPaintINTERFACE

