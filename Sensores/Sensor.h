#ifndef TP_SENSOR_H
#define TP_SENSOR_H
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "../Propriedades/Propriedade.h"
#include "../Componente.h"
#include "../Terminal.h"

using namespace std;

class Sensor: public Componente{
private:
    Propriedade* propriedade; //conhece propriedades

public:
    Sensor(Propriedade* propriedade);
    int getLeitura();
    virtual string getLetra() = 0;
    virtual void imprimir(term::Window* window) = 0;
    virtual void imprimirNomeID(term::Window* window) = 0;
    virtual ~Sensor();
};

#endif //TP_SENSOR_H
