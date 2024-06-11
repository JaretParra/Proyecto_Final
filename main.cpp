#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

#include"Headers/MenuMercancia.h"
#include"Headers/MenuOfertas.h"
#include"Headers/MenuProvedores.h"
#include"Headers/MenuUsuarios.h"
#include"Headers/FileUsage.h"
#include"Headers/PuntoDeVenta.h"

using namespace std;

int MenuAdmin(){
    int _opcion=3;

    system("cls");
    cout<<"_-_"<<endl;
    cout<<"||| \tBIENVENIDO AL SISTEMA DE VENTAS:"<<endl;
    cout<<"=== \tTIENDA PARRA"<<endl;
    
    cout<<"\nLos modulos son:"<<endl;
    cout<<"1) Usuarios."<<endl;
    cout<<"2) Almacen."<<endl;
    cout<<"3) Salir."<<endl;
    cout<<"Modulo al que accedera: ";
    cin>>_opcion;
    return _opcion;
}

void ModuloAlmacen(){
    int _opcion=4;
    bool flag_a = true;
    while(flag_a){
        system("cls");
        cout<<"BIENVENIDO AL MODULO ALMACEN."<<endl;
        cout<<"Los modulos son:"<<endl;
        cout<<"1) Mercancia."<<endl;
        cout<<"2) Provedores."<<endl;
        cout<<"3) Ofertas."<<endl;
        cout<<"4) Salir"<<endl;
        cout<<"Modulo al que accedera: ";
        cin>>_opcion;

        if(_opcion==1){
            MenuMercancia(); 
        }
        if(_opcion==2){
            MenuProvedores();
        }
        if(_opcion==3){
            MenuOfertas();
        }
        if(_opcion==4){
            flag_a == false;
        }
    }
}

int main(){
    int opcion;
    bool acabar=false;
    string rol = "not_found";

    while(!acabar){
        rol = sesion();

        if(rol=="admin"){
            opcion = MenuAdmin();

            if(opcion=1){
                MenuUsuarios();
            }
            if(opcion=2){
                ModuloAlmacen();
            }
            if(opcion=3){
                acabar=true;
            }
        }

        if(rol=="cajero"){
            PuntoDeVenta();
            acabar=true;
        }
    }

    return 0;
}