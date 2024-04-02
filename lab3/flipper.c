#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

/*otwieramy katalog (opendir), potem go czytamy (readdir) w petli,
dla kazdego pliku sprawdzwamy czy jest txt (strtsr), jesli tak to otwieramy go 
ze ze sciezki (sprintf) czytamy linia po linii (fgets)*/

void reverseLine(char *str){
    int i = 0;
    int j = strlen(str)-2;
    while(i < j){
        int tmp = str[i];
        str[i] = str[j];
        str[j] = tmp; 
        i++;
        j--;
    }

}


int main(int argc, const char *argv[]){
    printf("Pierwszy arg: %s\n",argv[1]);
    printf("Drugi arg: %s\n",argv[2]);

    const char *inDir = argv[1];
    const char *outDir = argv[2];


    DIR *dir;
    struct dirent *input;
    //otwieram katalog
    dir = opendir(inDir);
    if(dir == NULL){
        perror("error while opening directory");
        exit(EXIT_FAILURE);
    }

    if(mkdir(outDir,0777) == -1){
        perror("error while creating out directory");
        exit(EXIT_FAILURE);
    }

    //przechodze po elementach w katalogu
    while((input = readdir(dir)) != NULL){
        //sprawdzam czy sa to pliki txt
        if(strstr(input->d_name,".txt") != NULL){
            char inFilePath[256];
            char outFilePath[256];

            sprintf(inFilePath,"%s/%s",inDir,input->d_name);
            sprintf(outFilePath,"%s/%s",outDir,input->d_name);


            //otwieram plik z ktorego bede czytac i do ktorego bede wpisywac
            FILE *inFile = fopen(inFilePath,"r");
            FILE *outFile = fopen(outFilePath,"w");

            char line[256];
            //linijka po lijice obracam linijke i kopiuje do nowego pliku
            while(fgets(line,sizeof(line),inFile) != NULL){
                reverseLine(line);
                fputs(line,outFile);
            }
            fclose(inFile);
            fclose(outFile);
        }
    }
    closedir(dir);
    return 0;
}