#include "Aquecedor.h"

Aquecedor::Aquecedor(Temperatura *temperatura, Som* som) : temperatura(temperatura), som(som), Aparelho() {}

void Aquecedor::executarComando(string comando) {
    this->setUltimoComando(comando);

    if (comando == "liga") {
        if (!isLigado()) {
            setLigado(true);
            setInstante(0);
            som->modificaValor(5);
        }
    } else if (comando == "desliga") {
        if (isLigado()) {
            setLigado(false);
            som->modificaValor(-5);
        }
    }
    //Possivel adicionar else com erro
}

string Aquecedor::getLetra() {
    if (isLigado()) {
        return "A";
    }

    return "a";
}

void Aquecedor::processarInstante() {
    if (isLigado()) {
        setInstante(getInstante() + 1);

        if (getInstante() == 3) {
            setInstante(0);

            int temperaturaAtual = temperatura->getValor();

            if (temperaturaAtual + 1 <= maxTemperatura) {
                temperatura->modificaValor(1);
            }
        }
    }
}

void Aquecedor::imprimir(term::Window* window) {
    (*window) << "Tipo: A, ID: " << this->getId() << ", Aquecedor, U_CMD: " << this->getUltimoComando() << "\n";
}