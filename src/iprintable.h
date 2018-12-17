#ifndef IPRINTABLE_H
#define IPRINTABLE_H

#include <ostream>

class IPrintable
{
protected:
    virtual void print(std::ostream & stream) = 0;
};

#endif // IPRINTABLE_H
