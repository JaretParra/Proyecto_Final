#include"../Headers/StockUsage.h"

void altaStock(string _datos[4]){
    outfile.open(fileName);

        for(int i=0;i<=3;i++){
            outfile << _datos[i] <<"\n";
        }

    outfile << "\n";

    outfile.close();
}

void bajaStock(string _nombre){
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
                if((i<num_line)||(i>(num_line+4))){
                    outfile << temp[i] <<endl;
                }
            }

            cout<<"Producto Eliminado con exito."<<endl;

            outfile.close();
        }else{
            cout << "Producto no encontrado."<<endl;
        }
    }
}

void cambiosStock(string _nombre, string _datos[4]){
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
            if((i<num_line)||(i>(num_line+4))){
                outfile << temp[i] <<endl;
            }
        }

        for(int i=0;i<=3;i++){
            outfile << _datos[i] <<"\n";
        }
        outfile << "\n";
        
        outfile.close();

        cout<<"Producto Cambiado con exito."<<endl;
    }else{
        cout<<"Producto no encontrado."<<endl;
        cout<<"Operacion no realizada."<<endl;
    }
}

void consultaStock(){
    string linea;

    infile.open(fileName);

    while(getline(infile,linea)){
        cout<<linea<<endl;
    }

    infile.close();
}
