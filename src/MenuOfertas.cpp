#include"../Headers/MenuOfertas.h"

string datos[2]={"","1"};
string fecha="";

void RegistrarOfertas(){
    system("cls");

    for(int i=0;i<=1;i++){
        datos[i] = "";
    }

    cout<<"1)Registro de Ofertas."<<endl;
    cout<<"Ingresa los datos de la Oferta:"<<endl;
    cout<<"Fecha: ";
    getline(cin,datos[0]);
    cout<<"Descuento: ";
    getline(cin,datos[1]);
}

string EliminarOfertas(){
    char confir='n';
    system("cls");

    cout<<"2)Eliminacion de Ofertas.";
    cout<<"Ingrese la fecha de la Oferta:"<<endl;
    cout<<"Fecha: ";
    getline(cin,fecha);
    cout<<"Esta seguro de continuar[y/n]: ";
    cin>>confir;
    confir = tolower(confir);

    if(confir='y'){
        return fecha;
    }else{
        return "error_not_found";
    }

}

void ModificarOfertas(){
    system("cls");
    
    cout<<"3)Modificacion de Oferta."<<endl;
    cout<<"Ingrese la fecha de la oferta:"<<endl;
    cout<<"Fecha: ";
    getline(cin,fecha);

    cout<<"\nIngresa los nuevos datos de la Oferta:"<<endl;
    cout<<"Fecha: ";
    getline(cin,datos[0]);
    cout<<"Descuento: ";
    getline(cin,datos[1]);
}

void MenuOfertas(){
    bool flag=false;
    int opcion;

    while(flag==false){
        system("cls");
        cout<<"\tBIENVENIDO AL MODULO DE OFERTAS :D"<<endl;
        cout<<"1) Registrar Ofertas."<<endl;
        cout<<"2) Eliminar Ofertas."<<endl;
        cout<<"3) Modificar Ofertass."<<endl;
        cout<<"4) Consultar Ofertass."<<endl;
        cout<<"5) salir del Modulo."<<endl;
        cout<<"Digite el numero de la opcion a realizar: ";
        cin>>opcion;

        if(opcion==1){
            RegistrarOfertas();
            altaOfertas(datos);
        }
        if(opcion==2){
            bajaOfertas(EliminarOfertas());
        }
        if(opcion==3){
            ModificarOfertas();
            cambiosOfertas(fecha,datos);
        }
        if(opcion==4){
            consultaOfertas();
        }
        if(opcion==5){
            flag==true;
        }
    }
}