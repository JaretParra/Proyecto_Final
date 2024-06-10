#include"../Headers/OfertasUsage.h"

void altaOfertas(string _datos[2]){
    outfile.open(fileName);

        for(int i=0;i<=1;i++){
            outfile << _datos[i] <<"\n";
        }

    outfile << "\n";

    outfile.close();
}

void bajaOfertas(string _fecha){
    if(_fecha!="error_not_found"){
        string dato;
        string linea;
        vector<string> temp;
        int num_line = 0;
        bool encontrado = false;

        infile.open(fileName);

        while(infile>>dato){
            num_line++;
            if(dato==_fecha){
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
                if((i<num_line)||(i>(num_line+1))){
                    outfile << temp[i] <<endl;
                }
            }

            cout<<"Fecha Eliminada con exito."<<endl;

            outfile.close();
        }else{
            cout << "Fecha no encontrada."<<endl;
        }
    }
}

void cambiosOfertas(string _fecha, string _datos[2]){
    string dato;
    string linea;
    vector<string> temp;
    int num_line = 0;
    bool encontrado = false;

    infile.open(fileName);

    while(infile>>dato){
        num_line++;
        if(dato==_fecha){
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
            if((i<num_line)||(i>(num_line+1))){
                outfile << temp[i] <<endl;
            }
        }

        for(int i=0;i<=1;i++){
            outfile << _datos[i] <<"\n";
        }
        outfile << "\n";
        
        outfile.close();

        cout<<"Fecha Cambiada con exito."<<endl;
    }else{
        cout<<"Fecha no encontrada."<<endl;
        cout<<"Operacion no realizada."<<endl;
    }
}

void consultaOfertas(){
    string linea;

    infile.open(fileName);

    while(getline(infile,linea)){
        cout<<linea<<endl;
    }

    infile.close();
}