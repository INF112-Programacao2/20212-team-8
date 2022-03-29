#include <iostream>
#include "compra.h"
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip>

Compra::Compra(){

    _numeropedido = 0;
    _data = "nulo";    
    _cliente = "nulo";
}

void Compra::exibirjogos(){
    std::cout << "::Jogos disponiveis em nossa plataforma::" << std::endl;
    
    char leitura[100];
    int n = 1;
    int g = 0;

    std::ifstream view_gamelist;

    view_gamelist.open("produtos.txt",std::ios::in);
	
	 if(!view_gamelist){
        std::cout << "Loja encontra-se sem produtos, em breve disponibilizaremos novos jogos..." << std::endl;
    }else{
	
		for(int i = 0; i < n; i++){
			if(view_gamelist.eof()){
				break;
			}
	
			view_gamelist.getline(leitura,100);
			if(i == g*6){
				std::cout << g << "- " << leitura << std::endl;
				g++;
			}
			n++;
		}
	}
    
}

bool Compra::comprar(){
    int opcao;
    char leitura[50];
    char d;
    int n = 1;
    double quant;
    double totalvalor;
    
    std::string nome;
    double valor;
    double quantidade;
    std::ifstream view_gamelist;
    std::ifstream acc_saldo;
    std::ofstream acc_saldout;
    
    while(true){
        std::cout << "Digite o numero do jogo que deseja comprar: ";
        std::cin >> opcao;
        std::cin.ignore(); 

        std::cout << "Encaminhando para a pagina..." << std::endl;
        
        view_gamelist.open("produtos.txt",std::ios::in);
        for(int i = 0; i <= n; i++){
			if(view_gamelist.eof()){
				break;
			}
            view_gamelist.getline(leitura,50);
			
			if(i == (opcao*6)){
				
				std::cout << "Nome: " << leitura << std::endl;
				nome = leitura;
          
            }if(i == (opcao*6)+1){
               
                std::cout << "Codigo do jogo: " << leitura << std::endl;
                
            }if(i == (opcao*6)+2){

                std::cout << "R$ " << leitura << std::endl;
                valor = atof(leitura);

            }if(i == (opcao*6)+3){
                quantidade = atof(leitura);
                std::cout << "Em estoque: " << leitura << std::endl;
                
            }if(i == (opcao*6)+4){

                std::cout << "Descricao: " << leitura << std::endl; 
                
            }
			n++;
        }

        std::cout << "Deseja efetuar a compra?" << std::endl;
		std::cout << "Digite 'S' para efetuar a compra" << std::endl;
        std::cout << "Se nao, digite 'N' para cancelar a compra e voltar a pagina inicial." << std::endl;
        
		int verifica = 0;
        std::cin >> d;

        while(verifica == 0){
            
                if(d == 'S' || d == 's'){
                    verifica++;
                }else if(d == 'N' || d == 'n'){
                    verifica++;
                }else if(verifica == 0){
                    std::cout << "Opcao invalida!" << std::endl;
                    std::cout << "Digite 'S' para efetuar a compra" << std::endl;
                    std::cout << "Se nao, digite 'N' para cancelar a compra e voltar a pagina inicial." << std::endl;
                    std::cin >> d;
                }
        }
        
        if(d == 'S' || d == 's'){
            
            std::cout << "Quantas unidades?" << std::endl;
            std::cin >> quant;

			while(quant < 1 || quant > quantidade){
				std::cout << "Erro! Digite um valor valido de 1 a " << quantidade << ".";
				std::cin >> quant; 
			}

			totalvalor = quant*valor;

			acc_saldo.open("compra.txt",std::ios_base::app);
			acc_saldout.open("compra.txt",std::ios::out);

			acc_saldout << nome << std::endl;
			acc_saldout << quant << std::endl;
			acc_saldout << std::fixed << std::setprecision(2) << totalvalor << std::endl;

			acc_saldout.close();
			return true;

        }else if(d == 'N' || d == 'n'){
           return false;
        }
    }
}

void Compra::pedido(){
    char comentario1[100];
    char comentario3[100];

    std::string nome;
    std::string valor;
    std::string quantidade;

    srand(time(0));
    _numeropedido = 1+rand()%100;
	
	std::string numeropedido(std::to_string(_numeropedido));

    std::ifstream acc_check1;
    std::ofstream acc_out1;

    acc_check1.open("conta.txt",std::ios::in);

    acc_check1.getline(comentario3,100);

    _cliente = comentario3;

    acc_check1.close();

    acc_check1.open("compra.txt");

    int h = 0;

    while(h < 3){
        acc_check1.getline(comentario1,100);
        
        if(h == 0){
            nome = comentario1;
        }if(h == 1){
            quantidade = comentario1;
        }if(h == 2){
            valor = comentario1;
        }

        h++;
    }
	
	std::cout << "::Pedido::" << std::endl;
	std::cout << "Numero do pedido: ";
	std::cout << numeropedido << std::endl;
	std::cout << "Cliente: ";
	std::cout << _cliente << std::endl;
	std::cout << "Nome: ";
	std::cout << nome << std::endl;
	std::cout << "Quantidade: ";
	std::cout << quantidade << "x" << std::endl;
	std::cout << "Preco: R$";
	std::cout << valor << std::endl;
	
    acc_check1.open("pedido.txt",std::ios_base::app);
    acc_out1.open("pedido.txt",std::ios::out);
	
    acc_out1 << _numeropedido << std::endl;
    acc_out1 << _cliente << std::endl;
    acc_out1 << nome << std::endl;
    acc_out1 << quantidade << std::endl;
    acc_out1 << valor << std::endl;
    
    acc_out1.close();
}


void Compra::emitirrecibo(){

    char comentario1[100];
    char comentario2[100];
    std::ifstream acc_entrada;
    std::ofstream acc_saida;
    std::string numeropedido;
    std::string nome;
    std::string nomepedido;
    std::string precoproduto;
    int h1 = 0;

    acc_entrada.open("pedido.txt",std::ios::in);

    while(h1 < 4){
        acc_entrada.getline(comentario1,100);

        if(h1 == 0){
           _cliente = comentario1;
        }if(h1 == 1){
            precoproduto = comentario1;
        }if(h1 == 2){
            nomepedido = comentario1;
        }if(h1 == 3){
            numeropedido = comentario1;
        }
        h1++;
    }

    acc_entrada.close();

    acc_entrada.open("recibo.txt",std::ios_base::app);
    acc_saida.open("recibo.txt",std::ios::in);

    acc_saida << "Olá ";
    acc_saida << _cliente << std::endl;
    acc_saida << "Obrigado por comprar na nossa loja." << std::endl;
    acc_saida << "Numero do pedido: " << numeropedido << std::endl;
    acc_saida << "Nome do produto: " << nomepedido << std::endl;
    acc_saida << "Preco do produto: " << precoproduto << std::endl;

    acc_saida.close();

}





