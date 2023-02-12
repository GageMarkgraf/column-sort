#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LINES 3
#define MAX 128
const char *myarg = NULL;
int drive_sort(int argc, char* argv[])
{
    int sort = argc;
    FILE* inFile;
    FILE* outFile;
    int i = 0;
    char a;
    char line[MAX];
    char tmp[MAX_LINES];
    char* str1 = argv[1];

    if ((inFile = (fopen(argv[1], "r"))) == NULL)
    {
        fprintf(stderr, "Error: Cannot open file \n");
        return (0);
    }

    if ((outFile = (fopen("output.txt", "a"))) == NULL)
    {
        fprintf(stderr, "Error: Cannot open file \n");
        return (0);
    }
    fprintf(outFile, "%c", &str1);
        

    /*do
    {
        a = fgetc(inFile);
        fputc(a, outFile);
    } while (a != EOF);*/

    


    /*do
    {
        ptr = (NULL, del);
        i++;
    } while (i < sort);
    for(int j = 0; j < MAX_LINES - 1; j++)
    {
    printf("%s", lines[j]);
    }*/

    
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

