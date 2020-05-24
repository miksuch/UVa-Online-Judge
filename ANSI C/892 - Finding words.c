#include <stdio.h>
#include <string.h>
int main()
{
    unsigned int i,idx;
    int flag,prevWasLetter, specialCase;
    char line[63], word[63];
    flag = 1; specialCase = 0;
    while( fgets( line, 63, stdin ) )
    {
        i = 0;
        if( flag )
            idx = 0;
        else specialCase = 1;
        while( i < strlen(line) )
        {
            if( (line[i] >= 'a' && line[i] <= 'z' ) || (line[i] >= 'A' && line[i] <= 'Z' ))
            {
                word[idx] = line[i];
                ++idx;
                prevWasLetter = 1;
            }
            else if( line[i] == 32 || line[i] == '\n' )
            {
                if( line[i] == '\n' )
                {
                    if( flag == 1 )
                    {
                        word[idx] = '\0';
                        if( strlen( word ) >= 1 )
                            printf( "%s", word );
                        idx = 0;
                        printf("%c", line[i] );
                        flag = 1;
                        prevWasLetter = 0;
                    }
                    else printf("\n");
                }
                else
                {
                    word[idx] = '\0';
                    if( strlen( word ) >= 1 )
                        printf( "%s", word );
                    idx = 0;
                    printf("%c", line[i] );
                    flag = 1;
                    prevWasLetter = 0;
                }
                if( specialCase == 1 )
                {
                    printf("\n");
                    specialCase = 0;
                }

            }
            else if( line[i] == '-' && prevWasLetter == 1)
            {
                flag = 0;
            }

            ++i;
        }
        if( strlen( line ) == 2 && line[0] == '#' )
            break;
    }
    return 0;
}
