#include "cadastro.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

Cadastro::Cadastro(){
    std::getline(std::cin, _nome); 
	std::getline(std::cin,_genero);
	std::getline(std::cin, _datanascimento);
	std::getline(std::cin, _cpf);
	std::getline(std::cin, _telefone); 
	std::getline(std::cin, _email); 
	std::getline(std::cin, _endereco);
	std::getline(std::cin, _senha);
   
    std::string arquivot1("conta.txt");
    std::ifstream acc_entrada;
    std::ofstream acc_saida;

    acc_entrada.open(arquivot1,std::ios_base::app);
	
	acc_saida.open(arquivot1,std::ios::out);
	
	acc_saida << "Nome: ";
    acc_saida << _nome << std::endl;
	acc_saida << "Genero: ";
    acc_saida << _genero << std::endl;
    acc_saida << "Data de nascimento: ";
	acc_saida << _datanascimento << std::endl;
    acc_saida << "CPF: ";
	acc_saida << _cpf << std::endl;
    acc_saida << "Telefone: ";
	acc_saida << _telefone << std::endl;
    acc_saida << "Email: ";
	acc_saida << _email << std::endl;
    acc_saida << "Endereco: ";
	acc_saida << _endereco << std::endl;
    acc_saida << "Senha: ";
	acc_saida << _senha << std::endl;
    
    acc_saida.close();
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
    std::cout << "Para efetuar login na nossa plataforma, digite seu email e apos confirmar, digite sua senha: ";
    
    std::string email;
    std::cin >> email;

    std::string senha;
    std::cin >> senha;

    ifstream acc_check;
    


    
}