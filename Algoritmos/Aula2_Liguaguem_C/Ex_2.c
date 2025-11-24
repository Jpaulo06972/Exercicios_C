#include <stdio.h>

int main(){
    
    int segundos, minutos, horas;

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &segundos);
    
    minutos = segundos / 60;
    horas = minutos / 60;
    
    printf("Quantidade de Segundos: %i\n", segundos);
    printf("Quantidade de Minutos: %i\n", minutos);
    printf("Quantidade de Horas: %i\n", horas);
    
    return 0;

}