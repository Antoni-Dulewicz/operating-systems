#include "collatz.h"

int collatz_conjecture(int input){
    if(input%2 == 0){
        return input/2;
    }else{
        return 3*input + 1;
    }
}

int test_collatz_convergence(int input, int max_iter){
    int i = 0;
    int tmp = input;
    while(i < max_iter){
        tmp = collatz_conjecture(tmp);
        i ++;
        if(tmp == 1){
            return i;
        }
        
    }

    return -1;

}