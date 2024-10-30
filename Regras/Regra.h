#ifndef TP_REGRAS_H
#define TP_REGRAS_H
#include <iostream>
#include "../Sensores/Sensor.h"
using namespace std;

class Regra {
private:
    int id;
    Sensor* sensor; //conhece os sensores
    int parametro1;

public:
    Regra(Sensor *sensor, int parametro1);
    virtual bool verificar() = 0;
    int getParametro1() const;
    Sensor *getSensor() const;
    int getId() const;
    virtual void imprimir(term::Window* window) = 0;
    virtual ~Regra();
};

#endif //TP_REGRAS_H
