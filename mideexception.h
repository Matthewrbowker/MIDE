#ifndef MIDEEXCEPTION_H
#define MIDEEXCEPTION_H

using namespace std;

#include <string>

class MIDEException : public std::exception
{
public:
    MIDEException(string);
};

#endif // MIDEEXCEPTION_H
