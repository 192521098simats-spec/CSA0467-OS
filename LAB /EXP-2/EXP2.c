#include <stdio.h>

int main()
{
    FILE *source, *target;
    int ch;

    source = fopen("source.txt", "r");
    target = fopen("target.txt", "w");

    if (source == NULL || target == NULL)
    {
        printf("Error opening file!");
        return 1;
    }

    while ((ch = fgetc(source)) != EOF)
    {
        fputc(ch, target);
    }

    printf("File copied successfully!");

    fclose(source);
    fclose(target);

    return 0;
}