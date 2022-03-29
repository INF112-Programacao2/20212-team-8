#ifndef TPFINAL_CONTA_NORMAL_H
#define TPFINAL_CONTA_NORMAL_H
#include "conta.h"
#include <string>
#include <iostream>

class Cnormal : public Conta {
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
    Cnormal();
    virtual void conta();
    void alterardados();

};

#endif

