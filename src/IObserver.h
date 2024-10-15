
#ifndef II_IOBSERVER_H
#define II_IOBSERVER_H

#include <iostream>
#include <sstream>

using std::string;

class IObserver{

public:
    virtual void update(int) = 0;

    virtual ~IObserver() {}
};


#endif //II_IOBSERVER_H
