#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char ***copyFile(FILE *aFile, int row, int col);
int strcmp(const char *strOne, const char *strTwo);
char *strdup(const char *strOne);
char **combine(char ***strMat, int row, int col);
void pasteFile(FILE *aFile, char **array, int dim);
int drive_sort(int argc, char* argv[]){
    FILE *file;
    FILE *fileTwo;
    char ***strMat;
    int row, col;
    char **array;

    if((file=fopen(argv[1], "r")) != NULL || (file=fopen(argv[2], "w")) == NULL){
        printf("Error: Opening File \n");
        exit(1);
    }

    fscanf(file, "%d%d", &row, &col);
    //strMat = copyFile(file, row, col);
    array = combine(strMat, row, col);
    pasteFile(fileTwo, array, row*col);
    return 0;
}
char ***copyFile(FILE *aFile, int row, int col){
    char ***strMat;
    int i, j;
    char max = 128;
    if((strMat=malloc((row)*sizeof(char **))) == NULL){
    printf("Error: Allocation of Memory \n");
    exit(2);
    }

    for(i=0; i < row; i++){
        if((strMat[i]=malloc((col)*sizeof(char **))) == NULL){
            printf("Error: Allocation of Memory \n");
            exit(3);
        }
    }

    for(i=0; i < row; i++){
        for(j = 0; j < col; j++){
            fscanf(aFile, "%hhd", max);
            strMat[i][j]=strdup(max);
        }
    }
    fclose(aFile);
    return strMat;

}
char **combine(char ***strMat, int row, int col){
    char **arr;
    int i, j;
    int *c;
    int maxC;
    char *tempStr;
    if((arr=malloc((row*col)*sizeof(char*))) == NULL){
        printf("Error: Allocation of memory \n");
        exit(4);
    }
    if((c=calloc(row, sizeof(int))) == NULL){
        printf("Error Allocation of memory: \n");
        exit(5);
    }
    while(i < row*col){
        maxC=-1;
        for(j=0; j < row; j++){
            if(c[j] < col){
                if((maxC==-1) || strcmp(strMat[j][c[j]], tempStr) > 0){
                    maxC = j;
                    tempStr = strMat[maxC][c[maxC]];
                }
            }
        }
        arr[i++] = strMat[maxC][c[maxC]++];
    }
    free(c);
    return arr;
}
void pasteFile(FILE *aFile, char **array, int dim){
    int i;
    fprintf(aFile, "%d\n", dim);
    for(i = 0; i < dim; i++){
        fprintf(aFile, "%s\n", array[i]);
    }
    fclose(aFile);
    return;
}


int main(int argc, char* argv[])
{
    int ret = 0;
    double time;
    struct timespec s;
    struct timespec e;

    clock_gettime(CLOCK_MONOTONIC, &s);
    ret = drive_sort(argc, argv);
    clock_gettime(CLOCK_MONOTONIC, &e);
    time = e.tv_sec - s.tv_sec + (e.tv_nsec - s.tv_nsec)/1e9;

    fprintf(stderr, "time: %lfs\n", time);
    return ret;
}

