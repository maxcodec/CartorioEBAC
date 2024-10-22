#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include<string.h>  //biblioteca responsavel por cuidar das strings

int registro() //Fumncao responsavel por cadastrar os usuarios
{
	//incio da cria�ao de variaveis/strings
    char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da cria�ao de variaveis/strings
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informacoes do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores de string

	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w");//cria o arquivo e o "W" significa escrever
	
	fprintf(file, "\nCPF: ");
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo 
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nNOME: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nSOBRENOME: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCARGO: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo); 
	
	file = fopen(arquivo, "a");
   	fprintf(file, cargo);
   	printf("\n");
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause");
	
}	

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	printf("\n");
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if(file == NULL)
	{
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n\n");
    }
    
    printf("Essas s�o as informa��es do us�ario: ");
	printf("\n");
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("%s", conteudo);
	}	
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
    printf("\n");
	printf("Usu�rio deletado com sucesso!\n\n");
	system("pause");	
	}
	system("pause");
}

int main() //Definindo variaveis
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
{
		
		system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("### Cartorio EBAC ###\n\n"); //inicio do menu
	printf("Escolha a opcao desejada do menu\n\n");
	printf("\t1 - Registar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Op��o: "); //Fim do menu
	
	scanf("%d", &opcao); //Armazenando escolhas do usuario
	
	system("cls"); //Responsavel por limpar a tela 
	
	switch (opcao) //Inicio da sele�ao do menu
{
		case 1:
		registro(); // Chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("essa op��o n�o esta disponivel\n");
		system("pause");
		break;	
} //Fim da sele��o
	
}

}  
