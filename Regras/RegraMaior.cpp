#include "RegraMaior.h"

RegraMaior::RegraMaior(Sensor *sensor, int parametro1) : Regra(sensor, parametro1) {}

bool RegraMaior::verificar() {
    int valor = getSensor()->getLeitura();

    return valor > getParametro1();
}

void RegraMaior::imprimir(term::Window *window) {
    (*window) << "RegraMaior " << this->getId() << ", ";
    this->getSensor()->imprimirNomeID(window);
    (*window) << "\n";
}