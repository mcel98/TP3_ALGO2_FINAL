//
// Created by dn-01 on 01/07/18.
//

#ifndef SOLUCION_PROGRAMA_H
#define SOLUCION_PROGRAMA_H

#include <vector>
#include <tuple>
#include <string>
#include <list>
#include "Instruccion.hpp"
using namespace std;




class Programa{
private:
    struct Rutina;

public:
    Programa();
    ~Programa();
    void AgregarAunNoExiste(Instruccion,int);
    void BuscarEnAunNoExiste(Id, int);
    void AgInstruccion(string,Instruccion);
    vector<string> Rutinas() const;
    int longitud(string ) const ;
    Instruccion Instrucciones(string , int) const;
    list <tuple<string,vector< tuple<Instruccion,int> >  ,int> > ParaCalculadora();




private:
    struct Rutina{

        /* inicia rutina vacia */
        Rutina(Id r, vector<tuple<Instruccion,int>> i):Rut(r),instRut(i),tamRut(){}
        /* *************************** */
        Id Rut;
        vector<tuple<Instruccion,int>> instRut;
        int tamRut;


    };
    vector<Rutina*> ListaProg;
    vector<tuple<Id,list<tuple<Instruccion,int>*>>> AunNoExistentes;
    int cantRutina;


};

#endif //SOLUCION_PROGRAMA_H
