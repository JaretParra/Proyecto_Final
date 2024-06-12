#ifndef FILEUSAGE_H
#define FILEUSAGE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<array>

using namespace std;

void altaDatos(string _datos[3]);

void bajaDatos(string _nombre);

/// @brief 
/// @param _nombre 
/// @param _datos 
void cambiosDatos(string _nombre, string _datos[3]);

void consultaDatos();

string sesion();

#endif