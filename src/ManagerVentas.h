
#ifndef II_MANAGERVENTAS_H
#define II_MANAGERVENTAS_H

#include <ostream>
#include <math.h>
#include "Venta.h"

class ManagerVentas {
private:
    std::vector<Venta*> ventas;

public:
    void add(Venta* venta);

    const std::vector<Venta *> &getVentas() const;
    void setVentas(const std::vector<Venta *> &ventas);

    double ventasTotales() const;
    string trajeMasVendido() const;

    string toString();

    friend std::ostream &operator<<(std::ostream &os, const ManagerVentas &ventas);
};


#endif //II_MANAGERVENTAS_H
