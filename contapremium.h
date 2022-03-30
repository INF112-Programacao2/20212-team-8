#ifndef TPFINAL_CONTA_PREMIUM_H
#define TPFINAL_CONTA_PREMIUM_H
#include "conta.h"

class Cpremium : public Conta {
private:
    std::string _nome;
    std::string _genero;
    std::string _datanascimento;
    std::string _cpf;
    std::string _telefone;
    std::string _email;
    std::string _endereco;
    std::string _senha;
    std::string _status;

public:
    Cpremium();
    virtual void conta();
    void alterardados1();

};

#endif
