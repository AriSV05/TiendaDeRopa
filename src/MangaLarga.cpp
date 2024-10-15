
#include "MangaLarga.h"

MangaLarga::MangaLarga(double precio, const string &color, const string &talla, bool lisa) : CamisAbstr(precio, color,
                                                                                                         talla),
                                                                                              lisa(lisa) {}

bool MangaLarga::isLisa() const {
    return lisa;
}

void MangaLarga::setLisa(bool lisa) {
    MangaLarga::lisa = lisa;
}

string MangaLarga::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const MangaLarga &larga) {
    os << "[Manga larga]" << " lisa: ";
    if(larga.lisa){
        os<<"si";
    }
    else{
        os<<"no";
    }
    os<<" precio: "<<larga.getPrecio()<<" color: "<<larga.getColor()
      <<" talla: "<<larga.getTalla();
    return os;
}
MangaLarga::~MangaLarga() = default;

