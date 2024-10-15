
#include "TrajeTrabajo.h"

PantalonAbstr *TrajeTrabajo::crearPantalon(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);

    return new Jeans(precio, color, talla, booleano);
}

CamisAbstr *TrajeTrabajo::crearCamisa(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);

    return new ConCuadros(precio, color, talla, booleano);
}

ZapatoAbstr *TrajeTrabajo::crearCalzado(double precio, string color, string talla, bool booleano) {
    double precioTraje = getPrecioTraje()+precio;
    setPrecioTraje(precioTraje);

    return new Bota(precio, color, talla, booleano);
}

string TrajeTrabajo::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const TrajeTrabajo &trabajo) {
    os << "[Traje Trabajo] codigo: "<<trabajo.getCodigo()<<" precio: "<<trabajo.getPrecioTraje();
    return os;
}
