#include "RegraIgual.h"

RegraIgual::RegraIgual(Sensor *sensor, int parametro1) : Regra(sensor, parametro1){}

bool RegraIgual::verificar() {
    int valor = getSensor()->getLeitura();

    return valor = getParametro1();
}

void RegraIgual::imprimir(term::Window *window) {
    (*window) << "RegraIgual " << this->getId() << ", ";
    this->getSensor()->imprimirNomeID(window);
    (*window) << "\n";
}