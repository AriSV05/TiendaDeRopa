
#include "TrajeEjecutivo.h"

PantalonAbstr *TrajeEjecutivo::crearPantalon(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);

    return new DeVestir(precio, color, talla, booleano);
}

CamisAbstr *TrajeEjecutivo::crearCamisa(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);

    return new MangaLarga(precio, color, talla, booleano);
}

ZapatoAbstr *TrajeEjecutivo::crearCalzado(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);

    return new Ejecutivo(precio, color, talla, booleano);
}

string TrajeEjecutivo::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const TrajeEjecutivo &ejecutivo) {
    os << "[Traje Ejecutivo] codigo: "<<ejecutivo.getCodigo()<<" precio: "<<ejecutivo.getPrecioTraje();
    return os;
}
