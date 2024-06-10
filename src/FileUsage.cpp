#include"../Headers/FileUsage.h"

/*Ingresa usuarios*/
void altaDatos(string _datos[3]){
    outfile.open(fileName);

        for(int i=0;i<=2;i++){
            outfile << _datos[i] <<"\n";
        }

    outfile << "\n";

    outfile.close();
}

/*Elimina Usuarios*/
void bajaDatos(string _nombre){
    if(_nombre!="error_not_found"){
        string dato;
        string linea;
        vector<string> temp;
        int num_line = 0;
        bool encontrado = false;

        infile.open(fileName);

        while(infile>>dato){
            num_line++;
            if(dato==_nombre){
                encontrado = true;
                break;
            }
        }
    
        while(getline(infile,linea)){
            temp.push_back(linea);
        }

        infile.close();

        if(encontrado){
            outfile.open(fileName);

            for(int i=0;i<temp.size();i++){
                if((i<num_line)||(i>(num_line+3))){
                    outfile << temp[i] <<endl;
                }
            }

            cout<<"Usuario Eliminado con exito."<<endl;

            outfile.close();
        }else{
            cout << "Usuario no encontrado."<<endl;
        }
    }
}

/*Busca un usuario y lo cambia*/
void cambiosdatos(string _nombre, string _datos[3]){
    string dato;
    string linea;
    vector<string> temp;
    int num_line = 0;
    bool encontrado = false;

    infile.open(fileName);

    while(infile>>dato){
        num_line++;
        if(dato==_nombre){
            encontrado = true;
            break;
        }
    }
    
    while(getline(infile,linea)){
        temp.push_back(linea);
    }

    infile.close();

    if(encontrado){
        outfile.open(fileName);

        for(int i=0;i<temp.size();i++){
            if((i<num_line)||(i>(num_line+3))){
                outfile << temp[i] <<endl;
            }
        }

        for(int i=0;i<=2;i++){
            outfile << _datos[i] <<"\n";
        }
        outfile << "\n";
        
        outfile.close();

        cout<<"Usuario Cambiado con exito."<<endl;
    }else{
        cout<<"Usuario no encontrado."<<endl;
        cout<<"Operacion no realizada."<<endl;
    }
}

/*Muestra todos los usuarios*/
void consultaDatos(){
    string linea;

    infile.open(fileName);

    while(getline(infile,linea)){
        cout<<linea<<endl;
    }

    infile.close();
}

string sesion(){
    string guess, passwd;
    string dato;
    string linea;
    int num_line = 0;
    int i=0;
    bool encontrado = false;

    system("cls");
    cout<<"_-_"<<endl;
    cout<<"|||"<<endl;
    cout<<"==="<<endl;

    cout<<"Ingrese su usuario: ";
    getline(cin,guess);

    infile.open(fileName);
    while(infile>>dato){
        num_line++;
        if(dato==guess){
            encontrado = true;
            break;
        }
    }

    if(encontrado){
        cout<<"Ingrese su contraseña: ";
        getline(cin,passwd);

        while(infile>>linea){
            i++;
            if(i==(num_line+1)){
                if(passwd==linea){
                    while(infile>>linea){
                        if(linea=="admin"){
                            infile.close();
                            return "admin";
                        }else{
                            infile.close();
                            return "cajero";
                        }
                    }
                }
            }
        }
    }else{
        infile.close();
        return "not_found";
    }
}