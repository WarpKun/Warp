#include <stdio.h>// biblioteca de comunicação com o ussuario
#include <stdlib.h>//biblioteca de alocação de espaço em memoria
#include <locale.h>// biblioteca de alocação de texto por região
#include <string.h>// biblioteca responsavel pelas strings


int registro() //Função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    printf("cadastro realizado com sucesso!\n\n");
	system("pause");
	system("cls");

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
	}
	
	fclose(file);
	system("pause");
	system("cls");
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
		system("cls");
	}
	else
	{	
		fclose(file);
		remove(cpf);
		FILE*file;
		file=fopen(cpf,"r");
		if (file== NULL)
		{ 	printf("usuario deletedo com sucesso");
			system("pause");
		}
	}
	fclose(file);	
	}


int main()
	{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("\n\nCartório da EBAC\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");
		for(laco=1;laco=1;)//repetidor
		{	

			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
			
			printf("\n\nCartorio da EBAC\n\n"); //inicio do menu
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: ");//fim do menu
				
			scanf("%d", &opcao); //pausa o programa e espera a resposta do ussuario
		
			system("cls"); //limpar a interface
	
			switch(opcao) //escolhas
			{
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
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
	
				default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;
			} //fim das escolhas
		}
	}
	
	else
		printf("Senha incorreta!");	

}












