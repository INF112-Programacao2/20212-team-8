#include "cadastro.h"
#include <iostream>

Cadastro::Cadastro(){
    _nome = NULL;
    _genero = NULL;
    _datanascimento = NULL;
    _cpf = NULL;
    _telefone = NULL;
    _email = NULL;
    _endereco = NULL;
    _senha = NULL;
    _nomeproduto = NULL;
    _codigoproduto = NULL;
    _precoproduto = NULL;
    _quantidadeproduto = NULL;
    _descricaoproduto = NULL;
}

void Cadastro::cadastrarconta(){
    std::cin >> _nome;
    std::cin >> _genero;
    std::cin >> _datanascimento;
    std::cin >> _cpf;
    std::cin >> _telefone;
    std::cin >> _email;
    std::cin >> _endereco;
    std::cin >> _senha;
    std::cin >> _nomeproduto;
    std::cin >> _codigoproduto;
    std::cin >> _precoproduto;
    std::cin >> _quantidadeproduto;
    std::cin >> _descricaoproduto;
}
