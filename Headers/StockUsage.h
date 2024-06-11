#ifndef STOCKUSAGE_H
#define STOCKUSAGE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<array>

using namespace std;

void altaStock(string _datos[4]);

void bajaStock(string _nombre);

void cambiosStock(string _nombre, string _datos[4]);

void consultaStock();

#endif