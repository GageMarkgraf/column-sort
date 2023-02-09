#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 128

char ***readFile(FILE *aFile, int row, int col);
char **mergeString(char **strMat, int row, int col);
void writeString(FILE *aFile, char **array, int dim);
int drive_sort(int argc, char* argv[]){
    FILE *file, *fileTwo;
    char ***strMat;
    int row, col;
    char **array;

    if((file=fopen(argv[1], "r")) != NULL || (file=fopen(argv[2], "w")) == NULL){
        printf(stderr, "Error: Opening File \n");
        exit(1);
    }

    fscanf(file, "%d%d", &row, &col);
    strMat = readFile(file, row, col);
    array = mergeString(strMat, row, col);
    writeString(fileTwo, array, row*col);
    return 0;
}
char ***readFile(FILE *aFile, int row, int col){
    char ***strMatr;
    int i, j;
    char max[MAX];
    if((strMatr=malloc((row)*sizeof(char **))) == NULL){
    printf(stderr, "Error: Allocation of Memory \n");
    exit(2);
    }

    for(i=0; i < row; i++){
        if((strMatr[i]=malloc((col)*sizeof(char **))) == NULL){
            printf(stderr, "Error: Allocation of Memory \n");
            exit(3);
        }
    }

    for(i=0; i < row; i++){
        for(j = 0; j < col; j++){
            fscanf(aFile, "%s", max);
            if(j > 0 && strcmp(strMatr[i][j-1], max) > 0){
                printf(stderr, "Error: Strings not in ascending order \n");
                exit(4);
            }
            strMatr[i][j]=strup(max);
        }
    }
    fclose(aFile);
    return strMatr;

}
char **mergeString(char **strMat, int row, int col){
    char **arr;
    int i, j;
    int *c;
    int maxC;
    char *tempStr;
    if((arr=malloc((row*col)*sizeof(char*))) == NULL){
        printf(stderr, "Error: Allocation of memory \n");
        exit(5);
    }
    if((c=calloc(row, sizeof(int))) == NULL){
        printf(stderr, "Error Allocation of memory: \n");
        exit(6);
    }
    while(i < row*col){
        maxC=-1;
        for(j=0; j < row; j++){
            if(c[j] < col){
                if((maxC==-1) || strcmp(strMat[j][c[j]],tempStr > 0)){
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
void writeString(FILE *aFile, char **array, int dim){
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
