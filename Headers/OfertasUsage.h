#ifndef OFERTASUSAGE_H
#define OFERTASUSAGE_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<array>
#include<ctime>

using namespace std;

void altaOfertas(string _datos[2]);

void bajaOfertas(string _fecha);

void cambiosOfertas(string _fecha, string _datos[2]);

void consultaOfertas();

#endif