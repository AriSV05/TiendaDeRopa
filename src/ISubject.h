
#ifndef II_ISUBJECT_H
#define II_ISUBJECT_H
#include "IObserver.h"

class ISubject {

public:
    virtual void registerObserver(Cliente* observer) = 0;
    virtual void removeObserver(Cliente* observer) = 0;
    virtual void notifyObserver() = 0;
    virtual void stock(string) = 0;

    virtual ~ISubject() {}
};


#endif //II_ISUBJECT_H
