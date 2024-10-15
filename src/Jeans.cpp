
#include "Jeans.h"

Jeans::Jeans(double precio, const string &color, const string &talla, bool ajustado) : PantalonAbstr(precio, color,
                                                                                                      talla),
                                                                                        ajustado(ajustado) {}

Jeans::~Jeans() {

}

bool Jeans::isAjustado() const {
    return ajustado;
}

void Jeans::setAjustado(bool ajustado) {
    Jeans::ajustado = ajustado;
}

string Jeans::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Jeans &jeans) {
    os << "[Jeans]" << " ajustado: ";
    if(jeans.ajustado){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<jeans.getPrecio()<<" color: "<<jeans.getColor()
      <<" talla: "<<jeans.getTalla();
    return os;
}


