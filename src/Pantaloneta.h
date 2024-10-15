
#ifndef PROGRA2_PROJECT_2_BRAVO_PANTALONETA_H
#define PROGRA2_PROJECT_2_BRAVO_PANTALONETA_H

#include <ostream>
#include "PantalonAbstr.h"

class Pantaloneta : public PantalonAbstr{

private:
    bool estampado;

public:
    Pantaloneta(double precio, const string &color, const string &talla, bool estampado);

    virtual ~Pantaloneta();

    bool isEstampado() const;
    void setEstampado(bool estampado);

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const Pantaloneta &pantaloneta);
};


#endif //PROGRA2_PROJECT_2_BRAVO_PANTALONETA_H
