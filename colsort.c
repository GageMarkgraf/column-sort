#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 128

int drive_sort(int argc, char* argv[])
{
    int sort = argc;
    char temp[MAX];
    FILE* inFile;
    FILE* outFile;
    int i, j;
    char** data = NULL;
    int sizeF = 0;
    char* ptr;
    char a;
    const char delim[] = " ";
    char* tok;
    
    if ((inFile = (fopen(*argv, "r"))) == NULL)
    {
        fprintf(stderr, "Error: Cannot open file \n");
        return (0);
    }

    if ((outFile = (fopen("output.txt", "a"))) == NULL)
    {
        fprintf(stderr, "Error: Cannot open file \n");
        return (0);
    }

    while(fgets(temp, MAX, inFile) != NULL) 
    {
        if(strchr(temp, '\n'))
        {
            temp[strlen(temp) - 1] = '\0';
        }
        data = (char**)realloc(data, sizeof(char**)*(sizeF + 1));
        data[sizeF] = (char*)calloc(MAX, sizeof(char));
        strcpy(data[sizeF], temp);
        sizeF++;
    }

    for(i = 0; i < sizeF - 1; i++)
    {
        if(strtol(argv[i], &ptr, 10) < strtol(argv[i + 1], &ptr, 10))
        {
            strcpy(temp, argv[i]);
            strcpy(argv[i], argv[i + 1]);
            strcpy(argv[i + 1], temp);
        }
    }
    do
    {
        fgetc(inFile);
        fputc(a, outFile);
    } while (a != EOF);
    
    for(i = 0; i < sizeF; i++)
    {
        fprintf(outFile, "%s\n", data[i]);
    }

    for(i = 0; i < sizeF; i++)
    {
        free(data[i]);
    }

    free(data);
    fclose(inFile);
    fclose(outFile);
    return 0;
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

