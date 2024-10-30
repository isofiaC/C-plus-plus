#ifndef TP_ZONA_H
#define TP_ZONA_H
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "Sensores/Sensor.h"
#include "Aparelhos/Aparelho.h"
#include "Regras/Processador.h"
#include "Terminal.h"
#include "Propriedades/Propriedade.h"
#include "Propriedades/Temperatura.h"
#include "Propriedades/Luz.h"
#include "Propriedades/Radiacao.h"
#include "Propriedades/Vibracao.h"
#include "Propriedades/Humidade.h"
#include "Propriedades/Fumo.h"
#include "Propriedades/Som.h"

using namespace std;

class Zona{
    int id;
    term::Window* window;
    map<string, Propriedade*> propriedades; //tem propriedades
    vector<Sensor*> sensores; //tem sensores
    vector<ProcessadorRegras*> processadores; //tem processadores
    vector<Aparelho*> aparelhos; //tem aparelhos

public:
    Zona(term::Window* window);
    void add(Sensor* sensor);
    void add(ProcessadorRegras* processador);
    void add(Aparelho* aparelho);
    Propriedade* getPropriedade(string chave);
    Sensor* getSensor(int id);
    ProcessadorRegras* getProcessadorRegras(int id);
    Aparelho* getAparelho(int id);
    void removeSensor(int id);
    void removeProcessadorRegras(int id);
    void removeAparelho(int id);
    void processarInstante();
    void desenhaZona();
    int getId() const;
    void imprimir(term::Window* window);
    void imprimirComponentes(term::Window* window);
    void imprimirPropriedades(term::Window* window);
    ~Zona();
};

#endif //TP_ZONA_H
