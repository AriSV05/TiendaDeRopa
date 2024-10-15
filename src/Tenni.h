
#ifndef PROGRA2_PROJECT_2_BRAVO_TENNI_H
#define PROGRA2_PROJECT_2_BRAVO_TENNI_H

#include <ostream>
#include "ZapatoAbstr.h"

class Tenni : public ZapatoAbstr{
private:
    bool Adidas;

public:
    Tenni(double precio, const string &color, const string &talla, bool adidas);

    virtual ~Tenni();

    bool isAdidas() const;
    void setAdidas(bool adidas);

    string toString() override;
    friend std::ostream &operator<<(std::ostream &os, const Tenni &tenni);
};


#endif //PROGRA2_PROJECT_2_BRAVO_TENNI_H
