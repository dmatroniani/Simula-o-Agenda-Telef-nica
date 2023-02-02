#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"agenda2.h"




//criando agenda vazia (OPCAO 2)

void criaAgendaVazia(Contato *principal){
	
	char *nome, c;
    char *telefone;
    
    nome = (char *)malloc(40);
    telefone = (char *)malloc(40);
//
  	//lendo string
	  
	  //Armazenando nome
	  
  	
	//scanf("%s", nome);
    
    printf("\n");
    
    //Armazenando telefone
    printf("\n\nInsira o telefone do contato: \n----> ");
    scanf("%s", telefone);
    printf("\n");
    
    //coloca dados na agenda principal
    free(principal);
    principal = iniciaDados(nome, telefone);
}

Contato *iniciaDados(char *nome, char *telefone){

 	Contato *novo;
 	
 	//Alocando memória para a posição atual da agenda
    novo = (Contato*)malloc(sizeof(Contato));
    
    //dados lidos
   // novo->nome = (char*)malloc(strlen(nome)+1);
    strncpy(novo->nome, nome, strlen(nome)+1);
   // novo->telefone = (char*)malloc(strlen(telefone)+1);
    strncpy(novo->telefone, telefone, strlen(telefone)+1);
    

    //Apontando para a próxima posição da agenda
    novo->prox = NULL;
    return novo;
 	
 }

//________________________________________________________*


//inserindo contato (OPCAO 3)

char *maiuscula(char *str){
	
	int i;
	char *nome;
	
	nome = (char*)malloc(sizeof(char)*40);
	strcpy(nome,str);
	
	for(i=0; i<strlen(nome); i++){
		toupper(nome[i]);
	}
	
	return nome;
	
}
// lendo string
//char lestring(char str){
//	char c,str;
//	int i=0;
//
  //  	while((c=getchar())!= '\n'){
		
    //		str[i]=c;
    //		i++;  }
    	
  //  n//ome[i]= '\0';
   
	
//	re//turn nome;
	
	
	

Contato *insereContato(Contato *contato, char *nome, char *telefone){
	
	Contato *novo;
	Contato *aux;
	Contato *inicio;
	
	//Alocando memória para a posição atual
    novo = (Contato*)malloc(sizeof(Contato));
    
    //lançando os dados lidos
  	strcpy(novo->nome, nome);
   	strcpy(novo->telefone, telefone);
    
    novo->prox = NULL;
    inicio = contato;
	
    
    if(contato == NULL) {
    	return novo;
    	
	} else {
		
		if(strcmp(maiuscula(novo->nome),maiuscula(contato->nome))<0){
			novo->prox = contato;
			return novo;
			
		}else{
			while(strcmp(maiuscula(novo->nome),maiuscula(contato->nome))>0){
	
				aux = contato;
				contato = contato->prox;
				
				if(contato==NULL){
					
					aux->prox = novo;
					return inicio;
				}
			}
			
			aux->prox=novo;
			novo->prox = contato;
			return inicio;
			
		}
		
	
	}
   

///


    
}

//________________________________________//

//Imprime lista (OPCAO 7)



void imprimeLista(Contato *dados) {
	
	int i=0;
	
	printf("\nAGENDA:\n\n");
   	printf("------------------------\n");
   		 
	//Exibindo todos os valores da lista
	//como sei que começou do inicio?
	for (; dados != NULL; dados = dados->prox) {
        printf("Nome: %s\n", dados->nome);
        printf("Telefone: %s\n", dados->telefone);
        printf("\n------------------------\n");
    }
 
	
}
 
//_________________________________________________________

//criando arquivo bin (OPCAO 8) (falta por os dados dentro do arquivo)
void salvaAgenda(Contato *contato){
	
	//nome do arquivo
	char nomeArquivo[20];
	

	//pedindo nome do arquivo pra salvar
	printf("\n Insira o nome para salvar o arquivo:\n");
	scanf("%s", &nomeArquivo);

	//criando arquivo bin na pasta 
	FILE *file;
	file = fopen(nomeArquivo, "wb");
	
	for (; contato != NULL; contato = contato->prox) {
		
		fwrite(contato,sizeof(Contato),1,file);


	}
	fclose(file);
	printf("\n");
				
}


