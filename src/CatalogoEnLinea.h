

#ifndef II_CATALOGOENLINEA_H
#define II_CATALOGOENLINEA_H

#include <vector>
#include "ManagerTrajes.h"
#include "ManagerClientes.h"
#include "IObserver.h"
#include "Persona.h"
#include "Empresa.h"
#include "ISubject.h"

class CatalogoEnLinea : public ISubject{

private:
    ManagerClientes* clientes;
    //std::vector<IObserver *> observers;
    ManagerTrajes* trajes;
    int inStock;

public:
    int getInStock() const;
    void setInStock(int inStock);
    ManagerTrajes *getTrajes() const;
    void setTrajes(ManagerTrajes *trajes);
    //const std::vector<IObserver *> &getObservers() const;
    //void setObservers(const std::vector<IObserver *> &observers);
    ManagerClientes *getClientes() const;

    void setClientes(ManagerClientes *clientes);

    void registerObserver(Cliente* observer) override;
    void removeObserver(Cliente* observer) override;
    void notifyObserver() override;

    void stock(string) override;
    string catalogo();

    string isPersona();
    string isEmpresa();

};


#endif //II_CATALOGOENLINEA_H
