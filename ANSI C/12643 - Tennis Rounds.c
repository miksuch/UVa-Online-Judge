#include <stdio.h>
int main()
{
    unsigned int rounds, playerOne, playerTwo, answer;
    while( scanf( "%u %u %u", &rounds, &playerOne, &playerTwo ) != EOF )
    {
        answer = 0;
        while(  playerOne != playerTwo )
        {
            if( playerOne % 2 == 1 )
                playerOne = (playerOne / 2) + 1;
            else playerOne = playerOne / 2;

            if( playerTwo % 2 == 1 )
                playerTwo = (playerTwo / 2) + 1;
            else playerTwo = playerTwo / 2;

            ++answer;
        }
        printf( "%u\n", answer );

    }
    return 0;
}
