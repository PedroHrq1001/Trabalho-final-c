int media5x5(int altura, int largura, int **matriz, int **matrizm);
int media5x5(int altura, int largura, int **matriz, int **matrizm){

	int i=0,j=0;

	int matriz0[altura+4][largura+4];	// DEFINE A MATRIZ QUE VAI SER UTILIZADA PARA SER EDITADA UTILIZANDO A MÉDIA.
	int f=0;
	int v=0,d=0;
	int poi=0;
	int media[5][5]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Matriz da média
	i=0;
	j=0;
	
	for(i=0;i<altura+4;i++){   //faz uma matriz só com zeros para receber a imagem e criar as bordas(0);
             
       for(j=0;j<largura+4;j++){
           matriz0[i][j] =0;
		   printf("%d  ", matriz0[i][j]);
       }
		printf("\n");	
	}
	i=0;
	j=0;
	printf("\n");
	for(i=2;i<=altura+1;i++){       //INSERE A IMAGEM NA MATRIZ ZERADA
             
       		for(j=2;j<=largura+1;j++){
           		matriz0[i][j] = matriz[i-2][j-2];
			printf("%d  ", matriz0[i][j]);
		}
		printf("\n");	
	}
			
	i=0;
	j=0;
	printf("\n");
	for(i=0;i<altura+4;i++){ //Printa a imagem da matriz para ver se ocorreu tudo certo com as bordas
             
       for(j=0;j<largura+4;j++){
		   printf("%d  ", matriz0[i][j]);
       }
		printf("\n");
	}
	printf("\n");

	i=1;
	j=1;
	for(i=2,v=0;i<=altura+1;i++,v++){ // calcula a média  usando a matriz zerada               
		
		for(j=2,d=0;j<=largura+1
		
		;j++,d++){

			 			media[0][0]=matriz0[i-2][j-2];
			 			f+=media[0][0];
			 			media[0][1]=matriz0[i-2][j-1];
			 			f+=media[0][1];
			 			media[0][2]=matriz0[i-2][j];
			 			f+=media[0][2];
			 			media[0][3]=matriz0[i-2][j+1];
			 			f+=media[0][3];
			 			media[0][4]=matriz0[i-2][j+2];
			 			f+=media[0][4];
			 			media[1][0]=matriz0[i-1][j-2];
			 			f+=media[1][0];
			 			media[1][1]=matriz0[i-1][j-1];
			 			f+=media[1][1];
			 			media[1][2]=matriz0[i-1][j];
			 			f+=media[1][2];
			 			media[1][3]=matriz0[i-1][j+1];
			 			f+=media[1][3];
			 			media[1][4]=matriz0[i-1][j+2];
			 			f+=media[1][4];
			 			media[2][0]=matriz0[i][j-2];
			 			f+=media[2][0];
			 			media[2][1]=matriz0[i][j-1];
			 			f+=media[2][1];
			 			media[2][2]=matriz0[i][j];
			 			f+=media[2][2];
			 			media[2][3]=matriz0[i][j+1];
			 			f+=media[2][3];
			 			media[2][4]=matriz0[i][j+2];
			 			f+=media[2][4];
			 			media[3][0]=matriz0[i+1][j-2];
			 			f+=media[3][0];
			 			media[3][1]=matriz0[i+1][j-1];
			 			f+=media[3][1];
			 			media[3][2]=matriz0[i+1][j];
			 			f+=media[3][2];
			 			media[3][3]=matriz0[i+1][j+1];
			 			f+=media[3][3];
			 			media[3][4]=matriz0[i+1][j+2];
			 			f+=media[3][4];
			 			media[4][0]=matriz0[i+2][j-2];
			 			f+=media[4][0];
			 			media[4][1]=matriz0[i+2][j-1];
			 			f+=media[4][1];
			 			media[4][2]=matriz0[i+2][j];
			 			f+=media[4][2];
			 			media[4][3]=matriz0[i+2][j+1];
			 			f+=media[4][3];
			 			media[4][4]=matriz0[i+2][j+2];
			 			f+=media[4][4];
			 			
                		pou=f/25;
                		matrizm[v][d]=pou; //Insere a média na matriz final
                		pou=0;
                		f=0;
		}
	}
        i=0;
	j=0;
	for(i=0;i<altura;i++){ //Printa a matriz final                  
		
		for(j=0;j<largura;j++){
			printf("%d  ", matrizm[i][j]);
			}
		printf("\n");
		}
	return 0;
}
