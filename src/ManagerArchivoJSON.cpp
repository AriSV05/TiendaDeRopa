
#include "ManagerArchivoJSON.h"

void to_json(json &_json, const ManagerVentas &ventas) {

    json jVenta;
    auto jVentasList = json::array();

    for (const auto &_venta: ventas.getVentas()) {
        jVenta["ganancia"] = _venta->getGanacia();
        jVenta["codTrajeVendido"] = _venta->getCodTrajeVendido();
        for (auto comprador: _venta->getCatalogo()->getClientes()->getClientes()) {
            jVenta["nombre"] = comprador->getNombre();
            jVenta["cedula"] = comprador->getCedula();
            jVenta["pagoSuscrip"] = comprador->getPagoSuscrip();
            jVenta["correoElec"] = comprador->getCorreoElec();
            jVenta["pais"] = comprador->getPais();
            jVenta["ciudad"] = comprador->getCiudad();
        }
        jVentasList.push_back(jVenta);
    }
    _json["ventas"] = jVentasList;
}

void from_json(const json &_json, ManagerVentas &ventas) {
    json ventasData = _json["ventas"];
    ManagerClientes clientes;
    CatalogoEnLinea vacio;

    for (auto & data : ventasData) {
        Cliente comprador;
        comprador.setNombre(data.at("nombre").get<string>());
        comprador.setCedula(data.at("cedula").get<string>());
        comprador.setPagoSuscrip(data.at("pagoSuscrip").get<double>());
        comprador.setCorreoElec(data.at("correoElec").get<string>());
        comprador.setPais(data.at("pais").get<string>());
        comprador.setCiudad(data.at("ciudad").get<string>());
        clientes.add(&comprador);
        vacio.setClientes(&clientes);
        vacio.setInStock(0);
        vacio.setTrajes(nullptr);

        Venta venta(&comprador,&vacio);
        venta.setCompradores(&clientes);
        venta.setGanacia(data.at("ganancia").get<double>());
        venta.setCodTrajeVendido(data.at("codTrajeVendido").get<string>());
        ventas.add(&venta);
    }
}

void ManagerArchivoJSON::save(const string &jsonData, const string &filename) {
    std::ofstream file (filename, std::ofstream::out);
    file << jsonData;
    file.close();
}

string ManagerArchivoJSON::read(const string &filename) {
    std::string txtContent;

    try {
        std::ifstream file (filename);
        file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string fileContent(buffer.str());
        txtContent = fileContent;
    }
    catch (std::ifstream::failure e) {
        throw std::runtime_error("Error opening file");
    }

    return txtContent;
}

ManagerVentas ManagerArchivoJSON::deserialize(const string &_data) {
    json jsonData = json::parse(_data);
    ManagerVentas ventas = jsonData;

    return ventas;
}

string ManagerArchivoJSON::serialize(ManagerVentas ventas) {
    json jsonData(ventas);
    string jsonArray = jsonData.dump();
    return jsonArray;
}
