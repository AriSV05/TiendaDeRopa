
#ifndef PROGRA2_PROJECT_2_BRAVO_EJECUTIVO_H
#define PROGRA2_PROJECT_2_BRAVO_EJECUTIVO_H

#include "ZapatoAbstr.h"

class Ejecutivo : public ZapatoAbstr{
private:
    bool fino;

public:
    Ejecutivo(double precio, const string &color, const string &talla, bool fino);

    virtual ~Ejecutivo();

    bool isFino() const;
    void setFino(bool fino);

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const Ejecutivo &ejecutivo);
};


#endif //PROGRA2_PROJECT_2_BRAVO_EJECUTIVO_H
