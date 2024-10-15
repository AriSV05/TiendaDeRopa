
#ifndef II_MANAGERARCHIVOS_H
#define II_MANAGERARCHIVOS_H

#include "ManagerVentas.h"
#include <fstream>

class ManagerArchivos {

private:
    ManagerVentas ventas;

public:
    void save(string, ManagerVentas);
    string read(string);

    const ManagerVentas &getVentas() const;
    void setVentas(const ManagerVentas &ventas);
};


#endif //II_MANAGERARCHIVOS_H
