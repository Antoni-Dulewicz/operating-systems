#include <stdio.h>
#include "collatz.h"
#ifdef DYNAMIC_LIB    //dyrektywa preprocesora
    #include <dlfcn.h> // biblioteka uzywana do dyn bibliotek
    //wskaznik na funkcje o typie int z parametrami (int,int)
    typedef int (*CollatzFunc)(int,int);

#endif 

int main(){
    int num = 20;
    #ifdef DYNAMIC_LIB

        void *lib_handle;
        CollatzFunc test_collatz_convergence;        

        printf("Using dynamic library:\n");
        //czyta tylko tylko te funckje i zmienne ktore w tym momencie sa uzywane przz program
        lib_handle = dlopen("./libcol.so",RTLD_LAZY);

        if(!lib_handle){
            printf("Couldn't find this library");
            return 0;
        }

        //dlsym - dynamic symbol resolution - dynamiczne rozwiazywanie
        //przypisuje wskaznik na funckje do zmiennej
        test_collatz_convergence = (CollatzFunc)dlsym(lib_handle,"test_collatz_convergence");
        //moge wywolywac te funkcje przez to zmienna
        if(!test_collatz_convergence){
            printf("Library doesn't have this function");
            dlclose(lib_handle);
            return 1;
        }

        printf("Number of iterations for %d is: ",num);
        printf("%d\n",test_collatz_convergence(num,1000));

        dlclose(lib_handle);
    #else
        printf("Using static/shared library:\n");
        printf("Number of iterations for %d is: ",num);
        printf("%d\n",test_collatz_convergence(num,1000));
    #endif
    return 0;

}