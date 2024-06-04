#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

int Menu(){
    int _opcion;
    cout<<"\t BIENVENIDO AL SISTEMA DE VENTAS:"<<endl;
    cout<<"\t TIENDA PARRA"<<endl;

    cout<<"\nLos modulos son:"<<endl;
    cout<<"1) Usuarios."<<endl;
    cout<<"2) Almacen."<<endl;
    cout<<"3) punto de venta."<<endl;
    cout<<"4) Salir."<<endl;
    cout<<"Modulo al que accedera: ";
    cin>>_opcion;

    if(_opcion==1){
        return 1;
    }
    if(_opcion==2){
        return 2;
    }
    if(_opcion==3){
        return 3;
    }
    if(_opcion==4){
        return 4;
    }
}

int Modulo_Menu_Usuarios(){
    int _opcion;
    cout<<"BIENVENIDO AL MODULO DE USUARIOS :D"<<endl;
    cout<<"1) Registrar Usuario."<<endl;
    cout<<"2) Eliminar Usuario."<<endl;
    cout<<"3) Modificar Usiario."<<endl;
    cout<<"4) Consultar Usiarios."<<endl;
    cout<<"5) salir del Modulo."<<endl;
    cin>>_opcion;

    if(_opcion==1){
        return 1;
    }

}

void mercancia_almacen(string rol){ 
	

    /*
    Este modulo aun no es capaz de recibir consultas ni de ser modificado desde modulos externos , solo cuenta con la funcionalidad de crear, añadir, consultar y eliminar 
    productos de la db , al igual que el modulo de usuarios, estas acciones solo son accesibles si el rol que se le pasa a la funcion es un rol de usuario.

    para la db se usa un vector bidimensional
    
    */
	int accion , newCant,status = 0 , elec;
	string originalProducto, newName,newPasword,newProveedor, proveedor,deleteItem;
	double newPrice , price;
	vector<vector<string>>productos;
	productos.push_back({"manzana", to_string(90), to_string(13.7),"juan" });
	
	
	if(rol == "admin"){
	    do{
		    cout<<"Ingresa la accion que deseas realizar:" <<endl;
            cout<<"1)consultar."<<endl;
            cout<<"2)modificar un registro."<<endl;
            cout<<"3)anadir."<<endl;
            cout<<"4)eliminar registro.";
            cout<<"5)salir."<<endl;
            cin >> accion;
            
            switch (accion) {
                case 1: // Consulta
                    cout <<" --------------------- "<<endl;
                    cout <<" | Tabla de mercancia |"<<endl;
                    cout <<" --------------------- "<<endl;
                    
                    for(int i = 0; i < productos.size(); i++) {
            	        cout << "Producto: " << productos[i][0] << " Cantidad: " << productos[i][1] << " Precio: " << productos[i][2] << " Proveedor: " << productos[i][3] <<endl;
                        cout << " "<<endl;
                    }
                    break;
                
                case 2: // Modificar registro
                   cout << "Que producto desea modificar" << endl;
                   cin >> originalProducto;
                
                    for(int i = 0; i < productos.size(); i++) {
                        if (productos[i][0] == originalProducto) {
                            cout << "Ingresa el nuevo nombre del producto: ";
                            cin >> newName;
                            cout << "Ingresa la cantidad: ";
                            cin >> newCant;
                            cout << "Ingresa el precio: ";
                            cin >> newPrice;
                            cout << "Ingresa el proveedor: ";
                            cin >> newProveedor;
                    
                            productos[i][0] = newName;
                            productos[i][1] = to_string(newCant);
                            productos[i][2] = to_string(newPrice);
                            productos[i][3] = newProveedor;
                    
                            cout << "\n Los cambios fueron: " << productos[i][0] << " , " << productos[i][1] << " , "<< productos[i][2]<< " , " << productos[i][3] <<endl;
                            status=1;
                            break;
                        }
                    }

                    if (status == 0) { // Se verifica si el usuario no se encontró durante la modificación
                        cout << "El producto no existe." << endl;
                    }
                break;

                case 3: // Añadir 
                    cout << "Ingresa el nombre del nuevo producto: ";
                    cin >> newName;
                    cout << "Ingresa la cantidad: ";
                    cin >> newCant;
                    cout << "Ingresa el precio por unidad: ";
                    cin >> price;
                    cout << "Ingresa el proveedor: ";
                    cin >>newProveedor;
            
                    productos.push_back({newName,to_string(newCant),to_string(price),newProveedor});
                break;
        
                char confirmar ;
        
                case 4: // Borrar
                    cout << "Ingresa el nombre del producto a borrar: ";
                    cin >> deleteItem;
                    cout << ">Estas seguro? [y/n] ";
                    cin >> confirmar;
            
                    if(confirmar == 'n'){
            	    cout << "Proceso cancelado...";
            	    break;
                }
            

                for (auto it = productos.begin(); it != productos.end(); ++it) {
                    if ((*it)[0] == deleteItem) {
                    it = productos.erase(it);
                    --it; // Se decrementa el iterador para no omitir el siguiente elemento
                    cout << "Producto borrado exitosamente." << endl;
                    status = 1;
                    break; 
                } else{
                	cout <<"El producto no existe"<<endl;
				}
            }

           
            break;
            
            case 5:
            	cout << ">Seguro que desea salir? [y/n]"<<endl;
            	cin >> confirmar;
            	if(confirmar == 'y'){
            	elec=0;	
            	break;
				}
            	cout << "Operacion cancelada..."<<endl;
            	break;

        default:
            cout << "Opción inválida." << endl;
    }
     
    
		}while(elec!=0);
}else{
		cout << "No puedes ingresar a este modulo" <<endl;
	}
	
	
	
	
}


void user(){ //modulo de usuarios
/*
Este modulo solo permite el acceso a los usuarios de tipo administrador.

  Aun presenta algunos problemas:
   Si el usuario que intenta iniciar sesion , no se encuentra registrado en la bd de usuarios o si este no tienen el rol de administrador, el programa se cierra en       automatico, no he logrado encontrar una solucion.

para la db se usa un vector bidimensional
*/

	
	string username,pasword , originalUser , superRol,newName, newPasword,deleteUser , serach_user, rol , newRol;
	int elec = 1 , stat = 1;
	int status = 0 , accion;
	
		vector<vector<string>>usuarios;
		usuarios.push_back({"admin123","a1234","admin"});//credenciales del usuario administrador


		
		while(stat == 1){ //inicio de sesion
		
		cout << "Inicio de sesion" << endl;
		cout <<"Inresa tu nombre de usuario: " ;
		cin >> username;
		cout << "\nIngresa tu contrasena: ";
		cin >> pasword;
		cout << " " << endl;
		
		for (int i = 0; i < 5; i++) { //autenticacion
                             if (usuarios[i][0] == username) {
                             	
                                if(usuarios[i][1] == pasword){
                                	if(usuarios[i][2] == "admin"){
                                		cout << "Bienvenido " << username << endl;
                                		superRol = "admin";
                                		stat = 0;
                                		break;
									} else {
										cout << username << " No tiene permitido el ingreso a este modulo" << endl;
										
									}
								} 
								                                                         
                        }
                    }
          }
		
		
		
		do{
		
                    cout << "Ingresa la accion que deseas realizar." <<endl;
                    cout << "[1]consultar , [2]modificar un registro, [3]anadir, [4]eliminar registro , [5]salir"<<endl;
                    cin >> accion;
			
		switch (accion) {
        case 1: // Consulta
        cout <<" --------------------- "<<endl;
        cout <<" | Tabla de usuarios |"<<endl;
        cout <<" --------------------- "<<endl;
            for (int i = 0; i < usuarios.size(); i++) {
            	
                cout << "Usuario: " << usuarios[i][0] << " Contrasena: " << usuarios[i][1] << " Rol: " << usuarios[i][2] <<endl;
               cout << ""<<endl;
                
            }
            break;

        case 2: // Modificar registro
       
            cout << "Que usuario deseas modificar?" << endl;
            cin >> originalUser;

            for (int i = 0; i < usuarios.size(); i++) {
                if (usuarios[i][0] == originalUser) {
                    cout << "Ingresa el nuevo usuario: ";
                    cin >> newName;
                    cout << "Ingresa la nueva contrasena: ";
                    cin >> newPasword;
                    cout << "Ingresa la nueva contrasena: ";
                    cin >> newRol;

                    usuarios[i][0] = newName;
                    usuarios[i][1] = newPasword;
                    usuarios[i][1] = newRol;
                    cout << "\nEl nuevo usuario y contrasena son: " << usuarios[i][0] << " , " << usuarios[i][1] << " , " << newRol << endl;
                    break;
                }
            }

            if (status == 0) { // Se verifica si el usuario no se encontró durante la modificación
                cout << "El usuario a modificar no existe." << endl;
            }
            break;

        case 3: // Añadir 
            cout << "Ingresa el nombre del nuevo usuario: ";
            cin >> newName;
            cout << "Ingresa la nueva contrasena: ";
            cin >> newPasword;
            cout << "Ingresa el rol del usuario: ";
            cin >> rol;
            
            usuarios.push_back({newName,newPasword,rol});
            
            break;
            break;
            
            
            char confirmar ;
        case 4: // Borrar
            cout << "Ingresa el nombre de usuario a borrar: ";
            cin >> deleteUser;
            cout << ">Estas seguro? [y/n] ";
            cin >> confirmar;
            
            if(confirmar == 'n'){
            	cout << "Proceso cancelado...";
            	break;
			}
            

            for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
                if ((*it)[0] == deleteUser) {
                    it = usuarios.erase(it);
                    --it; // Se decrementa el iterador para no omitir el siguiente elemento
                    cout << "Usuario borrado exitosamente." << endl;
                    status = 1;
                    break; 
                } else{
                	cout <<"El usuario no existe"<<endl;
				}
            }

           
            break;
            case 5:
            	cout << ">Seguro que desea salir? [y/n]"<<endl;
            	cin >> confirmar;
            	if(confirmar == 'y'){
            	elec=0;	
            	break;
				}
            	cout << "Operacion cancelada..."<<endl;
            	break;

        default:
            cout << "Opción inválida." << endl;
    }
}while(elec!=0);
    
				}
			


int main(){
    int opcion;
    
    opcion = Menu();

    system("cls");
    if(opcion==1){
        Modulo_Menu_Usuarios();
    }

    string rol = "admin";
    mercancia_almacen(rol);
    user();

    return 0;
}