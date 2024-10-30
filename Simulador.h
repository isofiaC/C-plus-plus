#ifndef TP2_SIMULADOR_H
#define TP2_SIMULADOR_H
#include <fstream>
#include "Habitacao.h"
#include "Terminal.h"
#include "Aparelhos/Aquecedor.h"
#include "Aparelhos/Aspersor.h"
#include "Sensores/SensorTemperatura.h"
#include "Aparelhos/Refrigerador.h"
#include "Aparelhos/Lampada.h"
#include "Sensores/SensorMovimento.h"
#include "Sensores/SensorLuminosidade.h"
#include "Sensores/SensorRadiacao.h"
#include "Sensores/SensorHumidade.h"
#include "Sensores/SensorSom.h"
#include "Sensores/SensorFumo.h"
#include "Regras/RegraIgual.h"
#include "Regras/RegraMenor.h"
#include "Regras/RegraMaior.h"
#include "Regras/RegraEntre.h"
#include "Regras/RegraFora.h"

using namespace term;
using namespace std;

class Simulador {
private:
    Habitacao* habitacao;

public:
    Simulador();
    void executar();
    void interpretarComando(const string &comando, Window &win_info,
                            Window &win_cmd, Window windows[4][4], bool fromFile);
    int valida_args(const string &linha);
    ~Simulador();
};


#endif //TP2_SIMULADOR_H
