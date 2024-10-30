#include "Regra.h"

int idRegra = 0; // gerar numero automatico automatico para o id

Regra::Regra(Sensor *sensor, int parametro1) : sensor(sensor), parametro1(parametro1) {
    id = ++idRegra;
}

int Regra::getParametro1() const {
    return parametro1;
}

Sensor *Regra::getSensor() const {
    return sensor;
}

int Regra::getId() const {
    return id;
}

Regra::~Regra() {

}
