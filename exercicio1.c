#include <stdio.h>
#include <stdlib.h>

#define MOD(x) ((x)>=0?(x):-(x))   // Definição de modulo de x: se o numero for menor que 0 ele sera multiplicado por menos um
                                   // Do contrario, retornara o proprio numero

/*
 *  Funçaõ fatal -> Usada para expor as mensagens de erro e sair do programa logo após
 */

int fatal(char *msg, int ret) {
    fprintf(stderr, msg);
    exit(ret);

}

int main(void){

    int x, y, z; // varíaveis que irão armazenar os lados do triangulo

    printf("Digite o valor de x: ");   // processo paraa azenar as entradas nas variáveis
    scanf("%i", &x);
    printf("Digite o valor de y: ");
    scanf("%i", &y);
    printf("Digite o valor de z: ");
    scanf("%i", &z);

    /*
     * PRIMEIRA VALIDACAO => Como é impossivel um triangulo que possua um dos seus lados nulos, primeiro
     * é checado se nenhuma das entradas é nula
     */

    if(x <= 0 || y <= 0 || z <= 0) 
        fatal("Não pode haver um triangulo com um dos lados nulos ou negativos\n", 1);

    /*
     * SEGUNDA VAILIDAÇÃO => Em um triangulo válido, a medida de qualquer um dos lados deve ser maior que
     * o módulo da diferença dos lados oposotos a ele e, ao mesmo tempo, menor que a soma dos lados ospostos,
     * portanto:
     *
     * Sejam x, y e z os lados de um triangulo
     *
     * |x - y| < z < x + y
     * |x - z| < y < x + z
     * |z - y| < x < z + y
     */

    if(!(MOD(x - y) < z < x + y))
        if(!(MOD(x - z) < y < x + z))
            if(!(MOD(z - y) < y < z + y))
                fatal("Impossivel haver um triangulo com esses lados\n", 1);

    printf("O tringulo é que possui os lados %i, %i e %i é ", x, y, z);

    /*
     * No trecho abaixo será analizada relação entre os lados do triangulo da seguinte forma
     *
     * ISÓCELES => Se o tringulo possuir dois lados com mesmo tamanho
     * logo, se X = Z, ou se X = Y oy se Y = Z
     *
     * porém, se haver mais um lado igual, o triangulo será EQUILÁTERO
     *
     * ESQUILÁTERO => 
     *  Se x = y, x = z e z = y
     *  Podemos simplificar o sistema, chegando a
     *  
     *  Se x = y e y = Z
     *
     *  Então, se um tringulo isóceles possuir x = y ou y = z ele será equilátero
     *
     *  ESCALENO => Caso não cumpra nenhuma das exigências anteriores, ele será escaleno
     *
     */

    if((x == y) ||  (x==z) || (y==z)) {
        if((x==y) && (y==z)) 
            printf("equilátero\n");
        else
            printf("isóceles\n");
    }else 
        printf("escaleno\n");
    


    return 0;
}

