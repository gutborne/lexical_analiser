#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * @brief definição dos estados através de uma enum
 */
typedef enum{
    ESTADO1 = 1, ESTADO2, ESTADO3, ESTADO4, ESTADO5
}estados_automato;

void getNextChar(char* lineString, char* simbolo, int pos_cabeca_fita){
    *simbolo = *(lineString + pos_cabeca_fita);
}

estados_automato getState(estados_automato estado){
    if(estado == ESTADO1 || estado == ESTADO2 || estado == ESTADO3 || estado == ESTADO4){
        return true;
    }else{
        return false;
    }
}
int main(){
    estados_automato estado = ESTADO1;
    //char* lineString = "fadksjfkljdsf////*faksdjfkasjf******/*/fasdjfkadsjf/*";
    //char* lineString = "/*mateusvdlkgggl///********\\\\352345245433ter*/////////*********88****///fa,sldkjfklasjdfkljsdkfs*/";
    char* lineString = "oi/*adjshgjh*/var";
    char simbolo = ' ';
    size_t pos_cabeca_fita = 0, tamanho_line_string = strlen(lineString), pos = 0;
    //printf("tamanho_line_string: %zu\n", tamanho_line_string);
    //str_comment receberá o comentario ao final de toda manipulação
    char* str_comment = (char*)malloc(sizeof(char) * 200);
    while(getState(estado) && (pos_cabeca_fita <= tamanho_line_string)){
        switch(estado){
            case ESTADO1:
                getNextChar(lineString, &simbolo, pos_cabeca_fita);
                switch(simbolo){
                    case '/':
                        estado = ESTADO2;
                        str_comment[pos] = simbolo; 
                        pos++;
                        //printf("%c", simbolo);
                        break;                    
                }
                break;
            case ESTADO2:
                //simbolo -> função
                getNextChar(lineString, &simbolo, pos_cabeca_fita);
                switch(simbolo){
                    case '*':
                        estado = ESTADO3;
                        str_comment[pos] = simbolo;
                        pos++;
                        //printf("%c", simbolo);        
                        break;
                }
                break;
            case ESTADO3:
                getNextChar(lineString, &simbolo, pos_cabeca_fita);
                switch(simbolo){
                    case '*':
                        estado = ESTADO4;
                        str_comment[pos] = simbolo;
                        pos++;
                        //printf("%c", simbolo);
                        break;
                    default:
                        //simbolo -> função(avançar na tabela de simbolos)
                        str_comment[pos] = simbolo;
                        pos++;
                        estado = ESTADO3;    
                        //printf("%c", simbolo);
                }   
                break;
            case ESTADO4:
                getNextChar(lineString, &simbolo, pos_cabeca_fita);
                switch(simbolo){
                    case '/':
                        estado = ESTADO5;
                        str_comment[pos] = simbolo;
                        pos++;
                        //printf("%c", simbolo);
                        break;
                    case '*':
                        //simbolo -> função(avançar na tabela de simbolos)
                        estado = ESTADO4;
                        str_comment[pos] = simbolo;
                        pos++;
                        //printf("%c", simbolo);
                        break;    
                    default:
                        //simbolo -> função 
                        estado = ESTADO3;
                        str_comment[pos] = simbolo;
                        pos++;
                        //printf("%c", simbolo);
                }     
                break;
        }
        pos_cabeca_fita++;
    }
    
    //printf("\npos_cabeca_fita: %zu\n", pos_cabeca_fita);
    if(estado == ESTADO5){
        for(int i = 0; i < pos; i++){
            printf("%c", str_comment[i]);
        }
        printf("\nThat's a comment in C!\n");
        
    }else{
        printf("\nNot a comment in C!");
    }
    free(str_comment);
    return 0;
}