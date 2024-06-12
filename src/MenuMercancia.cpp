#include"../Headers/MenuMercancia.h"

string datos[4]={"#100","","$0","X0"};
string nombre="";

void RegistrarMercancia(){
    system("cls");

    for(int i=0;i<=3;i++){
        datos[i] = "";
    }

    cout<<"1)Registro de Mercancia."<<endl;
    cout<<"Ingresa los datos de la Mercancia:"<<endl;
    cout<<"Id: ";
    getline(cin,datos[0]);
    cout<<"Nombre: ";
    getline(cin,datos[1]);
    cout<<"Precio: ";
    getline(cin,datos[2]);
    cout<<"Cantidad: ";
    getline(cin,datos[3]);
}

string EliminarMercancia(){
    char confir='n';
    system("cls");

    cout<<"2)Eliminacion de Mercancia.";
    cout<<"Ingrese el nombre de la Mercancia:"<<endl;
    cout<<"Nombre: ";
    getline(cin,nombre);
    cout<<"Esta seguro de continuar[y/n]: ";
    cin>>confir;
    confir = tolower(confir);

    if(confir=='y'){
        return nombre;
    }else{
        return "error_not_found";
    }
}

void ModificarMercancia(){
    system("cls");
    
    cout<<"3)Modificacion de Mercancia."<<endl;
    cout<<"Ingrese el nombre de la Mercancia:"<<endl;
    cout<<"Nombre: ";
    getline(cin,nombre);

    cout<<"\nIngresa los nuevos datos de la Mercancia:"<<endl;
    cout<<"Id: #";
    getline(cin,datos[0]);
    cout<<"Nombre: ";
    getline(cin,datos[1]);
    cout<<"Precio: $";
    getline(cin,datos[2]);
    cout<<"Cantidad: X";
    getline(cin,datos[3]);
}

void MenuMercancia(){
    bool flag=false;
    int opcion;
    
    while(flag==false){
        system("cls");

        cout << "\tBIENVENIDO AL MENU DE MERCANCIA."<<endl;
        cout<<"1) Ingresar Mercancia."<<endl;
        cout<<"2) Eliminar Mercancia."<<endl;
        cout<<"3) Modificar Mercancia."<<endl;
        cout<<"4) Consultar Mercancia."<<endl;
        cout<<"5) salir del Modulo."<<endl;
        cout<<"Digite el numero de la opcion a realizar: ";
        cin>>opcion;

        if(opcion==1){
            RegistrarMercancia();
            altaStock(datos);
        }
        if(opcion==2){
            bajaStock(EliminarMercancia());
        }
        if(opcion==3){
            ModificarMercancia();
            cambiosStock(nombre,datos);
        }
        if(opcion==4){
            consultaStock();
        }
        if(opcion==5){
            flag==true;
        }
    }
}