#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/**
 * @brief Definition of the states through @enum
 */
typedef enum{
    ESTATE1 = 1, ESTATE2, ESTATE3, ESTATE4, ESTATE5
}estates_automata;


void getNextChar(char* lineString, char* simbol, int pos_tape_head){
    *simbol = *(lineString + pos_tape_head);
}

estates_automata getState(estates_automata estate){
    if(estate == ESTATE1 || estate == ESTATE2 || estate == ESTATE3 || estate == ESTATE4){
        return true;
    }else{
        return false;
    }
}
int main(){
    estates_automata estate = ESTATE1;
    char* lineString = "fadksjfkljdsf////*faksdjfkasjf*****/\\*/*/fasdjfkadsjf/*";
    char simbol = ' ';
    size_t pos_tape_head = 0, size_line_string = strlen(lineString), pos = 0;
    //str_comment receberá o comentario ao final de toda manipulação
    char* str_comment = (char*)malloc(sizeof(char) * 200);
    while(getState(estate) && (pos_tape_head <= size_line_string)){
        switch(estate){
            case ESTATE1:
                getNextChar(lineString, &simbol, pos_tape_head);
                switch(simbol){
                    case '/':
                        estate = ESTATE2;
                        str_comment[pos] = simbol; 
                        pos++;
                        break;                    
                }
                break;
            case ESTATE2:
                getNextChar(lineString, &simbol, pos_tape_head);
                switch(simbol){
                    case '*':
                        estate = ESTATE3;
                        str_comment[pos] = simbol;
                        pos++;
                        break;
                }
                break;
            case ESTATE3:
                getNextChar(lineString, &simbol, pos_tape_head);
                switch(simbol){
                    case '*':
                        estate = ESTATE4;
                        str_comment[pos] = simbol;
                        pos++;
                        break;
                    default:
                        str_comment[pos] = simbol;
                        pos++;
                        estate = ESTATE3;    
                }   
                break;
            case ESTATE4:
                getNextChar(lineString, &simbol, pos_tape_head);
                switch(simbol){
                    case '/':
                        estate = ESTATE5;
                        str_comment[pos] = simbol;
                        pos++;
                        break;
                    case '*':
                        estate = ESTATE4;
                        str_comment[pos] = simbol;
                        pos++;
                        break;    
                    default:
                        estate = ESTATE3;
                        str_comment[pos] = simbol;
                        pos++;
                }     
                break;
        }
        pos_tape_head++;
    }
    
    if(estate == ESTATE5){
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