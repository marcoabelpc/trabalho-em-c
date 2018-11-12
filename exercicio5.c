#include <stdio.h>

/*
 * Funçao que calcula a média das notas
 *
 * A equação dada foi simplificada a fins de simplicidade
 *
 * ANTES:
 *
 * { 20[sigma(apols) / 5] + 20PO + 30PD + 30AP }} / 100
 *
 * DEPOIS:
 *
 * { 2[ sigma(apols) / 5  + PO  ] + 3(PD + AP) } / 10
 */

float calcula_nota_final(float apol1, float apol2, float apol3, float apol4, float apol5, float po, float pd, float ap, float *nota_aluno) {

    float nota_final;

    nota_final = ((2 * (((apol1 + apol2 + apol3 + apol4 + apol5) / 5) + po)) + (3 * (pd + ap))) / 10;
    
    *nota_aluno = nota_final; // é pedido um ponteiro que aponta para uma variavel para armazenar a nota do aluno, para que, desta forma
                              // o valor seja mantido ao programa terminar de execultar a função, do contrário, o valor seria resetado

    if(nota_final < 29) {  // Checagem das notas
        return 0; // Reprovado
    }else if(nota_final < 69 && nota_final > 30) {
        return 2; // Nas Provas Finais
    }else{
        return 1; // Aprovado
    }    


}

/*
 *  Funçao main 
 *      Inicialmente, todas as notas são carregas para varíaveis através de um scanf
 *
 *      Logo após, a função descrita anteriormente é chamada, e todos aqueles valores capturados são passados por parametro para
 *  ela, seu retorno é um valor de 0 a 2 que determina se o aluno está aprovado, ou não. Tal valor é armazenado em uma variável chamada
 *  "status"
 */

int main(void){

    int status;

    /*
     *  Note abaixo as variáveis "nota_aluno" e "pNota_aluno", uma será responsável por armazenar a nota gerada na função "calcula_nota_final"
     *  e a outra será responsável por armazenar o endereço de memória da variável "nota_aluno"
     *  A função "calcula_nota_final" irá pedir o endereço de memória de uma variável para armazenar o valor da nota final do aluno
     */

    float apol1, apol2, apol3, apol4, apol5, po, pd, ap, nota_aluno, *pNota_aluno = &nota_aluno; // Notas das avaliações

    //Captura das notas das apols
    printf("Digite a nota_final da apol1: ");
    scanf("%f",&apol1);
    printf("Digite a nota_final da apol2: ");
    scanf("%f",&apol2);
    printf("Digite a nota_final da apol3: ");
    scanf("%f",&apol3);
    printf("Digite a nota_final da apol4: ");
    scanf("%f",&apol4);
    printf("Digite a nota_final da apol5: ");
    scanf("%f",&apol5);

    //captura da nota das demais avaliações
    printf("Digite a nota_final da po: ");
    scanf("%f",&po);
    printf("Digite a nota_final da pd: ");
    scanf("%f",&pd);
    printf("Digite a nota_final da ap: ");
    scanf("%f",&ap);

    // Armazenando o status do aluno: aprovado, provas finais ou reprovado
    status = calcula_nota_final(apol1, apol2, apol3, apol4, apol5, po, pd, ap, pNota_aluno);

    // Apresentando Ao Usuário o resultado
    printf("nota final: %.2f    |     Status: ", nota_aluno);
    
    if(status == 1){
        printf("Aprovado\n\n");
    }else if(status == 2) {
        printf("Nas Provas Finais\n\n");
    }else{
        printf("Reprovado\n\n");
    }
    
}

