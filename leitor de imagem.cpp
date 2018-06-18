#include <stdio.h>
#include <stdlib.h>

void learquivo(FILE *fp,char *buffer);

void converteparaint(char *buffer,int *numeros);

int proxnumero(FILE *fp,char *buffer,int *numeros);

int **AlocMatriz(int m, int n);

int **LibMatriz(int m, int n, int **v);

int main(){
	
	//arquivo e matriz com imagem original e imagem final
	FILE *fp;
	int **imagem;
	int **imagemfim;
	
	//altura,largura,tons,nome do arquivo a ser lido, largura eh a qualtidade de colunas que a imagem tem, e altura a quantidade de linhas
	int largura;
	int altura;
	int tons;
	char arquivo[80];
	
	//variaveis de controle de leitura: buffer e ponteiro pra vetor dos numeros, alem das variaveis i e j para colocar os dados na matriz
	char buffer[80];
	int numeros[45] = {0,0,0,0,0,0,0};
	int i,j;
	
	//variavel para escolher o modo de edi��o
	char modo;
	
	
	//na vers�o final descomentamos isso e tiramos o "teste" como padr�o
//	printf("digite o nome do arquivo original\n");
//	gets(arquivo);
//	
//	fp = fopen(arquivo, "r");	

	//nome temporario
	fp = fopen("teste.pgm", "r");
	
	
	learquivo(fp,buffer);
	if( !(buffer[0] == 'P' && buffer[1] == '2') ){
		printf("formato de arquivo incorreto\n");
		fclose(fp);
		exit(1);
	}
	
	largura = proxnumero(fp,buffer,numeros);
	altura = proxnumero(fp,buffer,numeros);
	tons = proxnumero(fp,buffer,numeros);
	
	printf("Sua imagem tem tamanho %d*%d, e %d tons de cinza\n",largura,altura,tons);
	printf("carregando imagem...\n");
	
	imagem = AlocMatriz(largura,altura);
	
	for(i = 0; i < largura; i++){
		for(j = 0; j < altura;j++){
			imagem[i][j] = proxnumero(fp,buffer,numeros);
		}
	}
	
	printf("imagem carregada\n\n");
	
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura;j++){
			printf("%3d ",imagem[j][i]);
		}
		printf("\n");
	}
	
	printf("o que deseja fazer%c\n\n",63);
	printf("1 - Mascara laplaciana 3x3\n");
	printf("2 - Media 3x3\n");
	printf("0 - Sair\n");
	
	scanf("%c",&modo);
	if(modo == '1'){
		//CODIGO DO KEV�O DA MASCARA
	}
	else if(modo == '2'){
		//CODIGO DO PEDRINHO DA MEDIA
	}
	else if(modo == '0'){
		printf("Nada foi feito\nSaindo...\n");
		LibMatriz(largura,altura,imagem);
		fclose(fp);
		exit(1);
	}
	
	
	//ainda preciso fazer o codigo pra escrever a imagem final num arquivo
	
	
	
	LibMatriz(largura,altura,imagem);
	fclose(fp);
	return 0;
}

void learquivo(FILE *fp,char *buffer){
		
		//a fun��o deste codigo � ler 1 linha do arquivo de imagem, e remover, se houver,os comentarios trocando o inicializador deles por "\0" e passando essa linha pro vetor "buffer"
		int count;
		
		//zerando o buffer pra n�o dar merda
		for(count=0;count<80;count++){
			buffer[count] = 0;
		}
		
		fgets(buffer,80,fp);
		
		//o # � o simbolo que se tem antes de algum comentario na image, e eu troco o "\n" por "\0" para garantir que o fim da linha � o fim da string 
		for(count=0;count<80;count++){
			if(buffer[count] == '#' || buffer[count] == '\n' || buffer[count] == '\0'){
				buffer[count] = '\0';
				break;
			}
		}
	}

void converteparaint(char *buffer,int *numeros){
	//essa fun��o tem a utilidade de pegar a linha s� composta de numeros da fun��o "learquivo" e os converter para inteiros
	int count,n;
	char straux[5];
	
	//numeros[0] � basicamente a quantidade de numeros que ainda tem no vetor, isso � usado para fazer uma pilha,boto no mesmo vetor e para economizar passagem de valores
	numeros[0] = 0;
	
	//aqui count vai passando pelo vetor procurando um numero "buffer[count] >= '0' && buffer[count] <= '9'" e se o encontra inicia um segundo for
	//esse segundo for come�a em n=0, e vai caminhando apos esse numero ja encontrado, ate achar o fim dele,a cada passo copia um char da string pra uma string auxiliar "straux" 
	//e quando encontra o fim do numero aumenta o contador numeros[0], marcando que encontrou mais um numero nessa linha
	//e ent�o converte essa string auxiliar, usando o atoi, para um numero inteiro, e insere esse numero na posi��o numeros[0](que � a quantidade de numeros,indice do ultimo) 
	for(count = 0; buffer[count] != '\0' ;count++){
		if(buffer[count] >= '0' && buffer[count] <= '9'){			
			for(n = 0; buffer[count + n] >= '0' && buffer[count + n] <= '9' ;n++){
				straux[n] = buffer[count + n];
			}
			numeros[0]++;
			numeros[numeros[0]] = atoi(straux);
			count = count+n;
			
			//zera a string auxiliar, evita tretas onde se le um numero com menos caracteres que o anterior ex: le 11,converte pra int corretamente ent�o le 5, converte 51(devia ser 5)
			for(n=0; n < 5 ; n++){
				straux[n] = 0;
			}
		}	
	}
	//como o vetor numeros foi passado por ponteiros n�o precisa de retorno
	
	
//	printa os numeros convertidos na execu��o atual, para debug
//	printf("numeros na linha :%d\n",numeros[0]);
//	for(count = 1;count <= numeros[0] ; count++){printf("%d ",numeros[count]);}
//	printf("\n\n");

}

int proxnumero(FILE *fp,char *buffer,int *numeros){
	//fun��o que organiza o vetor numeros como pilhar, primeiro verificando se ha mais de 1 numero na pilha, se n�o houver, ele pede mais
	//se tiver numeros ele coloca o primeiro valor em uma variavel auxiliar, move tudo 1 indice pra cima, e retorna a variavel auxiliar
	int temp = 0;
	int count;
	
	//o while � necessario para caso haja multiplas linhas de numeros, com comentarios por exemplo
	while(numeros[0] == 0){
		learquivo(fp,buffer);
		converteparaint(buffer,numeros);
	}
	
	//codigo debug que printa todo o vetor numeros, se o vetor numeros n�o estiver zerado na primeira execu��o, eh possivel descobrir aqui se deu merda
//	printf("recebido:\n");
//	for(count = 0;count <= numeros[0] ; count++){printf("%d ",numeros[count]);}
//	printf("\n");
	
	//tira do topo da pilha e bota numa var temporaria
	temp = numeros[1];
	//move toda a pilha pra cima
	for(count = 1; count < numeros[0];count++){
		numeros[count] = numeros[count+1];
	}
	//diminui a quantidade de numeros na pilha
	numeros[0]--;
	//retorna o numero do topo
	return temp;
}

int **AlocMatriz (int m, int n){
    int **v; 
    int i;
      if (m < 1 || n < 1) { 
        printf ("Erro: Parametro invalido\n");
           return (NULL);
    }
 
    v = (int **) calloc (m, sizeof(int *));

    if (v == NULL) {
        printf ("Erro: Memoria Insuficiente");
        return (NULL);
    }
 
    for ( i = 0; i < m; i++ ) {
        v[i] = (int*) calloc (n, sizeof(int));
    
           if (v[i] == NULL) {
               printf ("Erro: Memoria Insuficiente");
            return (NULL);
        }
    }
      return (v); 
}

int **LibMatriz (int m, int n, int **v){
    int  i; 
    if (v == NULL){
    return (NULL);
}
    if (m < 1 || n < 1) { 
    printf ("** Erro: Parametro invalido **\n");
    return (v);
    }
      for (i=0; i<m; i++){
        free (v[i]); 
        }
      free (v);      
      return (NULL);
}

