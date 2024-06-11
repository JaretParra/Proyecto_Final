#include"../Headers/ProvedoresUsage.h"

string fileName = "../Data/Provedores.txt";

ofstream outfile;
ifstream infile;

void altaDatos(string _datos[3]){
    outfile.open(fileName);

        for(int i=0;i<=2;i++){
            outfile << _datos[i] <<"\n";
        }

    outfile << "\n";

    outfile.close();
}

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

            cout<<"Provedor Eliminado con exito."<<endl;

            outfile.close();
        }else{
            cout << "Provedor no encontrado."<<endl;
        }
    }
}


void cambiosDatos(string _nombre, string _datos[3]){
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

        cout<<"Provedore Cambiado con exito."<<endl;
    }else{
        cout<<"Provedore no encontrado."<<endl;
        cout<<"Operacion no realizada."<<endl;
    }
}


void consultaDatos(){
    string linea;

    infile.open(fileName);

    while(getline(infile,linea)){
        cout<<linea<<endl;
    }

    infile.close();
}