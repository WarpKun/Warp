#include <stdio.h>// biblioteca de comunicação com o ussuario
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>// biblioteca de alocação de texto por região
#include <string.h>// biblioteca responsavel pelas strings

int registro() //responsavel por cadastrar os usuários no sitemas
{	
	char arquivo[30];//criação de variaveis/variaveis
	char cpf[30]; // char= caractere, 30= maximo de caracteres a ser digitados
	char nome[30];//criando a opção para o usúario responder essas questões
	char sobrenome[30];
	char cargo[30];
	
	printf("digite o cpf a ser cadastrado:");//coletando informação do usuário
	scanf("%s", cpf); //armazenar a informação na string e depois ler. string= registro de texto
	
	strcpy(arquivo , cpf);//responsavel por copiar os valores das strings
	
	FILE*file; // procurar na biblioteca um FILE (arquivo) e pedindo ele para criar um file ( criar um novo arquivo)
	file =fopen(arquivo, "w"); //abrir o arquivo e esvrever nele o que foi passado (Write)
	fprintf(file,cpf); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file=fopen(arquivo, "a"); // A= atualizar uma informação
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
		printf("essas são as informações do usuario:");
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
		printf("usuário nao encontrado!\n");
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
	printf("escolha a opção desejada:\n\n");//inicio das esoclhas
	printf("1-cadsatrar usuario\n");
	printf("2-consultar usuarios\n");
	printf("3-deletar usuario\n");
	printf("4-sair\n\n");
	printf("opção desejada:");
	
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
			printf ("essa opção esta indisponivel\n\n");
			system ("pause");
			break;//fim das escolhas
		
			
	}
	
	
	
	}
	
	
	
	
	
}
