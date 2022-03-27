#include "jogos.h"

Jogos::Jogos(){
    std::cout << "::Jogos disponiveis em nossa plataforma::" << std::endl;
    
    char leitura[100];
    char leitura2[100];
    char *c;
    std::ifstream view_gamelist;

    view_gamelist.open("produtos.txt",std::ios::in);
    for(int i = 0; i <= n; i++){
        view_gamelist.getline(leitura,100);
        if(i == i*6){
            c = strtok(leitura,"#");		//Separação da string em tokens
					
			while(t != NULL){
				strcpy(leitura2, c);		//Captura do nome
				c = strtok(NULL,"#");
			}
            std::cout << i << "- " << leitura2 << std::endl;
        }
    }
    


}