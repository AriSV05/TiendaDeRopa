
#include "Recibo.h"

Recibo::Recibo() {
    this->fecha = "";
    this->hora = "";
    this->venta = nullptr;
}

string Recibo::generarRecibo(string fecha, string hora) {
    std::stringstream ss;
    ss<<"[Fecha: "<<fecha<<" Hora: "<<hora<<"]"<<std::endl;
    ss<<venta->getComprador()->getCedula()<<" "
    <<venta->getComprador()->getNombre()<<"\n\n"
    <<venta->getComprador()->getPais()<<" "
    <<venta->getComprador()->getCiudad()
    <<"\n\nTraje(s) vendido(s): "<<venta->getTrajesVendidos().size()<<"\n";
    for(auto traje : venta->getTrajesVendidos()){
        ss<<"Codigo de traje: "<<traje->getCodigo()<<"\n";
    }
    ss<<"Total- "<<venta->ventaTotalConGanancia();
    return ss.str();
}

Venta *Recibo::getVenta() const {
    return venta;
}

void Recibo::setVenta(Venta *venta) {
    Recibo::venta = venta;
}
