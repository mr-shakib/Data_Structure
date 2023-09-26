
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fptr;

    fptr = fopen("D:\\FileHandling\\TestFile.txt","r");

    char display[100];
    fgets(display,100,fptr);
    fprintf(fptr," This is the test file for file handling");
    printf("%s",display);
    fclose(fptr);
    return 0;
}
