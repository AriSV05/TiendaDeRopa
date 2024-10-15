
#ifndef PROGRA2_PROJECT_2_BRAVO_TRAJEDEPORTIVO_H
#define PROGRA2_PROJECT_2_BRAVO_TRAJEDEPORTIVO_H

#include <ostream>
#include "TrajeAbstracto.h"
#include "Pantaloneta.h"
#include "Camiseta.h"
#include "Tenni.h"

class TrajeDeportivo : public TrajeAbstracto{
public:
    PantalonAbstr *crearPantalon(double, string, string, bool) override;

    CamisAbstr *crearCamisa(double, string, string, bool) override;

    ZapatoAbstr *crearCalzado(double, string, string, bool) override;

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const TrajeDeportivo &deportivo);
};


#endif //PROGRA2_PROJECT_2_BRAVO_TRAJEDEPORTIVO_H
