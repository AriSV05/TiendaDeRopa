
#ifndef II_MANAGERTRAJES_H
#define II_MANAGERTRAJES_H
#include <vector>
#include "TrajeAbstracto.h"

class ManagerTrajes {

private:
    std::vector<TrajeAbstracto*> trajes;

public:
    void add(TrajeAbstracto* traje);
    void remove(TrajeAbstracto* traje);

    const std::vector<TrajeAbstracto *> &getTrajes() const;
    void setTrajes(const std::vector<TrajeAbstracto *> &trajes);

};


#endif //II_MANAGERTRAJES_H
