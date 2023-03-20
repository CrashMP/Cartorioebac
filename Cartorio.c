#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40]; //O que est� em "[]" se refere a quantidade de caracteres
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string ("%" � usado para salvar)
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo ("W" significa write)
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" serve para atualizar a informa��o, ele inclue mais informa��es no arquivo citado
	fprintf(file,","); //Salva a informa��o (valor da vari�vel)
	fclose(file); //� necess�rio sempre fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); // "%s" salva string, sempre salve a informa��o
	
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
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40]; //Aquivo "CPF" a ser sempre consultado pelos comandos abaixo
	char conteudo[200]; // Conte�do do arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Cria o arquivo ("R" significa read)
	
	if(file == NULL) //Se o arquivo for nulo (NULL), ent�o:
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto (while) tiver conte�do dentro do arquivo, ele armazena na vari�vel conte�do (com a capacidade de at� 200), e a mensagem abaixo aparece, caso n�o tenha, vindo este a ser nulo, ele n�o executa a a��o
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	if(remove(cpf) == 0)
	{
		printf("CPF deletado com sucesso!\n");
		system("pause");
	}
	else
	{
		printf("CPF n�o encontrado!\n");
		system("pause");
	}
	return 0;
    
}

int main() //Definindo vari�veis - fun��o principal
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
			
    	setlocale(LC_ALL, "Portuguese"); //� necess�rio colocar em pt para a utiliza��o de acentos
	
    	printf("### Cart�rio da EBAC ###\n\n");
    	printf("Escolha a op��o desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n"); //BarraT � par�grafo
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("Op��o: ");
	
    	scanf ("%d", &opcao); //armazenando escolha do usu�rio
	
    	system("cls"); //Respons�vel por limpar a tela
    	
    	
    	switch(opcao) //In�cio da sele��o do menu
    	{
    		case 1:
    		registro(); // Chamada de fun��es (as 3 abaixo s�o a mesma coisa)
	    	break;
	    	
	    	case 2:
	    	consulta();
    		break;
    		
    		case 3:
    		deletar();
    		break;
    		
    		default: //Default pois a mensagem ir� aparecer somente caso nenhum dos casos acima ocorrer
    		printf("Essa op��o n�o est� dispon�vel!\n");
    		system("pause");
    		break;
		} //Fim da sele��o
   }
}
