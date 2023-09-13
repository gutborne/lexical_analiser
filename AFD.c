#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief definição dos estados através de uma enum
 */
typedef enum{
    ESTADO1 = 1, ESTADO2, ESTADO3, ESTADO4, ESTADO5
}estados_automato;

void get_next_char(char* lineString, char* simbolo, int pos){
    if(pos == -1)
        pos++;
    *simbolo = *(lineString + pos);
}
char* get_token(){

}
int main(){
    estados_automato estado = ESTADO1;
    char* lineString = "/mateus/*coment*/";
    char* simbolo = ' ';
    int pos = -1;
    //get_next_char(lineString, );
    while(estado == ESTADO1 || estado == ESTADO2 || estado == ESTADO3 || estado == ESTADO4){
        switch(estado){
            case ESTADO1:
                get_next_char(lineString, simbolo, pos);
                switch(*simbolo){
                    case '/':
                        estado = ESTADO2;
                        printf("");
                        break;
                    default:
                        printf("");
                }
                break;
            case ESTADO2:
                //simbolo -> função
                get_next_char(lineString, simbolo, pos);
                switch(*simbolo){
                    case '*':
                        estado = ESTADO3;
                        printf("");
                        break;
                    default:
                        printf("");
                }
                break;
            case ESTADO3:
                switch(*simbolo){
                    case '*':
                        estado = ESTADO4;
                        printf("");
                        break;
                    default:
                        //simbolo -> função(avançar na tabela de simbolos)
                        estado = ESTADO3;    
                        printf("");
                }   
                break;
            case ESTADO4:
                switch(*simbolo){
                    case '/':
                        estado = ESTADO5;
                        printf("");
                        break;
                    case '*':
                        //simbolo -> função(avançar na tabela de simbolos)
                        estado = ESTADO4;
                        break;    
                    default:
                        //simbolo -> função 
                        estado = ESTADO3;    
                        printf("");
                }     
                break;
        }
        pos++;
    }
    if(estado == ESTADO5){
        printf("aceitação\n");
    }else{
        printf("erro");
    }
    return 0;
}