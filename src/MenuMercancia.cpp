#include"../Headers/StockUsage.h"



void MenuMercancia(){

    bool flag=false;
    int opcion;
while(flag==false){
system("cls");

    cout << "\tBIENVENIDO AL MENU DE MERCANCIA"<<endl;
    cout<<"1) Registrar Usuario."<<endl;
    cout<<"2) Eliminar Usuario."<<endl;
    cout<<"3) Modificar Usuarios."<<endl;
    cout<<"4) Consultar Usuarios."<<endl;
    cout<<"5) salir del Modulo."<<endl;
    cout<<"Digite el numero de la opcion a realizar: ";
    cin>>opcion;

    if(opcion==1){
          altaStock();
        }
        if(opcion==2){
            bajaStock();
        }
        if(opcion==3){
            cambiosStock();
            
        }
        if(opcion==4){
            consultaStock();
        }
        if(opcion==5){
            flag==true;
        }
}
    
}