#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#define TAM_FILME 10
#define TAM_PESSOA 10
#define MAX_LOCACOES 25

int codeFilme = 0;
int codePessoa = 0;
int code2 = 0;
int buscafilme = 0;
int buscapessoa = 0;

struct Aluguel_filme {
	char nome_filme[50];
	float preco;
	int codigo;
	int quantidade;
};

Aluguel_filme cadfilme[TAM_FILME];

struct Cadastro_pessoa {
	char endereco[50];
	char cidade[50];
	int idade;
	int cpf[11];
	char nome [20];
	int codigo;
};

Cadastro_pessoa cadpessoa[TAM_PESSOA];

typedef struct locacao {
    char cadlocacao[100]; // Alterei para um array de caracteres para armazenar o local
    char filmelocal[100];
} p1;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data_inicial;
    Data data_final;
    int valor_total;
} Locacao;

Locacao locacoes[MAX_LOCACOES];
int num_locacoes = 0;

void data_aloca(Locacao *locacao) {
    
	int Dia = 0;
	int Mes = 0;
	int Ano = 0;
	int preco = 0;
    Dia = abs(locacao->data_final.dia - locacao->data_inicial.dia);
    Mes = abs(locacao->data_final.mes - locacao->data_inicial.mes);
    Ano = abs(locacao->data_final.ano - locacao->data_inicial.ano);
    locacao->valor_total = (Dia + Mes + Ano) * preco;
}

void adicionar_locacao(Locacao *locacao) {
  
    if (num_locacoes < MAX_LOCACOES) {
        locacoes[num_locacoes++] = *locacao;
    } else {
        printf("Limite máximo de locações alcançado.\n");
    }
}

void listar_locacoes() {
	int dataInicial;
	int dataFinal;
	int diasAlocados;
	
	
    printf("Lista de locações:\n");
    for (int i = 0; i < num_locacoes; i++) {
        printf("Locação %d:\n", i + 1);
        printf("Data inicial: %02d/%02d/%04d\n", locacoes[i].data_inicial.dia, locacoes[i].data_inicial.mes, locacoes[i].data_inicial.ano);
        scanf("%d", &dataInicial);
        printf("Data final: %02d/%02d/%04d\n", locacoes[i].data_final.dia, locacoes[i].data_final.mes, locacoes[i].data_final.ano);
        scanf("%d", &dataFinal);
        printf("Valor total: R$ %d\n", locacoes[i].valor_total);
        printf("\n");
	}
}

void cadloc(){
	
	
    printf("\tPor quanto tempo deseja alocar o filme ?\n");
    printf("\n");
    Locacao locacao;

    printf("\t\tData inicial:\n");
    printf("\t\tdia:");
    scanf("%d", &locacao.data_inicial.dia);
    printf("\t\tmes:");
    scanf("%d", &locacao.data_inicial.mes);
    printf("\t\tano:");
    scanf("%d", &locacao.data_inicial.ano);
    printf("\n");
    printf("\t\tData final\n");
    printf("\t\tdia:");
    scanf("%d", &locacao.data_final.dia);
    printf("\t\tmes:");
    scanf("%d", &locacao.data_final.mes);
    printf("\t\tano:");
    scanf("%d", &locacao.data_final.ano);
    printf("\n");

    printf("\nLocação registrada com sucesso!\n");
    printf("\n");

}

void menuPrincipal() {
	system("cls");
	
	printf("\t\t\t\t\t=========================================\n");
	printf("\t\t\t\t\t==== SISTEMA DE CADASTRO DE PRODUTOS ====\n");
	printf("\t\t\t\t\t=========================================\n\n\n");
}

void menuLocFilme() {
	printf("==== CADASTRO DE FILMES ====\n");
	
	if(codeFilme == TAM_FILME) {
		printf("O sistema está cheio.");
	} else {
		fflush(stdin);
		printf("Nome do filme: ");
		fgets(cadfilme[codeFilme].nome_filme,sizeof(cadfilme[codeFilme].nome_filme), stdin);
		
		fflush(stdin);
		printf("Quantidade de filmes desejados: ");
		scanf("%d", &cadfilme[codeFilme].quantidade);
		
		fflush(stdin);
		printf("Preço: ");
		scanf("%f", &cadfilme[codeFilme].preco);
		
		fflush(stdin);
		printf("Codigo: ");
		scanf("%d", &cadfilme[codeFilme].codigo);
		
		printf("\nProduto cadastrado com sucesso! Código: %d", codeFilme++);
		menuPrincipal();
		
	}
}

void buscaLocFilme() {
	int buscafilme = 0;
	char op;
	
	do {
		printf("\n\n===== BUSCAR =====\n\n");
		
		for(int i = 0;i < codeFilme; i++) {
			printf("%d - %s\n", i, cadfilme[i].nome_filme);
		}
		
		fflush(stdin);
		printf("Deseja saber detalhes do cadastro do filme? (s/n): ");
		scanf("%c", &op);
		
		if(toupper(op) == 'S') {
			printf("\nInforme o código do produto: ");
			scanf("%d", &buscafilme);
			
			printf("\n");
			
			if(buscafilme < codeFilme) {
				printf("\nNome do filme: %s", cadfilme[buscafilme].nome_filme);
				printf("\nCodigo: %d", cadfilme[buscafilme].codigo);
				printf("\nPreço: R$ %.2f", cadfilme[buscafilme].preco);
				printf("\nQuantidade: %d", cadfilme[buscafilme].quantidade);
				
			} else {
				printf("Produto não encontrado!Tente novamente");
				menuPrincipal();
			}
		}
	} while(toupper(op) != 'N');
}

void menuCadPessoa(){
	
	menuPrincipal();
	printf("==== CADASTRO DO CLIENTE ====\n");
	
	if(codePessoa == TAM_PESSOA) {
		printf("O sistema está cheio.");
	} else {
		fflush(stdin);
		printf("Digite seu nome: ");
		scanf("%s", &cadpessoa[codePessoa].nome);
		
		fflush(stdin);
		printf("Informe sua cidade: ");
		scanf("%s", &cadpessoa[codePessoa].cidade);
		
		fflush(stdin);
		printf("Informe sua idade: ");
		scanf("%d", &cadpessoa[codePessoa].idade);
		
		fflush(stdin);
		printf("Informe o seu CPF: ");
		scanf("%d", &cadpessoa[codePessoa].cpf);
		
		fflush(stdin);
		printf("Informe o seu Endereço: ");
		scanf("%s", &cadpessoa[codePessoa].endereco);
		
		fflush(stdin);
		printf("Codigo: ");
		scanf("%d", &cadpessoa[codePessoa].codigo);
		
		printf("\nProduto cadastrado com sucesso! Código: %d", codePessoa++);
		menuPrincipal();
	}

} 

void buscaCadPessoa() {
	int buscapessoa;
	char opcaopessoa;

		system("cls");
		printf("\n\n===== BUSCAR =====\n\n");
		
		system("cls");
		for(int i = 0;i < codePessoa; i++) {
			printf("%d - %s\n", i, cadpessoa[i].nome);
		}
	
		fflush(stdin);
		printf("Deseja saber detalhes do seu cadastro como cliente? (s/n): ");
		scanf("%c", &opcaopessoa);
		
		if(toupper(opcaopessoa) == 'S') {
			printf("\nInforme o código do produto: ");
			scanf("%d", &buscapessoa);
			
			printf("\n");
			
			if(buscapessoa < codePessoa) {
				printf("\nNome do cliente: %s", cadpessoa[buscapessoa].nome);
				printf("\nIdade: %d", cadpessoa[buscapessoa].idade);
				printf("\nCidade: %s", cadpessoa[buscapessoa].cidade);
				printf("\nCPF: %d", cadpessoa[buscapessoa].cpf);
				printf("\nEndereço: %s", cadpessoa[buscapessoa].endereco);
				printf("\nCódigo: %d", cadpessoa[buscapessoa].codigo);
		
			} else {
				printf("Produto não encontrado!");
				
			}
		}
}

void buscaLocacaoPorFilme (){
	char oplocfilme;
	char oplocfilme2;
	
	system("cls");
	printf("Deseja buscar sua locação pelo código de cadastro do filme? ");
	scanf("%c", &oplocfilme);
	
	if(oplocfilme == 's'){
		printf("\nDigite o código de cadastro do filme: ");
		scanf("%d", &oplocfilme2);
	
		if(oplocfilme2 == codePessoa){
			printf("\nNome do filme: %s", cadfilme[buscafilme].nome_filme);
			printf("\nCodigo: %d", cadfilme[codeFilme].codigo);
			printf("\nPreço: R$ %.2f", cadfilme[buscafilme].preco);
			printf("\nQuantidade: %d \n", cadfilme[buscafilme].quantidade);
			
		}
	}
}

void buscaLocacaoPorPessoa (){
	char oplocpessoa;
	
	printf("Deseja buscar sua locação pelo código de cadastro do cliente? ");
	scanf("%c", &oplocpessoa);
	
	if(oplocpessoa == 's'){
		printf("\nDigite o código de cadastro de cliente: ");
		scanf("%d", &cadpessoa[buscapessoa].codigo);
	
		if(cadpessoa[buscapessoa].codigo){
				printf("\nNome do cliente: %s", cadpessoa[buscapessoa].nome);
				printf("\nIdade: %d", cadpessoa[buscapessoa].idade);
				printf("\nCidade: %s", cadpessoa[buscapessoa].cidade);
				printf("\nCPF: %d", cadpessoa[buscapessoa].cpf);
				printf("\nEndereço: %s", cadpessoa[buscapessoa].endereco);
				printf("\nCódigo: %d", cadpessoa[buscapessoa].codigo);
		}
	}

}

void menuCad() {

    int opcao;
    do {
    	
    
        printf("Selecione uma opcao:\n");
        printf("1. Deseja buscar o filme cadastrado através do código? \n");
        printf("2. Deseja buscar seus dados de cliente através do código ? \n");
        printf("0. Sair? \n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        

        switch (opcao) {
            case 1:
                buscaLocFilme();
                break;
            case 2:
                buscaCadPessoa();
                break;
            case 0:
                printf("Saindo...\n");
                menuPrincipal();
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    
}

void choice(int op) {
	menuPrincipal();
	Locacao *locacao;
	switch(op) {
		case 1:		
			menuLocFilme();
			
			break;
			
		case 2:			
			menuCadPessoa();
				
			break;
			
		case 3:
			menuCad();
						
			break;
			
		case 4:
			cadloc();
			
			break;
			
		default:
			printf("Opção inválida!");		
	}
	
	printf("\n");
	
	system("pause");
	
	menuPrincipal();
}

int main() {
	setlocale(LC_ALL, "portuguese");
	
	int opmenu = 0;
	
	menuPrincipal();
	
	while(opmenu != 5) {
		printf("====== MENU ======\n");
		printf("1 - Cadastrar um filme\n");
		printf("2 - Cadastrar um novo cliente\n");
		printf("3 - Menu Locações\n");
		printf("4 - Cadastrar as locacoes\n");
		printf("5 - Sair \n\n");
		printf("Escolha uma opção: ");
		scanf("%d", &opmenu);
		
		if(opmenu == 5){
			exit(1);
		}
		
		choice(opmenu);
	}
}
