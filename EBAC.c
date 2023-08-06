#include <stdio.h>// biblioteca de comunica��o com o ussuario
#include <stdlib.h>//biblioteca de aloca��o de espa�o em memoria
#include <locale.h>// biblioteca de aloca��o de texto por regi�o
#include <string.h>// biblioteca responsavel pelas strings

int registro() //responsavel por cadastrar os usu�rios no sitemas
{	
	char arquivo[30];//cria��o de variaveis/variaveis
	char cpf[30]; // char= caractere, 30= maximo de caracteres a ser digitados
	char nome[30];//criando a op��o para o us�ario responder essas quest�es
	char sobrenome[30];
	char cargo[30];
	
	printf("digite o cpf a ser cadastrado:");//coletando informa��o do usu�rio
	scanf("%s", cpf); //armazenar a informa��o na string e depois ler. string= registro de texto
	
	strcpy(arquivo , cpf);//responsavel por copiar os valores das strings
	
	FILE*file; // procurar na biblioteca um FILE (arquivo) e pedindo ele para criar um file ( criar um novo arquivo)
	file =fopen(arquivo, "w"); //abrir o arquivo e esvrever nele o que foi passado (Write)
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file=fopen(arquivo, "a"); // A= atualizar uma informa��o
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastradao:");
	scanf("%s", nome);
	
	file= fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado:");
	scanf("%s, cargo");
	
	file= fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	system("pause");
	
	printf("cadastro realizado com sucesso!\n\n");
	system("pause");
}

int consulta()
{	
	setlocale(LC_ALL, "portuguese");

	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file=fopen(cpf, "r");// (r)= read/ ler
	
	if (file==NULL) // se o arquivo for nulo ou nao for encontrado
	{ 
		printf("usuario nao encontrado");
	}
	
	
		while(fgets(conteudo, 200, file)!=NULL) 
	{	
		printf("essas s�o as informa��es do usuario:");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
	}
}


int deletar()
{	
	char cpf[40];
	
	printf("digite o cpf do ussuario a ser apagado:");
	scanf("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file= fopen(cpf,"r");
	
	if(file==NULL)
	{ 
		printf("usu�rio nao encontrado!\n");
		system("pause");
	}
	
	int exit (){ //comando para conseguir fechar o sitema
	
	system("pause");
	exit(0);
	
	}
}



int main()
{

	int opcao=0;
	int x=1;
	
	for(x=1;x=1;)//repetidor
	{
		
		system("cls"); //limpar a interface
		
	
		
	setlocale(LC_ALL, "portuguese");// colocar a ortografia certa
	
	
	printf("\t Cartorio da Ebac\n\n\n");//menu
	printf("escolha a op��o desejada:\n\n");//inicio das esoclhas
	printf("1-cadsatrar usuario\n");
	printf("2-consultar usuarios\n");
	printf("3-deletar usuario\n");
	printf("4-sair\n\n");
	printf("op��o desejada:");
	
	scanf("%d", &opcao);//pausa o programa e espera a resposta do ussuario
	
	system("cls");
	
	switch (opcao){//escolhas
		
		case 1:
			registro();
			break;
			
		case 2:
			consulta();
			break;
			
		case 3: 
			deletar();
			break;
		
		case 4:
			printf("obrigado por acessar o site de resgistro da EBAC!\n\n");
			exit(0);
			break;
			
		
			
		default:	
			printf ("essa op��o esta indisponivel\n\n");
			system ("pause");
			break;//fim das escolhas
		
			
	}
	
	
	
	}
	
	
	
	
	
}
