
#ifndef II_RECIBO_H
#define II_RECIBO_H
#include "Venta.h"

class Recibo {

private:
    string fecha;
    string hora;
    Venta* venta;

public:
    Recibo();

    string generarRecibo(string, string);

    Venta *getVenta() const;

    void setVenta(Venta *venta);


};


#endif //II_RECIBO_H
