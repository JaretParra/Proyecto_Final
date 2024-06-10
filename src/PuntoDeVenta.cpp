#include"../Headers/PuntoDeVenta.h"

// Funcion para obtener la fecha y hora actual
string obtenerFechaHora() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return string(dt);
}

// Funcion para mostrar un ticket
void mostrarTicket(const Ticket& ticket) {
    system("cls");
    cout << "\n\n\nFecha y Hora: " << obtenerFechaHora() << endl;
    cout << "Empleado: " << ticket.nombreEmpleado << endl;
    cout<<"_-_"<<endl;
    cout<<"||| \tTIENDA PARRA"<<endl;
    cout<<"=== \tLos Mejores de Mexico."<<endl;
    cout<<" "<<endl;
    cout << "-----------------------------------" << endl;
    cout << "Productos "<< endl;
    double total = 0.0;
    for (const auto& producto : ticket.productos) {
        cout  <<"Id: " << producto.id << ", Producto: " << producto.nombre << ", Precio: $" << producto.precio << ", Cantidad: X" << producto.cantidad << endl;
        total += producto.precio * producto.cantidad;
    }
    cout << "-----------------------------------" << endl;
    cout << "Total a Pagar: $" << total << endl;
    cout << "-----------------------------------" << endl;
    cout << "Forma de Pago: " << ticket.formaPago << endl;
    if (ticket.formaPago == "Efectivo") {
        cout << "Monto Recibido: $" << ticket.montoRecibido << endl;
        if (ticket.montoRecibido < ticket.total) {
            cout << "ERROR: El monto recibido es menor que el total a pagar." << endl;
        } else {
            cout << "Cambio: $" << ticket.cambio << endl;
            sw=1;
        }
    }
    cout << "-----------------------------------" << endl;
}

// Funcion para añadir un producto al ticket
void agregarProducto(Ticket& ticket, const Producto& producto) {
    ticket.productos.push_back(producto);
    system("cls");
}

// Funcion para eliminar un producto del ticket por ID
void eliminarProducto(Ticket& ticket, int idProducto) {
    ticket.productos.erase(
        remove_if(ticket.productos.begin(), ticket.productos.end(),
                  [idProducto](const Producto& producto) { return producto.id == idProducto; }),
        ticket.productos.end());
    system("cls");
}

// Funcion para cancelar toda la compra
void cancelarCompra(Ticket& ticket) {
    ticket.productos.clear();
    system("cls");
}

void PuntoDeVenta(){
    Ticket ticket;
    ticket.nombreEmpleado = "";

    int opcion;
    do {
        cout << "1. Añadir producto" << endl;
        cout << "2. Eliminar producto" << endl;
        cout << "3. Cancelar compra" << endl;
        cout << "4. Pagar y mostrar ticket" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Producto producto;
                cout << "Ingrese ID del producto: ";
                cin >> producto.id;
                cout << "Ingrese nombre del producto: ";
                cin.ignore();
                getline(cin, producto.nombre);

                cout << "Ingrese precio del producto: ";
                cin >> producto.precio;
                cout << "Ingrese cantidad del producto: ";
                cin >> producto.cantidad;

                agregarProducto(ticket, producto);
                break;
            }
            case 2: {
                int idProducto;
                cout << "Ingrese ID del producto a eliminar: ";
                cin >> idProducto;

                eliminarProducto(ticket, idProducto);
                break;
            }
            case 3: {
                cancelarCompra(ticket);
                break;
            }
            case 4: {
                int formaPago;
                cout << "Seleccione forma de pago: 1. Efectivo 2. Vales 3. Tarjeta de debito 4. Tarjeta de credito: ";
                cin >> formaPago;
                switch (formaPago)
                {
                    case 1:
                        ticket.formaPago = "Efectivo";
                        cout << "Ingrese monto recibido: $";
                        cin >> ticket.montoRecibido;

                        if (ticket.montoRecibido < ticket.total) {
                            cout << "ERROR: El monto recibido es menor que el total a pagar." << endl;
                            continue; // Volver al menu principal
                        }


                        break;

                    case 2: ticket.formaPago = "Vales"; break;
                    case 3: ticket.formaPago = "Tarjeta de debito"; break;
                    case 4: ticket.formaPago = "Tarjeta de credito"; break;
                    default: ticket.formaPago = "Desconocida"; break;
                }

                ticket.total = 0.0; // Reiniciamos el total antes de calcularlo nuevamente
                for (const auto& producto : ticket.productos)
                    ticket.total += producto.precio * producto.cantidad;


                ticket.cambio = abs(ticket.montoRecibido - ticket.total);

                mostrarTicket(ticket);
                break;
            }

            case 5:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida!" << endl;
                break;
        }
    } while (opcion != 5 && sw==0); //Si no se desea que el codigo termine al mostrar el ticket, solo se elimina el ultimo parametro en este While.
    //El bucle solo terminara si el monto dado es igual o mayor al monnto a pagar, o si el usuario selecciona salir
}