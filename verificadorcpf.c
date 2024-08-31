#include <stdio.h>
#include <stdbool.h>
bool todosIguais(int cpf[])
{
    int i;
    for(i=1; i<11;i++){
        if(cpf[0] != cpf[i]) return false;
    }
    return true;
}

int calculaDigito(int cpf[], int mult[], int N){
    int i;
    int soma=0;
    for(i=0;i<N;i++)
    { soma+= cpf[i]*mult[i];
    }
    return ((soma*10)%11)%10;
}

int main()
{
    int cpf[11];
    int m1[9]={10,9,8,7,6,5,4,3,2};
    int m2[10]={11,10,9,8,7,6,5,4,3,2};
    int i, tam;
    char entrada[20];
    printf("Insira o seu CPF: ");
    fgets(entrada, 20, stdin);
    tam=strlen(entrada);
    for(i=0;i<tam;i++){
        int j;
        if(entrada[i]>=48 && entrada[i]<=57){ 
            cpf[j]=entrada[i]-48;
            j++;
        }
    }
    if(!todosIguais(cpf) &&
        calculaDigito(cpf, m1, 9) == cpf[9] && 
        calculaDigito(cpf, m2, 10) == cpf[10]){
        printf("\nCPF válido.");
    } 
    else printf("\nErro no CPF.");
    return 0;
}
