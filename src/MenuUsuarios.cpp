#include"../Headers/MenuUsuarios.h"

string datos[3]={"","","cajero"};
string nombre="";

void RegistrarUsuario(){
    system("cls");

    for(int i=0;i<=2;i++){
        datos[i] = "";
    }

    cout<<"1)Registro de Usuario."<<endl;
    cout<<"Ingresa los datos del Usuario:"<<endl;
    cout<<"Nombre: ";
    getline(cin,datos[0]);
    cout<<"Contraseña: ";
    getline(cin,datos[1]);
    cout<<"Rol: ";
    getline(cin,datos[2]);
}

void EliminarUsuario(){
    system("cls");

    cout<<"2)Eliminacion de Usuario.";
    cout<<"Ingrese el nombre del Usuario:"<<endl;
    cout<<"Nombre: ";
    getline(cin,nombre);
    
}

void MenuUsuarios(){
    bool flag=false;
    int opcion;

    while(flag==false){
        system("cls");
        cout<<"\tBIENVENIDO AL MODULO DE USUARIOS :D"<<endl;
        cout<<"1) Registrar Usuario."<<endl;
        cout<<"2) Eliminar Usuario."<<endl;
        cout<<"3) Modificar Usuarios."<<endl;
        cout<<"4) Consultar Usuarios."<<endl;
        cout<<"5) salir del Modulo."<<endl;
        cout<<"Digite el numero de la opcion a realizar: ";
        cin>>opcion;

        if(opcion==1){
            RegistrarUsuario();
            altaDatos(datos);
        }
        if(opcion==2){}
        if(opcion==3){}
        if(opcion==4){}
        if(opcion==5){}
    }
}