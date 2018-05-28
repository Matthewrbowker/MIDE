#include "sourcenode.h"
#include <string>

#ifndef SOURCE_H
#define SOURCE_H


class Source
{
private:
    sourceNode * first;
public:
    Source();
    void add(string, string, string);
    sourceNode * find(string);
};

#endif // SOURCE_H
