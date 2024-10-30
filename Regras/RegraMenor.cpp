#include "RegraMenor.h"

RegraMenor::RegraMenor(Sensor *sensor, int parametro1) : Regra(sensor, parametro1) {}

bool RegraMenor::verificar() {
    int valor = getSensor()->getLeitura();

    return valor < getParametro1();
}

void RegraMenor::imprimir(term::Window *window) {
    (*window) << "RegraMenor " << this->getId() << ", ";
    this->getSensor()->imprimirNomeID(window);
    (*window) << "\n";
}