
#ifndef PROGRA2_PROJECT_2_BRAVO_TRAJEABSTRACTO_H
#define PROGRA2_PROJECT_2_BRAVO_TRAJEABSTRACTO_H

#include "PantalonAbstr.h"
#include "CamisAbstr.h"
#include "ZapatoAbstr.h"

class TrajeAbstracto {

private:
    double precioTraje;
    string tipo;
    string codigo;

public:
    TrajeAbstracto();

    double getPrecioTraje() const;
    void setPrecioTraje(double precioTraje);
    const string &getTipo() const;
    void setTipo(const string &tipo);
    const string &getCodigo() const;
    void setCodigo(const string &codigo);

    virtual PantalonAbstr* crearPantalon(double, string, string, bool) = 0;
    virtual CamisAbstr* crearCamisa(double, string, string, bool) = 0;
    virtual ZapatoAbstr* crearCalzado(double, string, string, bool) = 0;

    virtual string toString() = 0;
};


#endif //PROGRA2_PROJECT_2_BRAVO_TRAJEABSTRACTO_H
