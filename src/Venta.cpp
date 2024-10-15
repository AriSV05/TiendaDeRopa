
#include "Venta.h"

Venta::Venta(Cliente *comprador, CatalogoEnLinea *catalogo) : catalogo(catalogo), comprador(comprador) {

    string pais = comprador->getPais();
    string ciudad = comprador->getCiudad();
    this->precioTraslado = ServicioTraslado().obtenerPrecioTraslado(pais,ciudad);
    this->ganacia = 0;
    this->precioTraje = 0;
    this->compradores = nullptr;
    this->codTrajeVendido = "";

}

double Venta::getGanacia() const {
    return ganacia;
}

void Venta::setGanacia(double ganacia) {
    Venta::ganacia = ganacia;
}

double Venta::ventaTotalConGanancia() const {
    double precioTrajes = getPrecioTraje();
    double gananciaTotal = (precioTrajes*80)/100;
    gananciaTotal += precioTrajes+getPrecioTraslado();
    return gananciaTotal;
}

double Venta::ventaTotalSinGanancia() const {
    double total;
    double precioTrajes = getPrecioTraje();
    total = precioTrajes+getPrecioTraslado();
    return total;
}

double Venta::gananciaNeta() {
    double totalGanancia = ventaTotalConGanancia();
    double totalNeto;
    totalNeto = totalGanancia - ((totalGanancia*15)/100);
    setGanacia(totalNeto);
    return totalNeto;
}

string Venta::realizarVenta(string codigoTraje, int cantidad) {
    agregarComprador();
    string message;
    double precioTrajes = 0;
    string codTraje = "";
    int stock = 0;
    std::vector<TrajeAbstracto*> trajesEliminar;
    for(auto traje : catalogo->getTrajes()->getTrajes()){   //cuenta cuantos trajes de ese codigo
        codTraje = traje->getCodigo();                                  //hay en el catalogo
        if(codTraje == codigoTraje){
            stock++;
        }
        else{
            continue;
        }
    }
    if(stock >= cantidad) {
        message = "Compra realizada";
        for(auto trajes: catalogo->getTrajes()->getTrajes()){
            if(trajes->getCodigo() == codigoTraje && cantidad != 0){
                trajesEliminar.push_back(trajes);   //si el traje encontrado tiene el mismo codigo y se puede
                trajesVendidos.push_back(trajes);   //comprar, almacena es un vector temporal el traje que se
                cantidad--;                         //eliminara al comprarse.
            }
        }
    }
    else{
        message = "No fue posible realizar la compra";
        setGanacia(0);
        setPrecioTraje(precioTrajes);
        return message;
    }
    for(int i = 0; i < trajesEliminar.size(); i++){     //elimina los trajes del catalogo
        auto temp = trajesEliminar.operator[](i);
        setCodTrajeVendido(temp->getCodigo());
        precioTrajes += temp->getPrecioTraje();
        catalogo->getTrajes()->remove(temp);
    }
    trajesEliminar.clear();
    setPrecioTraje(precioTrajes);
    gananciaNeta();
    return message;
}

Venta::~Venta() = default;

std::ostream &operator<<(std::ostream &os, const Venta &venta) {
    os<<"Precio Traslado: "<<venta.getPrecioTraslado()
    <<"\nPrecio de los trajes: "<<venta.getPrecioTraje()
    <<"\nTotal sin ganancia: "<<venta.ventaTotalSinGanancia()
    <<"\nTotal con ganancia: "<<venta.ventaTotalConGanancia()
    <<"\nTotal neto: "<<venta.getGanacia()
    <<"\n[Detalles del comprador]\n"<<venta.comprador->toString();

    return os;
}

string Venta::toString() {
    std::stringstream ss;
    ss<<(*this);
    return ss.str();
}

void Venta::agregarComprador() {
    Cliente* comp = getComprador();
    compradores->add(comp);
}

ManagerClientes *Venta::getCompradores() const {
    return compradores;
}

void Venta::setCompradores(ManagerClientes *compradores) {
    Venta::compradores = compradores;
}

Cliente *Venta::getComprador() const {
    return comprador;
}

void Venta::setComprador(Cliente *comprador) {
    Venta::comprador = comprador;
}

double Venta::getPrecioTraslado() const {
    return precioTraslado;
}

void Venta::setPrecioTraslado(double precioTraslado) {
    Venta::precioTraslado = precioTraslado;
}

CatalogoEnLinea *Venta::getCatalogo() const {
    return catalogo;
}

void Venta::setCatalogo(CatalogoEnLinea *catalogo) {
    Venta::catalogo = catalogo;
}

double Venta::getPrecioTraje() const {
    return precioTraje;
}

void Venta::setPrecioTraje(double precioTraje) {
    Venta::precioTraje = precioTraje;
}

const string &Venta::getCodTrajeVendido() const {
    return codTrajeVendido;
}

void Venta::setCodTrajeVendido(const string &codTrajeVendido) {
    Venta::codTrajeVendido = codTrajeVendido;
}

const std::vector<TrajeAbstracto *> &Venta::getTrajesVendidos() const {
    return trajesVendidos;
}

void Venta::setTrajesVendidos(const std::vector<TrajeAbstracto *> &trajesVendidos) {
    Venta::trajesVendidos = trajesVendidos;
}




