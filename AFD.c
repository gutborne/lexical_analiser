#include <stdio.h>
#include <stdlib.h>
/**
 * @brief definição dos estados através de uma enum
 */
typedef enum{
    ESTADO1 = 1, ESTADO2, ESTADO3, ESTADO4, ESTADO5
}estados_automato;


int main(){
    estados_automato estado = 0;
    char simbolo = ' ';
    while(estado == ESTADO1 || estado == ESTADO2 || estado == ESTADO3 || estado == ESTADO4){
        switch(estado){
            case ESTADO1:
                //simbolo -> função 
                switch(simbolo){
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
                switch(simbolo){
                    case '*':
                        printf("");
                        break;
                    default:
                        printf("");
                }
                break;
            case ESTADO3:
                switch(simbolo){
                    case '*':
                        printf("");
                        break;
                    default:
                        printf("");
                }   
                break;
            case ESTADO4:
                break;
        }
    }
    if(estado == ESTADO5){
        printf("aceitação\n");
    }else{
        printf("erro");
    }
    return 0;
}