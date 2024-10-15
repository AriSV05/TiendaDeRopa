
#include "gtest/gtest.h"
#include "../src/TrajeAbstracto.h"
#include "../src/TrajeDeportivo.h"
#include "../src/ServicioTraslado.h"
#include "../src/ManagerTrajes.h"
#include "../src/CatalogoEnLinea.h"
#include "../src/ServicioTraslado.h"
#include "../src/Empresa.h"
#include "../src/Venta.h"
#include "../src/ManagerVentas.h"
#include "../src/ManagerArchivos.h"

TEST(ArchivoTxtTest,archivoTxt) {
try {
    TrajeAbstracto *trajeAbstracto;
    trajeAbstracto = new TrajeDeportivo;

    trajeAbstracto->setCodigo("E300");
    trajeAbstracto->crearCamisa(200, "azul", "G", true);
    trajeAbstracto->crearPantalon(110, "azul", "G", false);
    trajeAbstracto->crearCalzado(225, "azul", "G", false);

    ManagerTrajes trajesDeportivos;
    trajesDeportivos.add(trajeAbstracto);

    CatalogoEnLinea catalogoEnLinea;

    Persona persona1;
    persona1.setNombre("Ana");
    persona1.setCedula("111");
    persona1.setCiudad("Paris");
    persona1.setNacionalidad("francesa");
    persona1.setPais("Francia");
    persona1.setCorreoElec("ana@una.cr");

    ManagerClientes clientes;
    clientes.add(&persona1);

    catalogoEnLinea.setClientes(&clientes);
    catalogoEnLinea.setTrajes(&trajesDeportivos);

    ServicioTraslado servicioTraslado;

    Venta venta(&persona1, &catalogoEnLinea);
    venta.setCompradores(&clientes);

    ManagerVentas ventas;
    venta.realizarVenta("E300", 1);
    ventas.add(&venta);

    ManagerArchivos arch;
    arch.save("../../ventas.txt", ventas);

    EXPECT_STREQ(arch.read("../../ventas.txt").c_str(),"988.55,E300,535,111,Ana,ana@una.cr,Francia,Paris\n");

    }
    catch (std::exception e) {
    std::cout << e.what() << std::endl;
    }
}