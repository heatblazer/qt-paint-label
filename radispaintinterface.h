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
    // TODO add function for resize if needed
};

#endif // RADISPAINTINTERFACE

