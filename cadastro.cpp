#include "cadastro.h"
#include <iostream>
#include <string>
#include <fstream>

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
   
}

void Cadastro::cadastrarproduto(){
    std::cout << "::Cadastrar Produto::" << std::endl;
    std::cout << "Digite o nome do produto: ";
    std::cin >> _nomeproduto;
    std::cout << "Digite o codigo do produto: ";
    std::cin >> _codigoproduto;
    std::cout << "Digite o preco do produto: ";
    std::cin >> _precoproduto;
    std::cout << "Digite a quantidade do produto: ";
    std::cin >> _quantidadeproduto;
    std::cout << "Insira a descricao do produto: ";
    std::cin >> _descricaoproduto;
}

void Cadastro::temcadastro(){
    
}