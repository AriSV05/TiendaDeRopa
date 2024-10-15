#include "TrajeAbstracto.h"
#include "TrajeDeportivo.h"
#include "CamisAbstr.h"
#include "PantalonAbstr.h"
#include "ZapatoAbstr.h"
#include "ManagerTrajes.h"

#include "CatalogoEnLinea.h"
#include "Persona.h"
#include "Empresa.h"

#include "ServicioTraslado.h"
#include "Venta.h"
#include "Recibo.h"
#include "ManagerVentas.h"

#include "ManagerArchivoJSON.h"
#include "ManagerArchivos.h"

int main() {
    try {
        TrajeAbstracto *trajeAbstracto, *trajeAbstracto2;
        CamisAbstr *camiseta, *camisetaV;
        PantalonAbstr *pantaloneta, *pantalonetaEstamp;
        ZapatoAbstr *tenni, *tenniAdidas;

        trajeAbstracto = new TrajeDeportivo;
        trajeAbstracto2 = new TrajeDeportivo;

        trajeAbstracto->setCodigo("E300");
        camiseta = trajeAbstracto->crearCamisa(150, "azul", "G", false);
        pantaloneta = trajeAbstracto->crearPantalon(110, "azul", "G", false);
        tenni = trajeAbstracto->crearCalzado(225, "azul", "G", false);

        trajeAbstracto2->setCodigo("E200");
        camisetaV = trajeAbstracto2->crearCamisa(200, "azul", "G", true);
        pantalonetaEstamp = trajeAbstracto2->crearPantalon(150, "azul", "G", true);
        tenniAdidas = trajeAbstracto2->crearCalzado(335, "azul", "G", true);

        std::cout << trajeAbstracto->toString() << std::endl << std::endl;

        std::cout << camiseta->toString() << std::endl;
        std::cout << pantaloneta->toString() << std::endl;
        std::cout << tenni->toString() << std::endl;

        std::cout << "Precio Total: " << trajeAbstracto->getPrecioTraje() << std::endl << std::endl;

        std::cout << trajeAbstracto2->toString() << std::endl << std::endl;

        std::cout << camisetaV->toString() << std::endl;
        std::cout << pantalonetaEstamp->toString() << std::endl;
        std::cout << tenniAdidas->toString() << std::endl;

        std::cout << "Precio Total: " << trajeAbstracto2->getPrecioTraje() << std::endl << std::endl;

        ManagerTrajes trajesDeportivos;
        CatalogoEnLinea catalogoEnLinea;
        trajesDeportivos.add(trajeAbstracto);
        trajesDeportivos.add(trajeAbstracto);
        trajesDeportivos.add(trajeAbstracto);
        trajesDeportivos.add(trajeAbstracto2);
        trajesDeportivos.add(trajeAbstracto2);
        trajesDeportivos.add(trajeAbstracto2);
        trajesDeportivos.add(trajeAbstracto2);


        Persona personaCliente, persona, persona1;
        Empresa empresaCliente, empresa;
        ManagerClientes clientes;

        catalogoEnLinea.setClientes(&clientes);

        catalogoEnLinea.registerObserver(&empresaCliente);  //1
        catalogoEnLinea.registerObserver(&empresa); //2
        string pais = "EE-UU";
        string ciudad = "California";
        personaCliente.setCiudad(ciudad);
        personaCliente.setPais(pais);
        persona1.setCiudad(ciudad);
        persona1.setPais(pais);
        catalogoEnLinea.registerObserver(&personaCliente);  //3


        std::cout << "Clientes manager " << clientes.getClientes().size() << std::endl;
        std::cout << "Cientes catalogo " << catalogoEnLinea.getClientes()->getClientes().size() << std::endl;
        catalogoEnLinea.registerObserver(&personaCliente);
        std::cout << "Cientes catalogo " << catalogoEnLinea.getClientes()->getClientes().size() << std::endl;

        catalogoEnLinea.setTrajes(&trajesDeportivos);

        std::cout << trajesDeportivos.getTrajes().size() << std::endl; //3

        catalogoEnLinea.stock("E300");
        std::cout << catalogoEnLinea.catalogo();

        //trajesDeportivos.remove(trajeAbstracto);

        std::cout << trajesDeportivos.getTrajes().size(); //2

        catalogoEnLinea.stock("E300");
        std::cout << catalogoEnLinea.catalogo();

        std::cout << std::endl << catalogoEnLinea.isPersona() << std::endl;
        std::cout << catalogoEnLinea.isEmpresa();

        catalogoEnLinea.removeObserver(&persona);   //2

        ServicioTraslado servicioTraslado;

        std::cout << std::endl << servicioTraslado.obtenerCodigoCiudad(ciudad) << std::endl;
        std::cout << servicioTraslado.obtenerCodigoPais(pais) << std::endl;
        std::cout << servicioTraslado.obtenerPrecioTraslado(pais, ciudad) << std::endl;


        Venta venta(&personaCliente, &catalogoEnLinea);

        venta.setCompradores(&clientes);

        std::cout << "Clientes en venta " << venta.getCompradores()->getClientes().size();

        ManagerVentas ventas;

        std::cout << "Realizar Venta" << std::endl << std::endl;

        venta.realizarVenta("E300", 2);
        std::cout << std::endl << ventas.trajeMasVendido() << std::endl;
        std::cout << "\nClientes en venta " << venta.getCompradores()->getClientes().size() << std::endl << std::endl;
        std::cout << "\nTrajes vendidos " << venta.getTrajesVendidos().size() << std::endl;
        std::cout << venta.toString() << std::endl << std::endl;
        ventas.add(&venta);

        Recibo recibo;
        recibo.setVenta(&venta);
        std::cout << recibo.generarRecibo("15/6/2022", "8:00") << std::endl << std::endl;

        std::cout << ventas.ventasTotales() << std::endl;

        catalogoEnLinea.stock("E300");

        venta.realizarVenta("E200", 3);
        std::cout << std::endl << ventas.trajeMasVendido() << std::endl;
        std::cout << "\nTrajes vendidos " << venta.getTrajesVendidos().size() << std::endl;
        std::cout << "ganancia:" << venta.gananciaNeta() << " " << venta.getGanacia() << std::endl;

        std::cout << recibo.generarRecibo("15/6/2022", "8:00") << std::endl << std::endl;

        std::cout << ventas.toString();

        venta.setComprador(&persona1);
        std::cout << "Clientes en venta " << venta.getCompradores()->getClientes().size() << std::endl;
        std::cout << ventas.toString();

        ManagerArchivos arch;
        arch.save("../../ventas.txt",ventas);
        std::cout<<"Texto"<<std::endl<<std::endl;
        std::cout<<arch.read("../../ventas.txt")<<std::endl;
        for(auto ventas2 : arch.getVentas().getVentas()){
            std::cout<<ventas2->getGanacia()<<'\n';
            std::cout<<ventas2->getCodTrajeVendido()<<'\n';
            std::cout<<ventas2->getPrecioTraje()<<'\n';
            std::cout<<ventas2->getComprador()->getCedula()<<'\n';
            std::cout<<ventas2->getComprador()->getNombre()<<'\n';
            std::cout<<ventas2->getComprador()->getCorreoElec()<<'\n';
            std::cout<<ventas2->getComprador()->getPais()<<'\n';
            std::cout<<ventas2->getComprador()->getCiudad()<<'\n';
        }
        /*ManagerArchivoJSON::save(ManagerArchivoJSON::serialize(ventas), "../../Ventas.json");


        std::cout << "\n\nDeserializacion del Json" << std::endl;

        string dataFromJSonFile;
        dataFromJSonFile = ManagerArchivoJSON::read("../../Ventas.json");
        std::cout << "Sin des\n\n" << dataFromJSonFile;

        ManagerVentas vent;
        vent = ManagerArchivoJSON::deserialize(dataFromJSonFile);
        std::cout<<vent.toString();*/

    }
    catch (std::exception e) {
        std::cout << "Error Caught" << std::endl;
    }
    return 0;
}
