#ifndef TP2_AQUECEDOR_H
#define TP2_AQUECEDOR_H
#include "Aparelho.h"
#include "../Propriedades/Temperatura.h"
#include "../Propriedades/Som.h"

class Aquecedor: public Aparelho {
private:
    Temperatura* temperatura;
    Som* som;
    static const int maxTemperatura = 50;

public:
    Aquecedor(Temperatura *temperatura, Som* som);
    void executarComando(string comando) override;
    string getLetra() override;
    void processarInstante() override;
    void imprimir(term::Window* window) override;
};


#endif //TP2_AQUECEDOR_H
