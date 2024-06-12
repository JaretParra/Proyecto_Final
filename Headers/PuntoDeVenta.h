#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <fstream>

#include"../Headers/StockUsage.h"

int sw=0;

using namespace std;

// Estructura para representar un producto
struct Producto {
    int id;
    string nombre;
    double precio;
    int cantidad;
};

// Estructura para representar un ticket
struct Ticket {
    time_t fechaHora;
    string nombreEmpleado;
    vector<Producto> productos;
    string formaPago;
    double total; // Suma total a pagar
    double montoRecibido; // Monto recibido en caso de pago en efectivo
    double cambio; // Cambio a devolver al cliente en caso de pago en efectivo
};

string obtenerFechaHora();

void mostrarTicket(const Ticket& ticket);

void agregarProducto(Ticket& ticket, const Producto& producto);

void eliminarProducto(Ticket& ticket, int idProducto);

void cancelarCompra(Ticket& ticket);

void PuntoDeVenta();