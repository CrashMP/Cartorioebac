#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40]; //O que está em "[]" se refere a quantidade de caracteres
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string ("%" é usado para salvar)
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo ("W" significa write)
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" serve para atualizar a informação, ele inclue mais informações no arquivo citado
	fprintf(file,","); //Salva a informação (valor da variável)
	fclose(file); //É necessário sempre fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome); // "%s" salva string, sempre salve a informação
	
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
	char conteudo[200]; // Conteúdo do arquivo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Cria o arquivo ("R" significa read)
	
	if(file == NULL) //Se o arquivo for nulo (NULL), então:
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Enquanto (while) tiver conteúdo dentro do arquivo, ele armazena na variável conteúdo (com a capacidade de até 200), e a mensagem abaixo aparece, caso não tenha, vindo este a ser nulo, ele não executa a ação
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	if(remove(cpf) == 0)
	{
		printf("CPF deletado com sucesso!\n");
		system("pause");
	}
	else
	{
		printf("CPF não encontrado!\n");
		system("pause");
	}
	return 0;
    
}

int main() //Definindo variáveis - função principal
{
	int opcao=0;
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
			
    	setlocale(LC_ALL, "Portuguese"); //É necessário colocar em pt para a utilização de acentos
	
    	printf("### Cartório da EBAC ###\n\n");
    	printf("Escolha a opção desejada do menu:\n\n");
    	printf("\t1 - Registrar nomes\n"); //BarraT é parágrafo
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("Opção: ");
	
    	scanf ("%d", &opcao); //armazenando escolha do usuário
	
    	system("cls"); //Responsável por limpar a tela
    	
    	
    	switch(opcao) //Início da seleção do menu
    	{
    		case 1:
    		registro(); // Chamada de funções (as 3 abaixo são a mesma coisa)
	    	break;
	    	
	    	case 2:
	    	consulta();
    		break;
    		
    		case 3:
    		deletar();
    		break;
    		
    		default: //Default pois a mensagem irá aparecer somente caso nenhum dos casos acima ocorrer
    		printf("Essa opção não está disponível!\n");
    		system("pause");
    		break;
		} //Fim da seleção
   }
}
