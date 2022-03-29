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
   int verifica = 0;

   while(verifica == 0){
	
		if(option == 'S' || option == 's'){
			verifica++;
		}else if(option == 'N' || option == 'n'){
			verifica++;
		}else if(verifica == 0){
			std::cout << "Opcao invalida!" << std::endl;
			std::cout << "Ja possui conta? Se sim, digite 'S' para ir para o login." << std::endl;
			std::cout << "Se nao, digite 'N' para criar uma conta." << std::endl;
			std::cin >> option;
		}
   }

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
	_status = "Normal";
   
    std::string arquivot1("conta.txt");
    std::ifstream acc_entrada;
    std::ofstream acc_saida;

    acc_entrada.open(arquivot1,std::ios_base::app);
	
	acc_saida.open(arquivot1,std::ios::out);
	
	
    acc_saida << _nome << std::endl;
    acc_saida << _genero << std::endl;
	acc_saida << _datanascimento << std::endl;
	acc_saida << _cpf << std::endl;
	acc_saida << _telefone << std::endl;
	acc_saida << _email << std::endl;  
	acc_saida << _endereco << std::endl;
	acc_saida << _senha << std::endl;
	acc_saida << _status << std::endl;
    
    acc_saida.close();
   }
}

void Cadastro::cadastrarproduto(){
    std::cin.ignore();
    std::cout << "::Cadastrar Produto::" << std::endl;
    std::cout << "Digite o nome do produto: ";
    std::getline(std::cin, _nomeproduto);
    std::cout << "Digite o codigo do produto: ";
    std::getline(std::cin, _codigoproduto);
    std::cout << "Digite o preco do produto: R$";
    std::getline(std::cin,_precoproduto);
    std::cout << "Digite a quantidade do produto: ";
    std::getline(std::cin,_quantidadeproduto);
    std::cout << "Insira a descricao do produto: ";
    std::getline(std::cin, _descricaoproduto);
	
	std::ifstream prod_entrada;
	std::ofstream prod_saida;
	
	prod_entrada.open("produtos.txt",std::ios::in);
	
	if(!prod_entrada){	

		prod_entrada.open("produtos.txt",std::ios_base::app);
		
		prod_saida.open("produtos.txt",std::ios::out);

		prod_saida << _nomeproduto << std::endl;
		prod_saida << _codigoproduto << std::endl;
		prod_saida << _precoproduto << std::endl;
		prod_saida << _quantidadeproduto << std::endl;
		prod_saida << _descricaoproduto << std::endl;
		prod_saida << "+" << std::endl;
		
		prod_saida.close();
	
	}else{
		char captura1[100][100];
		int i = 0;
		
		while(true){
			if(prod_entrada.eof()){
				break;
			}
			prod_entrada.getline(captura1[i],100);
			i++;
		}
		
		prod_saida.open("produtos.txt",std::ios::out);
		
		for(int j = 0; j < i; j++){
			if(j == i-1){
				prod_saida << captura1[j];
			}else{
				prod_saida << captura1[j] << std::endl;
			}
		}
		
		prod_saida << _nomeproduto << std::endl;
		prod_saida << _codigoproduto << std::endl;
		prod_saida << _precoproduto << std::endl;	
		prod_saida << _quantidadeproduto << std::endl;
		prod_saida << _descricaoproduto << std::endl;
		prod_saida << "+" << std::endl;
		
		prod_saida.close();
	}
}

bool Cadastro::login(){
	char captura[200];
	bool acc_vrfy = true;
	std::cout << "Para efetuar login na nossa plataforma, digite seu email e apos confirmar, digite sua senha: ";
    
    std::string email;
    std::cin >> email;

    std::string senha;
    std::cin >> senha;

    std::ifstream acc_check;

	if(email == "admin@adm.com" && senha == "admin4012"){
		std::cout << "Login de conta ADM realizado com sucesso!" << std::endl;
		std::cout << "Transferindo para a pagina de gerenciamento da loja..." << std::endl;
		return false;
	}

    acc_check.open("conta.txt",std::ios::in);
	
		
	for(int i = 0; i < 8; i++){	
		acc_check.getline(captura,200);

		if(i == 5){
			
			if(email != captura){
				acc_vrfy = false;
			}

		}if(i == 7){
	
			if(senha != captura && acc_vrfy != false){
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

	return 0;
}