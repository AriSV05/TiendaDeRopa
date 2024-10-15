
#include "ManagerTrajes.h"

const std::vector<TrajeAbstracto *> &ManagerTrajes::getTrajes() const {
    return trajes;
}

void ManagerTrajes::setTrajes(const std::vector<TrajeAbstracto *> &trajes) {
    ManagerTrajes::trajes = trajes;
}

void ManagerTrajes::add(TrajeAbstracto *traje) {
    trajes.push_back(traje);

}

void ManagerTrajes::remove(TrajeAbstracto *traje) {
    auto iterator = std::find(trajes.begin(), trajes.end(), traje);

    if (iterator != trajes.end()) {
        trajes.erase(iterator);
    }
}

