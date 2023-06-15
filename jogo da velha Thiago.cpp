 # include <stdio.h>
# include <stdlib.h>
# include <locale.h>



int jogo(int ganhou, char tabuleiro[3][3]){
	
		if(tabuleiro[0][0] == 'O' &&tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O' ||
               tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O' ||
              tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'){
                printf("\nParabens! O jogador O venceu por linha!\n");
                ganhou = 1;
            }

            if(tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X' ||
               tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X' ||
               tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'){
                printf("\nParabens! O jogador X venceu por linha!\n");
                ganhou = 1;
            }

          
            if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O' ||
              tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O' ||
               tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O'){
                printf("\nParabens! O jogador O venceu por coluna!\n");
                ganhou = 1;
            }

            if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X' ||
               tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X' ||
               tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X'){
                printf("\nParabens! O jogador X venceu por coluna!\n");
                ganhou = 1;
            }else(printf("NINGUEM GANHOU!, JOGUE NOVAMENTE!"));

            return ganhou;	
}

bool validar_jogadas(int l, int c, char tabuleiro[3][3]){
	if(tabuleiro[l][c] != ' '){
		printf("jogada invalida\n");
		return false;
	}else{
		return true;
	}
}
void controle(int op)
{
	system("cls");
	
	switch(op)
	{
		case 1:
		
		     break;
		case 2:
			  printf("\t\tJOGO ENCERRADO\n");
			 
			     return; 
			 break;
		  	  
	}
}
void menu()
{
	setlocale(LC_ALL, "portuguese");
	int op;
	
	printf("\t\t========SEJA BEM-VINDO========\n");
	printf("\t\t======A O JOGO DA VELHA======\n");
	printf("\n");
	printf("\t\t=======Pressione-1 para jogar=======\n");
	printf("\t\t=====Se quiser sair pressione-2====\n");
	printf("\t\t:");
	scanf("%d", &op);
	
	controle(op);
}

int main(){
	
	menu();
	int c;
	int l;
	int ganhou = 0;
	int jogadas = 0;
	int jogador = 1;
	int jogadas_o;
	int jogadas_x;
	char letra;
	char tabuleiro[3][3];
		
	
		
		 for(l = 0; l < 3; l++){
	            for(c = 0; c < 3; c++){
	        tabuleiro[l][c] = ' ';
	 
				}
		  }
		  
          do{
		      printf("\n\n\t 0   1   2\n\n");
		        for(l = 0; l < 3; l++){
		            for(c = 0; c < 3; c++){
		                if(c == 0)
		                    printf("\t");
		                printf(" %c ", tabuleiro[l][c]);
		                if(c < 2)
		                    printf("|");
		                if(c == 2)
		                    printf("  %d", l);
		            }
		            if(l < 2)
		                printf("\n\t-----------");
		            printf("\n");
		        }
				
				if(jogador == 1){			
						do{
							printf("Escolha sua jogada, jogador X \n");
							printf("linha: ");
							scanf("%d", &l);
							printf("coluna: ");
							scanf("%d", &c);	
						}while(!validar_jogadas(l, c, tabuleiro));
							tabuleiro[l][c] = 'X';
							jogadas++;
							jogador++;
							
					}
					else{
						do{
							printf("Escolha sua jogada, jogador O \n");
							printf("linha: ");
							scanf("%d", &l);
							printf("coluna: ");
							scanf("%d", &c);	
						}while(!validar_jogadas( l, c, tabuleiro));
							tabuleiro[l][c] = 'O';
							jogadas++;
							jogador--;
				}
          }while(jogo(ganhou,tabuleiro) == 0 && jogadas < 9);
			
    return 0;
	
}
