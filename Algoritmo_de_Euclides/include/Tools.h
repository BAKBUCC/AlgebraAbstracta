#ifndef TOOLS_H
#define TOOLS_H

#include <NTL/ZZ.h>
#include <iostream>
using namespace std;
using namespace NTL;

class Tools
{
    public:
        ZZ q,r;
        Tools();
        ZZ modulo(ZZ,ZZ);
        ZZ modulo(ZZ,int);

    protected:

    private:
};

#endif // TOOLS_H
