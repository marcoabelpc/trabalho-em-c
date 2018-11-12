#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_RU 7

// Função definida com o propósito de apresentar os eventuais erros que o programa pode ter.
void fatal(char *msg, int ret);

int main(void){
    
    /*
     * Inicialmente, haverá um processo para se capturar a ru do aluno, que seu funcionamento será explicada mais
     * a frente.
     *
     * O usário dirá com quantas posições o vetor deverá ter.
     * Logo após, será realizado uma checagem para saber se o vetor não possui mais que 100 posições.
     * Para cada numero entrado é checado seu módulo ao ser dividido por dois, caso zero, o número é
     * dado como par, do contrário, é dado como impar.
     * Os números pares e impares são divididos entre dois vetores, o "vetor_pares" e o "vetor_impares".
     * Ao ser identificado como impar, antes de ser adicionado a "vetor_impares", o número é multiplicado
     * pelos dois ultimos digitos da ru do aluno, armazenado em "digito_ru"
     */

    int tam_vetor, tam_vetor_pares = 0,p,i,c, digito_ru;

    char ru[TAM_RU], ch_digito_ru[] = "00";

    // Capturando a RU para um vetor de chars chamado "ru"
    printf("Digite sua RU: ");
    scanf("%s", &ru);

    //Pegando os dois ultimos chars do vetor "ru"
    ch_digito_ru[0] = ru[TAM_RU - 2];
    ch_digito_ru[1] = ru[TAM_RU - 1];

    /*
     *Os dois ultimos números, que estavam armazenados em um vetor do tipo CHAR, agora serão convertidos a apenas um algarismo
     *do tipo INTEGER, Para Isso, será utilizada a função "atoi", que recebe um *char e retorna um int
     */

    digito_ru = atoi(ch_digito_ru);

    // Entrando com o tamanho do vetor e o armazendondo na variavel tam_vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &tam_vetor);
    
    // Checagem Para Ver se o vetor não possui mais que 100 posições
    if(tam_vetor > 100)
        fatal("Erro, não pode ser maior que 100 posições\n", 1); // Mensagem de erro, Caso O vetor possua mais do que 100 posições

    // Declaração do vetor
    int vetor[tam_vetor];

    // Alimentando o vetor com um scanf
    for(c = 0; c < tam_vetor; c++) {
        printf("--> Digite o %iº valor: ", c+1);
        scanf("%i", &vetor[c]);
        
        /*
         * Caso um numero seja identificado como par, ao inves de ser diretamente adicionado ao vetor_pares, primeiro é contado quantos
         * pares haverão ao total, para que, desta forma, seja criado um vetor com o tamanho exato que será preciso.
         * Tal medida evitará disperdicio de memória em nosso programa
         */

        // Se Par, Adicione um à variável "tam(amnho)_vetor_pares"
        if(vetor[c] % 2 == 0){
            tam_vetor_pares++;
        }

    }

    int vetor_pares[tam_vetor_pares];
    int vetor_impares[tam_vetor - tam_vetor_pares]; // O numero de impares, logicamente, será igual ao número de posições totais no vetor,
                                                    // Menos O número de pares.

    /*
     *  As variáveis abaixo serão responsáveis por apontar para a posição do vetor com que o número par/impar ocupará ao ser adicionado
     */

    p = 0;  
    i = 0;

    for(c = 0; c < tam_vetor; c++) {
        if(vetor[c] % 2 == 0){
            vetor_pares[p] = vetor[c];
            p++; // Cada vez que um número é adicionado ao vetor, seu número é incrementado em um, de maneira que o próximo encontrado
                 // Ocupará Exatamente a posição seguinte;

        }else{
            vetor_impares[i] = vetor[c] * digito_ru; // Ao Ser Adicionado, o impar é multiplicado com os dois ultimos digitos presentes
            i++;                                     // Na Ru, Como Mandado no enunciado do exercício.
        }
    }
    
    printf("Sua RU: %s\n", ru); // Apresentando A Ru do aluno

    printf("Vetor contendo os numeros pares: "); // Imprime o vetor com os numeros pares

    for(c = 0; c < tam_vetor_pares; c++)
        printf("%i ", vetor_pares[c]);
    
    printf("\nVetor contendo os numeros impares multiplicados pelos dois ultimos algarismos da ru: "); // Imprime o vetor com os numeros impares

    for(c = 0; c < (tam_vetor - tam_vetor_pares); c++)
        printf("%i ", vetor_impares[c]);

    printf("\n");

    return 0;
}

void fatal(char *msg, int ret){
    fprintf(stderr, "%s", msg);
     exit(ret);

}

