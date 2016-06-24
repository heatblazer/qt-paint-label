#ifndef RADISPAINTINTERFACE
#define RADISPAINTINTERFACE

class RadisLabel;

// interface class to declare the custom paint methids
class RadisPaintInterface
{
public:
    RadisPaintInterface();
    virtual ~RadisPaintInterface() = 0;
    virtual void radisPaint(const RadisLabel& pradis) = 0;
};

#endif // RADISPAINTINTERFACE

