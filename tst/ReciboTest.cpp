
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
#include "../src/Recibo.h"

TEST(ReciboTest,imprimirRecibo) {

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

    venta.realizarVenta("E300", 1);

    Recibo recibo;
    recibo.setVenta(&venta);
    
    EXPECT_STREQ(recibo.generarRecibo("22/6/2022","17:50pm").c_str(),"[Fecha: 22/6/2022 Hora: 17:50pm]\n111 Ana\n\nFrancia Paris\n\nTraje(s) vendido(s): 1\nCodigo de traje: E300\nTotal- 1163");
}