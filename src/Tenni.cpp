
#include "Tenni.h"

Tenni::Tenni(double precio, const string &color, const string &talla, bool adidas) : ZapatoAbstr(precio, color,
                                                                                                  talla),
                                                                                      Adidas(adidas) {}

bool Tenni::isAdidas() const {
    return Adidas;
}

void Tenni::setAdidas(bool adidas) {
    Adidas = adidas;
}

Tenni::~Tenni() {

}

string Tenni::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Tenni &tenni) {
    os << "[Tenni]" << " Adidas: ";
    if(tenni.Adidas){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<tenni.getPrecio()<<" color: "<<tenni.getColor()
      <<" talla: "<<tenni.getTalla();
    return os;
}


