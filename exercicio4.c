#include <stdio.h>
#include <stdlib.h>

#define TAM_RU 7


int main()
{
    int tam_l, tam_c, l, c, l1, i, digito_ru;

    char ru[TAM_RU], ch_digito_ru[] = "00";

    /*
     *  O algorímimo usado para a obtenção dos ultimos digitos da ru é o mesmo utilizado no exercíco anterior,
     *  portanto, dispença explicações a respeito de seu funcionamento
     */

    printf("Digite sua RU: "); // Primeiro passo
    scanf("%s", &ru);

    ch_digito_ru[0] = ru[TAM_RU - 2];
    ch_digito_ru[1] = ru[TAM_RU - 1];

    digito_ru = atoi(ch_digito_ru);

    /*
     *  O usuário entrará com o tamanho da matriz que o programa trabalhará, a entrada será no formato (linha)x(coluna)
     *
     *  EX:
     *
     *  Uma matrix 5x5, bastará o usuário entra com o valor "5x5", sem as àspas
     */

    printf("Entre com o tamanho da matriz abaixo na forma (linhas)x(colunas): ");
    scanf("%ix%i", &tam_l,&tam_c);

    // Realiza a checagem para saber se a matriz cumpre o tamanho (menor que 5x5);

    if(tam_l > 5 || tam_c > 5) {
        printf("A matriz deve ser no máximo 5x5\n");
        exit(1);
    }

    int m1[tam_l][tam_c], m2[tam_l][tam_c], m_resultante[tam_l][tam_c]; // Declarando as matrizes de acordo com os 
                                                                        // tamanhos entrados
    int *pM1 = &m1[0][0], *pM2 = &m2[0][0], *pM_resultante = &m_resultante[0][0]; // Declarando ponteiros para cada matriz

    // Alimentando a primeira matriz
     
    printf("Entre com os valores da primeira matriz:\n");

    for(l = 0; l < tam_l; l++ ){
        for(c = 0; c < tam_c; c++){
            printf("--> ");
            scanf("%i",&m1[l][c]);
        }
    }

    printf("\n");
    
    // Alimentando a segunda matriz
    
    printf("Entre com os valores da segunda matriz:\n");

    for(l = 0; l < tam_l; l++ ){
        for(c = 0; c < tam_c; c++){
            printf("--> ");
            scanf("%i",&m2[l][c]);
        }
    }

    printf("\n");

    // Imprimindo os valores presentes na primeira matriz
    
    for(i=1; i < (tam_l * tam_c) + 1; i++ ){
        printf("%i ", *(pM1 + i -1));

        /*
         *  A matriz com l linhas e c colunas possui um total de L x C elementos, esse for percorrerá por todos os elementos.
         *
         *  Ao i se apresentar como múltiplo do número do colunas, será feita uma quebra de linha, para que os dados presentes na
         *  outra linha fiquem logo abaixo dos valores impressos anteriormente
         */

        if(i % tam_c == 0 && i > 1){
            printf("\n");
        }

    }

    printf("\n");

    // imprimindo os valores presentes na segunda matriz

    for(i=1; i < (tam_l * tam_c) + 1; i++ ){
        printf("%i ", *(pM2 + i -1));

        if(i % tam_c == 0 && i > 1){
            printf("\n");
        }

    }

    // Multiplicando as matrizes m1 e m2 e armazendo os valores na matriz m2
    
    for(l = 0; l < tam_l; l++) {
        for(c = 0; c < tam_c; c++){
            m_resultante[l][c] = 0;
            for(l1 = 0; l1 < tam_c; l1++)
                m_resultante[l][c] = m_resultante[l][c] + (m1[l][l1] * m2[l1][c]);
        }

    }

    printf("\n");

    // imprimindo os valores presentes na segunda matriz multiplicados pelos dois ultimos algarismos, armazenados em "digito_ru";
    
    for(i=1; i < (tam_l * tam_c) + 1; i++ ){
        printf("%i ", (*(pM_resultante + i -1)) * digito_ru);
    
        if(i % tam_c == 0 && i > 1){
            printf("\n");
        }

    }

    /*
     *  Tendo em vista que a diagonal da matriz sempre estará na forma m[x][x], o for abaixo percorre toda a diagonal de ambas as
     *  matrizes e vai somando o valor em uma variável chamada "somatorio"
     *  Logo após, ao ser apresentado, "somatorio" é multiplicado pelos dois ultimos numeros da ru do aluno, armazenados em digito_ru
     */

    int somatorio = 0;

    for(i = 0; i < tam_l; i++ ) {
        somatorio += m1[i][i]; // Diagonal

    }

    for(i = 0; i < tam_l; i++ ) {
        somatorio += m2[i][i]; // Diagonal
    }
    
    // Apresentando o resultado final
    printf("Somatorio das diagonais das duas matrizes x dois ultimos algarismos da ru = %i\n", somatorio * digito_ru);

    return 0;
}

