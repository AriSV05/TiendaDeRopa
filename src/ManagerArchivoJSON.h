
#ifndef II_MANAGERARCHIVOJSON_H
#define II_MANAGERARCHIVOJSON_H
#include "ManagerVentas.h"
#include <fstream>

#include <../lib/nlohmann/json.hpp>

using nlohmann::json;

class ManagerArchivoJSON {

private:
    ManagerVentas* ventasArchivo;

public:

    static void save(const string& jsonData, const std::string &filename);
    static string read(const std::string &filename);
    static ManagerVentas deserialize(const string& _data);
    static string serialize(ManagerVentas);
};


#endif //II_MANAGERARCHIVOJSON_H
