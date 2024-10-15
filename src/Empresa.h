
#ifndef PROGRA2_PROJECT_2_BRAVO_EMPRESA_H
#define PROGRA2_PROJECT_2_BRAVO_EMPRESA_H

#include <ostream>
#include "Cliente.h"

class Empresa : public Cliente{

private:
    bool clienteFrecuente;

public:
    Empresa();

    bool isClienteFrecuente() const;
    void setClienteFrecuente(bool clienteFrecuente);

    friend std::ostream &operator<<(std::ostream &os, const Empresa &empresa);

    void update(int) override;
    string toString() override;

};


#endif //PROGRA2_PROJECT_2_BRAVO_EMPRESA_H
