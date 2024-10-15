
#ifndef PROGRA2_PROJECT_2_BRAVO_TRAJEEJECUTIVO_H
#define PROGRA2_PROJECT_2_BRAVO_TRAJEEJECUTIVO_H

#include <ostream>
#include "TrajeAbstracto.h"
#include "MangaLarga.h"
#include "DeVestir.h"
#include "Ejecutivo.h"

class TrajeEjecutivo : public TrajeAbstracto{
public:
    PantalonAbstr *crearPantalon(double, string, string, bool) override;

    CamisAbstr *crearCamisa(double, string, string, bool) override;

    ZapatoAbstr *crearCalzado(double, string, string, bool) override;

    string toString() override;

    friend std::ostream &operator<<(std::ostream &os, const TrajeEjecutivo &ejecutivo);
};


#endif //PROGRA2_PROJECT_2_BRAVO_TRAJEEJECUTIVO_H
