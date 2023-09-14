#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define true 1
#define false 0






int main(void){

char path_arquivo_fonte[200] = "C:\\Matheus";

char string[200];
getcwd(string, sizeof(string));
printf("%s\n",string);



FILE* source;
source = fopen(path_arquivo_fonte, "r");
if(source == NULL){
    printf("FODEU");
}

// tamanho maximo de token sera de 255 caracteres
int TAM_MAX_TOKEN = 255;
// por enquanto nao leva em consideracao o caracter '\n' !!!!!!
char* string_source = malloc(TAM_MAX_TOKEN * sizeof(char));
fgets(string_source, TAM_MAX_TOKEN, source);

int num_carac = 0;
char car = string_source[0];
while(car != '\0'){
    num_carac++;
    car = string_source[num_carac];
}

int accept = false;


int pos_atual = 0;
int estado = 1; //inicio
int pos_inicio = 0;
while(estado < 5 && pos_atual < num_carac){
    char car_lido = string_source[pos_atual];
    pos_atual++;

    switch(estado){
        case 1:
            if(car_lido == '/') estado = 2;
            else{
                pos_inicio = pos_atual;
                continue;

            }

            break;
        case 2:
            if(car_lido == '*') estado = 3;
            else{
                pos_inicio = pos_atual;
                estado = 1;
                continue;
            }
            break;

        case 3:
            if(car_lido == '*'){
                estado = 4;
            }
            else{
                continue;
            }
            break;
        case 4:
            if(car_lido == '*'){
                continue;
            }
            else if(car_lido == '/'){
                estado = 5;
            }
            else{
                estado = 3;
            }
            break;

    }





}
if(estado == 5) accept = true;
else accept = false;

char* str = malloc((pos_atual - pos_inicio + 1) *sizeof(char));
for(int i = 0; i <= pos_atual; i++){
    str[i] = string_source[pos_inicio + i];
}
printf("%s\n", str);

if(accept == true){
    printf("Resultado: true");
}else{
    printf("Resultado: false");
}

return 0;
}