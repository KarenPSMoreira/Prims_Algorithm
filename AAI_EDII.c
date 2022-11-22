/*
============================================================================
	Name        : algoritmo-de-prim.c
	Author      : Arthur Antunes, Guilherme Henrique & Karen Moreira
	Version     : 1.0
	Description : Codigo desenvolvido para o trabalho autoinstrucional da
 	 	   		  disciplina de Estrutura de Dados II.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **matrizGrafo(int nV,int nA, int *pArray);
int algoritmoPrim(int **pMatrizGrafo, int vS);

int main(){
	
	int array[100];
	int *pArray;
	int **pMatrizGrafo;
	int nV, nA, i, vS, n, m;
	
	int choice;
		
		do{
			printf("\n\n\t============================================\n\n");
	        printf("\t\tMain Menu - Algoritmo de Prim\n\n");
	        printf("\t============================================\n\n");
	        printf("\t%c ESCOLHA A OPCAO DESEJADA:  \n\n", 26);
	        printf("\t  1  %c   Inserir Grafo \n\n", 16);
	        printf("\t  2  %c   Gerar Arvore(s) do Tipo MST\n\n", 16);
	        printf("\t  3  %c   Sobre o Algoritmo\n\n", 16);
	        printf("\t  4  %c   Sair\n", 16);
	        printf("\t____________________________________________   \n\n\t  %c     ", 26);
	        
	    	scanf("\n%d", &choice);
	    	
	    	printf("\t____________________________________________   \n\n");
        
        	switch(choice) {
        		case 1: 
        			fflush(stdin);
           	 		printf("\n\tInforme o numero de elementos: ");
            		scanf("%i", &nV);
            		
            		for(i=0; i<nV;i++){
            			array[i]=i;
					}
					pArray = &array[0];
            		array[nV];
            		
            		do {
		                printf("\n\tInforme o numero de arestas: ");
		                scanf("%d", &nA);
		                if (nA > ((((nV * nV) - nV) / 2))){
		                    printf("\n	Invalido! Informe um valor entre 1 e %d\n", (((nV * nV) - nV) / 2));
		                }
		            }while (nA > ((((nV * nV) - nV) / 2)) || nA < 1); // limite de arestas de um grafo simples

            		pMatrizGrafo = matrizGrafo(nV,nA,pArray);
            		
            		break;
            		
            	case 2:
            		printf("\n\tDigite o vertice S: ");
            		scanf("%d", &vS);
            		
            		algoritmoPrim(pMatrizGrafo,vS);
            		
            	
            	case 3:
	            	printf("\t O algoritmo consiste numa solucao para \n\t encontrar um arvore geradora de custo \n\t minimo de um grafo nao-dirigido \n\t com custos nas arestas.");
					printf("\n\n");
					printf("\t Os custos das arestas sao dados por \n\t numeros inteiros arbitrarios.");
					printf("\n\n");
					printf("\t O algoritmo apresenta solucao apenas \n\t para grafos conexos.");
					
					break;
				case 4:
					printf("\t Construido por:\n");
					printf("\t Arthur Antunes\n");
					printf("\t Guilherme Henrique\n");
					printf("\t Karen Moreira\n\n");
						
						
					printf("\t Programa Finalizado! Bye-bye :)\n");
					break;
        			
				default:
					printf("\n\t\t  Insira uma opcao valida!");
            		break;
			}			

        	
		} while (choice != 4);
	
}

int **matrizGrafo(int nV, int nA, int *pArray){
	
	int n, m, peso, aux1, aux2, v1, v2, valido=1;
	
	int **pMtrGrafo = malloc(nV * sizeof(*pMtrGrafo)); // alocando memoria
	for(n=0; n<nV; n++){
		pMtrGrafo[n]= malloc(nV*sizeof(*pMtrGrafo[n]));
		for(m=0; m<nV; m++){
			pMtrGrafo[n][m] = 0;	
		}
	}
	
	printf("\n\tA seguir, informe o valor de peso de cada aresta. Considere:\n\t\t - Se a aresta nao existir, o peso sera 0;\n\t\t - Se o peso for infinito, digite -1;\n");
	
	for(m = 0; m < nA; m++){
		printf("\n\n\t%c a%d : {\n", 26, m + 1);
        do{ // valida se o v1 existe dentro do array
            fflush(stdin);
            fprintf(stdout, "\t\tv1 = ");
            scanf("%d", &v1);
            for (n = 0; n < nV; n++){
                if (v1 == pArray[n]){
                    valido = 1;
                    aux1 = n;
                    break;
                }else{
                    valido = 0;
                }
            }
            if (valido == 0)
            {
                printf("\n\tVertice invalido. Tente novamente\n\n");
            }
        } while (valido == 0);

        do{ // valida se o v2 existe dentro do array
            fflush(stdin);
            printf("\t\tv2 = ");
            scanf("%d", &v2);
            for (n = 0; n < nV; n++){
                if (v2 == v1)
                {
                    valido = 0;
                    break;
                }else if (v2 == pArray[n]){
                    valido = 1;
                    aux2 = n;
                    printf("\t\t}\n");
                    break;
                }else{
                    valido = 0;
                }
            }
            
            if (valido == 0){
                printf("\n\tVertice invalido. Tente novamente\n\n");
            }
              
        } while (valido == 0);
        
        printf("\t  peso: ");
        scanf(" %d", &peso);
            
        pMtrGrafo[aux1][aux2] = pMtrGrafo[aux2][aux1] = peso;
	}
	/*
	printf("\n\n\t\tMATRIZ DO GRAFO\n\n\t\t"); // imprimir matriz
            
			for (n = 0; n < nV; n++)
            {
                printf("|%d\t", pArray[n]);
            }
        
        for (n = 0; n < nV; n++)
    	{
        printf("\n\t%d\t", pArray[n]);
        for (m = 0; m < nV; m++)
        {
            printf("|%d\t", pMtrGrafo[n][m]);
        }
    }*/
	
	return pMtrGrafo;
	
}

int algoritmoPrim(int **pMatrizGrafo, int vS){
	
}


