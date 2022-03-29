#include "contapremium.h"
#include <fstream>
#include <string>
#include <iostream>

Cpremium::Cpremium(){

    char captura[200];
    std::ifstream acc_op;

    acc_op.open("conta.txt",std::ios::in);

    for(int i = 0; i < 9; i++){	
		
        acc_op.getline(captura,200);
        if(i == 0){
            _nome = captura;
        }if(i == 1){
            _genero = captura;
        }if(i == 2){
            _datanascimento = captura;
        }if(i == 3){
            _cpf = captura;
        }if(i == 4){
            _telefone = captura;
        }if(i == 5){
            _email = captura;
        }if(i == 6){
            _endereco = captura;
        }if(i == 7){
            _senha = captura;
        }if(i == 8){
            _status = captura;
        }
    }

    acc_op.close();

}

void Cpremium::conta(){

    std::cout << "Nome: ";
    std::cout << _nome << std::endl;
    std::cout << "Genero: ";
    std::cout << _genero << std::endl;
    std::cout << "Data de nacimento: ";
    std::cout << _datanascimento << std::endl;
    std::cout << "CPF: ";
    std::cout << _cpf << std::endl;
    std::cout << "Telefone: ";
    std::cout << _telefone << std::endl;
    std::cout << "Email: ";
    std::cout << _email << std::endl;
    std::cout << "Endereco: ";
    std::cout << _endereco << std::endl;
    std::cout << "Senha: ";
    std::cout << _senha << std::endl;
    std::cout << "Tipo de conta: ";
    std::cout << _status << std::endl;

}

void Cpremium::alterardados1(){
    int i;
    char op;

    std::cout << "Deseja alterar qual dado? Digite a opcao correspondente." << std::endl;
    std::cout << "(1) Nome" << std::endl;
    std::cout << "(2) Genero" << std::endl;
    std::cout << "(3) Data de nascimento" << std::endl;
    std::cout << "(4) CPF" << std::endl;
    std::cout << "(5) Telefone" << std::endl;
    std::cout << "(6) Email" << std::endl;
    std::cout << "(7) Endereco" << std::endl;
    std::cout << "(8) Senha" << std::endl;
    std::cout << "Caso queira continuar alterando dados, digite 's', senao, digite 'n'" << std::endl;

    std::cin >> i;

    while(true){
        while(i < 1 || i > 8){
            std::cout << "Erro! Digite valores de 1 a 8 para definir uma alteracao" << std::endl;
            std::cin >> i;
        }

        if(i == 1){
            std::cin >> _nome;
        }else if(i == 2){
            std::cin >> _genero;
        }else if(i == 3){
            std::cin >> _datanascimento;
        }else if(i == 4){
            std::cin >> _cpf;
        }else if(i == 5){
            std::cin >> _telefone;
        }else if(i == 6){
            std::cin >> _email;
        }else if(i == 7){
            std::cin >> _endereco;
        }else if(i == 8){
            std::cin >> _senha;
        } 

        std::cin >> op;

        while(op != 's' || op != 'n'){
            std::cout << "Erro! Digite 's' para continuar alteracoes ou 'n' para encerrar alteracoes" << std::endl;
            std::cin >> op;
        }

        if(op == 's'){
            continue;
        }else if(op == 'n'){
            break;
        } 
    }

    std::ofstream acc_change;

    acc_change.open("conta.txt",std::ios::out);

    acc_change << _nome << std::endl;
    acc_change << _genero << std::endl;
    acc_change << _datanascimento << std::endl;
    acc_change << _cpf << std::endl;
    acc_change << _telefone << std::endl;
    acc_change << _email << std::endl;
    acc_change << _endereco << std::endl;
    acc_change << _senha << std::endl;
    acc_change << _status << std::endl;

    acc_change.close();
}