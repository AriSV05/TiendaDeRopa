
#ifndef PROGRA2_PROJECT_2_BRAVO_BOTA_H
#define PROGRA2_PROJECT_2_BRAVO_BOTA_H

#include "ZapatoAbstr.h"

class Bota : public ZapatoAbstr{
private:
    bool alta;

public:
    Bota(double precio, const string &color, const string &talla, bool alta);

    virtual ~Bota();

    bool isAlta() const;
    void setAlta(bool alta);

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const Bota &bota);
};


#endif //PROGRA2_PROJECT_2_BRAVO_BOTA_H
