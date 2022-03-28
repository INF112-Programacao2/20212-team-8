#include <iostream>
#include "cadastro.h"
#include "vendas.h"
#include "compra.h"
#include <ctime>
#include <fstream>

Compra::Compra(){

    _numeropedido = "nulo";
    _data = "nulo";    
    _cliente = "nulo";
}

void Compra::exibirjogos(){
    std::cout << "::Jogos disponiveis em nossa plataforma::" << std::endl;
    
    char leitura[100];
    char leitura2[100];
    char *c;
    int n = 1;
    int g = 0;

    std::ifstream view_gamelist;

    view_gamelist.open("produtos.txt",std::ios::in);
    for(int i = 0; i < n; i++){
        view_gamelist.getline(leitura,100);
        if(i == g*6){
            c = strtok(leitura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(leitura2, c);		//Captura do nome
				c = strtok(NULL,"#");
			}
            std::cout << g << "- " << leitura2 << std::endl;
            g++;
        }
        n++;
        if(view_gamelist.eof()){
            break;
        }
    }
    

}

void Compra::comprar(){
    int opcao;

    std::cout << "Digite o numero do jogo que deseja comprar: ";
    std::cin >> opcao;
    std::cin.ignore(); 

    /*srand(time(0));
    _numeropedido = 1+rand()%100;

    std::cout << "Digite a data: ";
    std::cin >> _data;

    _cliente = _nome;*/
    
    char leitura[100];
    char leitura2[100];
    char *c;
    
    std::ifstream view_gamelist;

    std::cout << "Encaminhando para a pagina..." << std::endl;
    view_gamelist.open("produtos.txt",std::ios::in);
    for(int i = 0; i <= n; i++){
        view_gamelist.getline(leitura,100);
        if(i == opcao*6){
            c = strtok(leitura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(leitura2, c);		//Captura do nome
				c = strtok(NULL,"#");
			}

            std::cout << "Nome: " << leitura2 << std::endl;
            
        }if(i == (opcao*6)+1){
            c = strtok(leitura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(leitura2, c);		//Captura do nome
				c = strtok(NULL,"#");
			}

            std::cout << "Codigo do jogo: " << leitura2 << std::endl;
            
        }if(i == (opcao*6)+2){
            c = strtok(leitura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(leitura2, c);		//Captura do nome
				c = strtok(NULL,"#");
			}

            std::cout << "R$ " << leitura2 << std::endl;

        }if(i == (opcao*6)+3){
            c = strtok(leitura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(leitura2, c);		//Captura do nome
				c = strtok(NULL,"#");
			}

            std::cout << "Em estoque: " << leitura2 << std::endl;
            
        }if(i == (opcao*6)+4){
            c = strtok(leitura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(leitura2, c);		//Captura do nome
				c = strtok(NULL,"#");
			}

            std::cout << "Descricao: " << leitura2 << std::endl; 
            
        }
    }
    

}


void Compra::emitirrecibo(){


    std::string arquivor("recibo.txt");
    std::ifstream acc_entrada;
    std::ofstream acc_saida;

    acc_entrada.open(arquivor,std::ios_base::app);
	acc_saida.open(arquivor,std::ios::out);
     

     acc_saida << "Olá ";
     acc_saida << _nome << std::endl;
     acc_saida << " Obrigado por comprar na nossa loja." << std::endl;
     acc_saida << "Nome do Produto: " << _nomeproduto << std::endl;
     acc_saida << "Preco do produto: " << _precoproduto << std::endl;

     acc_saida.close();

}





