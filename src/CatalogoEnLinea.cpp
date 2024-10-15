
#include "CatalogoEnLinea.h"

void CatalogoEnLinea::registerObserver(Cliente* observer) {
    //add
    clientes->add(observer);
}

void CatalogoEnLinea::removeObserver(Cliente* observer) {

    clientes->remove(observer);

}

void CatalogoEnLinea::notifyObserver() {
    int stock = getInStock();
    for (auto *observer : clientes->getClientes()) { // notify all observers/clients
        observer->update(stock);
    }
}

void CatalogoEnLinea::stock(string codigoTraje) {
    string codTraje;
    int cant = 0;
    for(auto traje : getTrajes()->getTrajes()){
        codTraje = traje->getCodigo();
        if(codTraje == codigoTraje){
            cant++;
        }
        else{
            continue;
        }
    }
    setInStock(cant);
    std::cout << std::endl;
    notifyObserver();
}

int CatalogoEnLinea::getInStock() const {
    return inStock;
}

void CatalogoEnLinea::setInStock(int inStock) {
    CatalogoEnLinea::inStock = inStock;
}

ManagerTrajes *CatalogoEnLinea::getTrajes() const {
    return trajes;
}

void CatalogoEnLinea::setTrajes(ManagerTrajes *trajes) {
    CatalogoEnLinea::trajes = trajes;
}

string CatalogoEnLinea::catalogo() {
    std::stringstream ss;
    for(auto catalog : trajes->getTrajes()){
        ss<<catalog->toString()<<"\n";
    }
    return ss.str();
}

ManagerClientes *CatalogoEnLinea::getClientes() const {
    return clientes;
}

void CatalogoEnLinea::setClientes(ManagerClientes *clientes) {
    CatalogoEnLinea::clientes = clientes;
}


string CatalogoEnLinea::isPersona() {
    string personas;
    for (auto persona_: getClientes()->getClientes()) {
        Persona* persona1 = dynamic_cast<Persona *>(persona_);
        if (persona1) {
            personas+=persona1->toString()+"\n";
        }
    }
    return personas;
}

string CatalogoEnLinea::isEmpresa() {
    string empresas;
    for (auto empresa_: getClientes()->getClientes()) {
        Empresa* empresa1 = dynamic_cast<Empresa *>(empresa_);
        if (empresa1) {
            empresas+=empresa1->toString()+"\n";
        }
    }
    return empresas;

}

