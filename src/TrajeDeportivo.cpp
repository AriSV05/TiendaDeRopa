
#include "TrajeDeportivo.h"

PantalonAbstr *TrajeDeportivo::crearPantalon(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);
    return new Pantaloneta(precio, color, talla, booleano);
}

CamisAbstr *TrajeDeportivo::crearCamisa(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);
    return new Camiseta(precio, color, talla, booleano);
}

ZapatoAbstr *TrajeDeportivo::crearCalzado(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);
    return new Tenni(precio, color, talla, booleano);
}

string TrajeDeportivo::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const TrajeDeportivo &deportivo) {
    os << "[Traje Deportivo] codigo: "<<deportivo.getCodigo()<<" precio: "<<deportivo.getPrecioTraje();
    return os;
}
