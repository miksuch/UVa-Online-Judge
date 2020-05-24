#include <stdio.h>
int main()
{
    int input, i, answer;
    char binary[40];
    while( scanf( "%d", &input) )
    {
        if( input == 0 )
            break;
        i = 0; answer = 0;
        while( input != 0 )
        {
            if( input % 2 )
            {
                binary[i] = '1';
                ++answer;
            }

            else binary[i] = '0';
            input = input / 2;
            ++i;
        }
        printf( "The parity of " );
        for( --i; i >= 0; --i )
            printf( "%c", binary[i] );
        printf( " is %d (mod 2).\n", answer );
    }
    return 0;

}
