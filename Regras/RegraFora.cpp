#include "RegraFora.h"

RegraFora::RegraFora(Sensor *sensor, int parametro1, int parametro2) : Regra(sensor, parametro1),
                                                                         parametro2(parametro2) {}

bool RegraFora::verificar() {
    int valor = getSensor()->getLeitura();

    return valor < getParametro1() && valor > parametro2;
}

void RegraFora::imprimir(term::Window *window) {
    (*window) << "RegraFora " << this->getId() << ", ";
    this->getSensor()->imprimirNomeID(window);
    (*window) << "\n";
}