#include <stdio.h>
#include <stdlib.h>

int main(void){

    /*
     *  Inicialmente, o programa irá definir um "perfil" ao usuário de acordo com seu salário, o perfil é nomeado com
     *  os números de 0 a 3
     *
     *  Cada perfil será equivalente a uma linha na matriz "taxas", que contém os valores da porcentagem da alíquota e a
     *  parecela a deduzir
     */

    float salario;
    int perfil;

    float taxas[4][2] = {   // Matri Contendo As taxas de cada perfil
        {0.075, 142.8},    // perfil 0
        {0.15, 354.8},     // perfil 1
        {0.225, 636.13},   // perfil 2
        {0.275, 869.36}    // perfil 3
    };                     // Como salarios abaixo de R$:1903,98 São Isentos do imposto, ele não entra na tabela

    printf("Digite o seu salário: ");
    scanf("%f", &salario);

    /*
     * Classifica o perfil da pessoa de acordo com o salario dela
     */

    // Determinando o Perfil Do usuário
    if(salario < 1903.98){ // Isento
        printf("Isento\n");
        exit(1);

    }else if(1903.99 < salario && salario < 2826.65){ // Perfil 0
        perfil = 0;

    }else if(2826.66 < salario && salario < 3751.05){ // Perfil 1
        perfil = 1;

    }else if(3751.06 < salario && salario < 4664.68){ // Perfil 2
        perfil = 2;

    }else{
        perfil = 3; // Perfil 3

    }

    /*
     *  Processo para calcular o imposto devido
     *
     *  taxas[PERFIL][X];
     *  
     *  Se:
     *      X = 0   --->    Aliquota
     *      X = 1   --->    Parcela a deduzir
     */

    float impostoDevido = (salario * taxas[perfil][0]) - taxas[perfil][1];

    printf("Imposto devido: %.2f\n", impostoDevido);

    return 0;
}

