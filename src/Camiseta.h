
#ifndef PROGRA2_PROJECT_2_BRAVO_CAMISETA_H
#define PROGRA2_PROJECT_2_BRAVO_CAMISETA_H

#include <ostream>
#include "CamisAbstr.h"

class Camiseta : public CamisAbstr {
private:
    bool cuelloV;

public:
    Camiseta(double precio, const string &color, const string &talla, bool cuelloV);
    virtual ~Camiseta();

    bool isCuelloV() const;
    void setCuelloV(bool cuelloV);

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const Camiseta &camiseta);

};


#endif //PROGRA2_PROJECT_2_BRAVO_CAMISETA_H
