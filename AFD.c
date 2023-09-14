#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief definição dos estados através de uma enum
 */
typedef enum{
    ESTADO1 = 1, ESTADO2, ESTADO3, ESTADO4, ESTADO5
}estados_automato;

void getNextChar(char* lineString, char* simbolo, int pos){
    if(pos == -1)
        pos++;
    *simbolo = *(lineString + pos);
}
char* get_token(){

}
int main(){
    estados_automato estado = ESTADO1;
    char* lineString = "fadksjfkljdsf////*faksdjfkasjf/*/fasdjfkadsjf/*";
    int str_lenght = 0;
    int nesses_estados = (estado == ESTADO1 || estado == ESTADO2 || estado == ESTADO3 || estado == ESTADO4);
    //printf("lenght: %d\n", str_lenght);
    char simbolo = ' ';
    int pos = -1;
    //str_comment receberá o comentario ao final de toda manipulação
    char* str_comment = malloc(sizeof(char) * 100);
    while(nesses_estados && (str_lenght <= strlen(lineString))){
        switch(estado){
            case ESTADO1:
                getNextChar(lineString, &simbolo, pos);
                switch(simbolo){
                    case '/':
                        estado = ESTADO2;
                        str_comment[pos] = simbolo; 
                        printf("%c", simbolo);
                        break;
                    default:
                        printf("%c", simbolo);
                        str_comment[pos] = simbolo; 

                }
                break;
            case ESTADO2:
                //simbolo -> função
                getNextChar(lineString, &simbolo, pos);
                switch(simbolo){
                    case '*':
                        estado = ESTADO3;
                        str_comment[pos] = simbolo;
                        printf("%c", simbolo);        
                        break;
                    default:
                        str_comment[pos] = simbolo;
                        printf("%c", simbolo);
                }
                break;
            case ESTADO3:
                getNextChar(lineString, &simbolo, pos);
                switch(simbolo){
                    case '*':
                        estado = ESTADO4;
                        str_comment[pos] = simbolo;
                        printf("%c", simbolo);
                        break;
                    default:
                        //simbolo -> função(avançar na tabela de simbolos)
                        str_comment[pos] = simbolo;
                        estado = ESTADO3;    
                        printf("%c", simbolo);
                }   
                break;
            case ESTADO4:
                getNextChar(lineString, &simbolo, pos);
                switch(simbolo){
                    case '/':
                        estado = ESTADO5;
                        str_comment[pos] = simbolo;
                        printf("%c", simbolo);
                        break;
                    case '*':
                        //simbolo -> função(avançar na tabela de simbolos)
                        estado = ESTADO4;
                        str_comment[pos] = simbolo;
                        printf("%c", simbolo);
                        break;    
                    default:
                        //simbolo -> função 
                        estado = ESTADO3;
                        str_comment[pos] = simbolo;
                        printf("%c", simbolo);
                }     
                break;
        }
        pos++;
        str_lenght++;
        if(str_lenght > strlen(lineString)){
            str_comment[pos] = '\0';
        }
    }
    if(estado == ESTADO5){
        printf("\nThat's a comment in C!\n");
        while()
    }else if(str_lenght > strlen(lineString)){
        printf("\nNot a comment in C!");
    }
    return 0;
}