#include <stdio.h>
#include <stdlib.h>
#include "sphinxstem.h"

int main(int argc, char* argv[])
{
    BYTE pWord[100];

    stem_ru_init();
    stem_en_init();

    if (argc > 1)
    {
        sscanf(argv[1], "%s", pWord);
    }
    else
    {
        scanf("%s\n", pWord);
    }
    stem_en(pWord, strlen((char*) pWord));
    stem_ru_cp1251(pWord);
    printf("%s\n", pWord);

    return 0;
}
