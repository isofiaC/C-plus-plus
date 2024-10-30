#include "Refrigerador.h"

Refrigerador::Refrigerador(Temperatura *temperatura, Som *som) : temperatura(temperatura), som(som), Aparelho() {}

void Refrigerador::executarComando(string comando) {
    this->setUltimoComando(comando);

    if (comando == "liga") {
        if (!isLigado()) {
            setLigado(true);
            setInstante(0);
            som->modificaValor(20);
        }
    } else if (comando == "desliga") {
        if (isLigado()) {
            setLigado(false);
            som->modificaValor(-20);
        }
    }
    //Possivel adicionar else com erro
}

string Refrigerador::getLetra() {
    if (isLigado()) {
        return "R";
    }

    return "r";
}

void Refrigerador::processarInstante() {
    if (isLigado()) {
        setInstante(getInstante() + 1);

        if (getInstante() == 3) {
            setInstante(0);

            temperatura->modificaValor(-1);
        }
    }
}

void Refrigerador::imprimir(term::Window* window) {
    (*window) << "Tipo: A, ID: " << this->getId() << ", Refrigerador, U_CMD: " << this->getUltimoComando() << "\n";
}