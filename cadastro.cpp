#include "cadastro.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

Cadastro::Cadastro(){
   std::cout << "Ja possui conta? Se sim, digite 'S' para ir para o login." << std::endl;
   std::cout << "Se nao, digite 'N' para criar uma conta" << std::endl;
   char option;
   
   std::cin >> option;
   if(option == 'S' || option == 's'){
	  
   }else if(option == 'N' || option == 'n'){
	std::cin.ignore();
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
	
	acc_saida << "#";
    acc_saida << _nome << std::endl;
	acc_saida << "#";
    acc_saida << _genero << std::endl;
    acc_saida << "#";
	acc_saida << _datanascimento << std::endl;
    acc_saida << "#";
	acc_saida << _cpf << std::endl;
    acc_saida << "#";
	acc_saida << _telefone << std::endl;
    acc_saida << "#";
	acc_saida << _email << std::endl;
    acc_saida << "#";
	acc_saida << _endereco << std::endl;
    acc_saida << "#";
	acc_saida << _senha << std::endl;
    
    acc_saida.close();
   }
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
	char captura[200];
	char teste[200];
	char *t;
	bool acc_vrfy = true;
	std::cout << "Para efetuar login na nossa plataforma, digite seu email e apos confirmar, digite sua senha: ";
    
    std::string email;
    std::cin >> email;

    std::string senha;
    std::cin >> senha;

    std::ifstream acc_check;
    acc_check.open("conta.txt",std::ios::in);
	
		
	for(int i = 0; i < 8; i++){	
		acc_check.getline(captura,200);

		if(i == 5){
			t = strtok(captura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(teste, t);		//Captura do nome
				t = strtok(NULL,"#");
			}
			
			if(email != teste){
				acc_vrfy = false;
			}
		}if(i == 7){
			t = strtok(captura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(teste, t);		//Captura do nome
				t = strtok(NULL,"#");
			}
	
			if(senha != teste && acc_vrfy != false){
				acc_vrfy = false;
			}
			
		}if(i == 7 && acc_vrfy == true){
			std::cout << "Login realizado com sucesso!" << std::endl;
			std::cout << "Transferindo para a pagina inicial..." << std::endl;
		}else if(i == 7 && acc_vrfy != true){
			std::cout << "Email ou senha incorretos! Tente novamente." << std::endl;
			acc_check.close();
			std::cin >> email;
			std::cin >> senha;
			i = -1;
			acc_vrfy = true;
			acc_check.open("conta.txt",std::ios::in);
		}
	}
	
}