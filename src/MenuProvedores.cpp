#include"../Headers/MenuProvedores.h"

string datos[3]={"","",""};
string nombre="";

void RegistrarProvedor(){
    system("cls");

    for(int i=0;i<=2;i++){
        datos[i] = "";
    }

    cout<<"1)Registro de Provedor."<<endl;
    cout<<"Ingresa los datos del Provedor:"<<endl;
    cout<<"Empresa: ";
    getline(cin,datos[0]);
    cout<<"Direccion: ";
    getline(cin,datos[1]);
    cout<<"Categoria: ";
    getline(cin,datos[2]);
}

string EliminarProvedor(){
    char confir='n';
    system("cls");

    cout<<"2)Eliminacion de Provedor.";
    cout<<"Ingrese el nombre del Provedor:"<<endl;
    cout<<"Provedor: ";
    getline(cin,nombre);
    cout<<"Esta seguro de continuar[y/n]: ";
    cin>>confir;
    confir = tolower(confir);

    if(confir='y'){
        return nombre;
    }else{
        return "error_not_found";
    }

}

void ModificarProvedor(){
    system("cls");
    
    cout<<"3)Modificacion de Provedor."<<endl;
    cout<<"Ingrese el nombre del Provedor:"<<endl;
    cout<<"Nombre: ";
    getline(cin,nombre);

    cout<<"\nIngresa los nuevos datos del Provedor:"<<endl;
    cout<<"Nombre: ";
    getline(cin,datos[0]);
    cout<<"Direccion ";
    getline(cin,datos[1]);
    cout<<"Categoria: ";
    getline(cin,datos[2]);
}


void MenuProvedores(){
bool flag=false;
    int opcion;

    while(flag==false){
        system("cls");
        cout<<"\tBIENVENIDO AL MODULO DE PROVEDORES"<<endl;
        cout<<"1) Registrar Provedor."<<endl;
        cout<<"2) Eliminar Provedor"<<endl;
        cout<<"3) Modificar Provedor"<<endl;
        cout<<"4) Consultar Provedor"<<endl;
        cout<<"5) salir del Modulo."<<endl;
        cout<<"Digite el numero de la opcion a realizar: ";
        cin>>opcion;

        if(opcion==1){
            RegistrarUsuario();
            altaDatos(datos);
        }
        if(opcion==2){
            bajaDatos(EliminarProvedor());
        }
        if(opcion==3){
            ModificarUsuario();
            cambiosDatos(nombre,datos);
        }
        if(opcion==4){
            consultaDatos();
        }
        if(opcion==5){
            flag==true;
        }
    }
}
