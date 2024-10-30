#include "Componente.h"

int idComponente = 0; // gerar numero automatico automatico para o id

Componente::Componente() {
    id = ++idComponente;
}

int Componente::getId() {
    return id;
}