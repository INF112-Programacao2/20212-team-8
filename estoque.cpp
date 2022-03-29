#include <iostream>
#include "estoque.h"


Estoque::Estoque(){

   char dados[50];
   std::ifstream acc_get;
   int n = 1;
   int d = 0;
   int d1 = 0;
   int dd1 = 3;

   acc_get.open("produtos.txt",std::ios::in);

   for(int i = 0; i < n; i++){
       if(acc_get.eof()){
           break;
       }
       acc_get.getline(dados,50);
       if(i == d*6){
           strcpy(_nomeproduto[d],dados);
           d++;
       }if(i == dd1+6){
           _estoque[d1] = atoi(dados);
           dd1 += 6;
           d1++;
       }
       n++;
   }
   
}



void Estoque::fluxoproduto(){

    int h = 0;

    char dados[50];
    char dados1[5][100];

    double quantidade;
    std::string nome;
    int quantfinal;

    std::ifstream acc_check;
    std::ofstream acc_out;

    acc_check.open("compra.txt",std::ios::in);

    while(true){
        acc_check.getline(dados,50);

        if(h == 0){
            nome = dados;
        }if(h == 1){
            quantidade = atof(dados);
        }
        h++;
    }

    acc_check.close();

    acc_check.open("produtos.txt",std::ios::in);

    int q = 0;
    int e = 0;

    for(int i = 0; i > -1 ; i++){
        
        if(acc_check.eof()){
            break;
        }
        
        acc_check.getline(dados1[i],100);
        acc_check.getline(dados,50);

        if(i == q*6){
            q++;
        }
        e++;
    }

    h = 0;

    for(int i = 0; i <= q; i++){
        if(nome == _nomeproduto[i]){
            quantfinal = _estoque[i] - quantidade;
            h = i;
        }
    }

    acc_check.close();

    acc_out.open("produtos.txt",std::ios::out);

    for(int j = 0; j < e; j++){
        if(j == e-1){
            break;
        }

        if(j == 3+(h*6)){
            acc_out << quantfinal << std::endl;
        }else{
            acc_out << dados1[j] << std::endl;
        }
    }

    acc_out.close();

}