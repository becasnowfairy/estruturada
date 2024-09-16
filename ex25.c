#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t nstrfile(char *filename, char *str)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        // Error handling: file cannot be opened
        return 0;
    }

    size_t count = 0;
    char line[1024]; // assume max line length is 1024

    while (fgets(line, sizeof(line), file))
    {
        char *pos = strstr(line, str);
        while (pos != NULL)
        {
            count++;
            pos = strstr(pos + 1, str);
        }
    }

    fclose(file);
    return count;
}
int main()
{
    char filename[] = "example.txt";
    char str[] = "hello";
    size_t count = nstrfile(filename, str);
    printf("A string '%s' é encontrada %zu vezes no ficheiro '%s'.\n", str, count, filename);
    return 0;
}
