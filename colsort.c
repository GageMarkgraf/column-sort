#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_LINES 3
#define MAX 127
const char *myarg = NULL;
int drive_sort(int argc, char* argv[])
{
    myarg = argv[1];
    int sort = argc;
    char temp[MAX];
    FILE* inFile;
    FILE* outFile;
    int i = 0;
    char a;
    //char str[] = (char)myarg[0];
    char del[] = " ";
    //char* ptr = strtok(str, del);
    int len = strlen(argv[1]);
    char mat[10];
    char lines[MAX_LINES][MAX];
    int line = 0;


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

    while(!feof(inFile) && !ferror(inFile))
    {
        if(fgets(lines[line], MAX, inFile) != NULL)
        {
            line++;
        }
    }

    /*do
    {
        ptr = (NULL, del);
        i++;
    } while (i < sort);
    for(int j = 0; j < MAX_LINES - 1; j++)
    {
    printf("%s", lines[j]);
    }*/
    do
    {
        a = fgetc(inFile);
        fputc(a, outFile);
    } while (a != EOF);
    
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

