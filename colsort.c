#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Treat this function as main
int drive_sort(int argc, char* argv[])
{
    return 0;
}
char* file = argv;
char tempString[128];
file* ptrFile = NULL;
char** data = NULL;
int lines = 0;

while(fgets(file, 128, ptrfile) != NULL){
    tempString = (char**)malloc(data, sizeof(char**)*(lines+1));
    data[lines] = (char*)malloc(128, sizeof(char));
    strcpy(data[lines], tempString);
}
for(i= 0; i < (noOfLines - 1); ++i) {
        for(j = 0; j < ( noOfLines - i - 1); ++j) {
            if(strcmp(strData[j], strData[j+1]) > 0) {
                strcpy(strTempData, strData[j]);
                strcpy(strData[j], strData[j+1]);
                strcpy(strData[j+1], strTempData);
            }
        }
    }
    for(i = 0; i < lines; i++)
        fprintf(ptrSummary,"%s\n",strData[i]);
    for(i = 0; i < noOfLines; i++)
        free(strData[i]);
    free(data);
    fclose(ptrFile);
    return 0;
fopen(argv);
fgets(argv);
//strcmp();
//qsort();
//strtok();
//fclose();
//fprintf(stdout, argv);
// TODO all changes should be made above this line
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
