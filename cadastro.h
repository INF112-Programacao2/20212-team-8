#ifndef TPFINAL_CADASTRO_H
#define TPFINAL_CADASTRO_H
#include <string>

class Cadastro{
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
    std::string _nomeproduto;
    std::string _codigoproduto;
    std::string _precoproduto;
    std::string _quantidadeproduto;
    std::string _descricaoproduto;

public:
    Cadastro();
    void cadastrarproduto();
    bool login();
};

#endif