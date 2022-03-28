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

    while(true){
        std::cout << "Digite o numero do jogo que deseja comprar: ";
        std::cin >> opcao;
        std::cin.ignore(); 
        
        char leitura[100];
        char leitura2[100];
        char *c;
        char d;
        std::string nome;
        std::string valor;


        std::ifstream view_gamelist;
        std::ifstream acc_saldo;
        std::ofstream acc_saldout;

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
                nome = leitura2;
                
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
                valor = leitura2;

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

        std::cout << "Deseja efetuar a compra?" << std::endl;
        int verifica = 0;
        std::cin >> d;

        while(verifica == 0){
            
                if(d == 'S' || d == 's'){
                    verifica++;
                }else if(d == 'N' || d == 'n'){
                    verifica++;
                }else if(verifica == 0){
                    std::cout << "Opcao invalida!" << std::endl;
                    std::cout << "Ja possui conta? Se sim, digite 'S' para ir para o login." << std::endl;
                    std::cout << "Se nao, digite 'N' para criar uma conta." << std::endl;
                    std::cin >> d;
                }
        }
        
        if(option == 'S' || option == 's'){
            
            acc_saldo.open("compra.txt",std::ios_base::app);
            acc_saldout.open("compra.txt",std::ios::out);

            acc_saldout << "#";
            acc_saldout << nome << std::endl;
            acc_saldout << "#";
            acc_saldout << valor << std::endl;

            acc_saldout.close();
            break;

        }else if(option == 'N' || option == 'n'){
            continue;
        }
    }
}

void Compra::pedido(){
    char comentario1[100];
    char comentario2[100];
    char comentario3[100];
    char *k;
    std::string nome;
    std::string valor;

    srand(time(0));
    _numeropedido = 1+rand()%100;

    std::ifstream acc_check1;
    std::ofstream acc_out1;

    acc_check1.open("conta.txt",std::ios::in);

    acc_check1.getline(comentario1,100);

    k = strtok(comentario1,"#");		//Separação da string em tokens
					
    while(k != NULL){
        strcpy(comentario3, k);		//Captura do nome
        k = strtok(NULL,"#");
    }

    acc_check.close();

    acc_check1.open("compra.txt");

    int h = 0;

    while(h < 2){
        acc_check1.getline(comentario1,100);
        
        k = strtok(comentario1,"#");		//Separação da string em tokens
                        
        while(k != NULL){
            strcpy(comentario2, k);		//Captura do nome
            k = strtok(NULL,"#");
        }

        if(h == 0){
            nome = comentario2;
        }if(h == 1){
            valor = comentario2;
        }
        h++;
    }

    acc_check.open("pedido.txt",std::ios_base::app);

    acc_out1 << "#";
    acc_out1 << _numeropedido << std::endl;
    acc_out1 << "#";
    acc_out1 << comentario3 << std::endl;
    acc_out1 << "#";
    acc_out1 << nome << std::endl;
    acc_out1 << "#";
    acc_out1 << valor << std::endl;
    
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
        acc_check1.getline(comentario1,100);
        
        k = strtok(comentario1,"#");		//Separação da string em tokens
                        
        while(k != NULL){
            strcpy(comentario2, k);		//Captura do nome
            k = strtok(NULL,"#");
        }

        if(h1 == 0){
            nome = comentario2;
        }if(h1 == 1){
            precoproduto = comentario2;
        }if(h1 == 2){
            nomepedido = comentario2;
        }if(h1 == 3){
            numeropedido = comentario2;
        }
        h1++;
    }

    acc_check1.close();

    acc_entrada.open("recibo.txt",std::ios_base::app);
    acc_saida.open("recibo.txt",std::ios::in);

    acc_saida << "Olá ";
    acc_saida << nome << std::endl;
    acc_saida << "Obrigado por comprar na nossa loja." << std::endl;
    acc_saida << "Numero do pedido: " << numeropedido << std::endl;
    acc_saida << "Nome do produto: " << nomepedido << std::endl;
    acc_saida << "Preco do produto: " << precoproduto << std::endl;

    acc_saida.close();

}





