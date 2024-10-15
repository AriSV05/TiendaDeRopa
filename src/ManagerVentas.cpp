
#include "ManagerVentas.h"

void ManagerVentas::add(Venta *venta) {
    ventas.push_back(venta);
}

const std::vector<Venta *> &ManagerVentas::getVentas() const {
    return ventas;
}

void ManagerVentas::setVentas(const std::vector<Venta *> &ventas) {
    ManagerVentas::ventas = ventas;
}

double ManagerVentas::ventasTotales() const {
    double ganancias = 0;
    for(auto venta: getVentas()){
        ganancias += venta->getGanacia();
    }
    ganancias = ceil(ganancias * 100.0) / 100.0;    //redondeo hacia arriba 2 decimales
    return ganancias;
}

string ManagerVentas::trajeMasVendido() const {
    int temp = 0;
    string masVendido = "";
    int count;
    for(auto venta : getVentas()){
        for(auto traje : venta->getTrajesVendidos()){
            auto trajes = venta->getTrajesVendidos();
            count = std::count(trajes.begin(), trajes.end(), traje);
            if(count > temp){
                temp = count;
                masVendido = traje->getCodigo();
            }
        }
    }
    return masVendido;
}

std::ostream &operator<<(std::ostream &os, const ManagerVentas &ventas) {
    os << "\t\t[Ventas]\n";
    for(auto venta : ventas.getVentas()){
        os<<venta->toString()<<std::endl;
    }
    return os;
}
string ManagerVentas::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}
