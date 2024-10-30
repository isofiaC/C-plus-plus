#ifndef TP2_REFRIGERADOR_H
#define TP2_REFRIGERADOR_H
#include "Aparelho.h"
#include "../Propriedades/Temperatura.h"
#include "../Propriedades/Som.h"

class Refrigerador: public Aparelho {
private:
    Temperatura* temperatura;
    Som* som;

public:
    Refrigerador(Temperatura *temperatura, Som* som);
    void executarComando(string comando) override;
    string getLetra() override;
    void processarInstante() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_REFRIGERADOR_H
