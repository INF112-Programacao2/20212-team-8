#ifndef TPFINAL_CONTA_H
#define TPFINAL_CONTA_H
#include <string>

class Conta {
private:

    std::string _status;

public:

    Conta();
    void temcadastro();
    void registro();
    void pedido();
    void contapadrao();
    void contapremium();
    void alterardados();

}

#endif