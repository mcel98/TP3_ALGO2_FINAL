//
// Created by dn-01 on 01/07/18.
//
#ifndef CALCULADORA_H_
#define CALCULADORA_H_

#include "Programa.hpp"
#include "Ventana.h"
#include "diccTrie.hpp"
#include <tuple>

using namespace std;

typedef string rut;
typedef string Variable;
typedef int instante;

class Calculadora{
public:
    void nuevaCalculadora(Programa ,rut, int);

    ~Calculadora();

    bool ejecutando();

    void ejecutarUnPaso();

    void asignarVariable(Variable, int);

    int valorHistoricoVariable(Variable,instante);

    int valorActualVariable(Variable);

    int IndiceInstruccionActual();

    instante InstanteActual();

    rut rutinaActual();

    stack<int> Pila();

private:
    instante momentoActual;
    int capacidadVentana;
    int indiceRutinaActual;
    int indiceInstruccion;
    stack<int> pila;
    vector<tuple<rut,std::list<tuple<Instruccion,int,Ventana<tuple<int,int>>*>>,int>> progCalc;
    list<tuple<int ,Variable, instante>> asignaciones;
    int cantidadAsignaciones;
    dicc_trie<Ventana<tuple<int,int>>> varVentana;
    dicc_trie<int> varAsignacionActual;
    tuple<Programa, rut> inicio;
    list<std::tuple<Instruccion, int, Ventana<std::tuple<int, int>> *>>::iterator itaInstruccion;
};


#endif //SOLUCION_CALCULADORA_H
