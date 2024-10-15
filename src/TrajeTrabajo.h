
#ifndef PROGRA2_PROJECT_2_BRAVO_TRAJETRABAJO_H
#define PROGRA2_PROJECT_2_BRAVO_TRAJETRABAJO_H

#include <ostream>
#include "TrajeAbstracto.h"
#include "Bota.h"
#include "Jeans.h"
#include "ConCuadros.h"

class TrajeTrabajo : public TrajeAbstracto{

public:
    PantalonAbstr *crearPantalon(double, string, string, bool) override;

    CamisAbstr *crearCamisa(double, string, string, bool) override;

    ZapatoAbstr *crearCalzado(double, string, string, bool) override;

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const TrajeTrabajo &trabajo);

};


#endif //PROGRA2_PROJECT_2_BRAVO_TRAJETRABAJO_H
