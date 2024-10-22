#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include<string.h>  //biblioteca responsavel por cuidar das strings

int registro() //Fumncao responsavel por cadastrar os usuarios
{
	//incio da criaçao de variaveis/strings
    char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criaçao de variaveis/strings
	
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
	printf("Não foi possivel abrir o arquivo, não localizado!.\n\n");
    }
    
    printf("Essas são as informações do usúario: ");
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
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
    printf("\n");
	printf("Usuário deletado com sucesso!\n\n");
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
	printf("Opção: "); //Fim do menu
	
	scanf("%d", &opcao); //Armazenando escolhas do usuario
	
	system("cls"); //Responsavel por limpar a tela 
	
	switch (opcao) //Inicio da seleçao do menu
{
		case 1:
		registro(); // Chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("essa opção não esta disponivel\n");
		system("pause");
		break;	
} //Fim da seleção
	
}

}  
