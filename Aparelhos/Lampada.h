#ifndef TP2_LAMPADA_H
#define TP2_LAMPADA_H
#include "Aparelho.h"
#include "../Propriedades/Luz.h"

class Lampada: public Aparelho {
private:
    Luz* luz;

public:
    Lampada(Luz* luz);
    void executarComando(string comando) override;
    string getLetra() override;
    void processarInstante() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_LAMPADA_H
