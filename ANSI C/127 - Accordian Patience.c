#include <stdio.h>
#include <stdlib.h>
typedef struct cardStack cardStack;
struct cardStack
{
    char value[52];
    char suit[52];
    int topCardIdx;
};
int getLeftIdx( int shift, int currentIdx, cardStack *s )
{
    int index, i;
    for( i = (currentIdx-1); i >= 0; --i )
    {
        if( s[i].topCardIdx >= 0 )
        {
            index = i;
            --shift;
            if( shift == 0 )
                return index;
        }
    }
    index = -1; /* sytuacja gdy nie bylo 3 stosu po lewej */
    return index;
}
int main()
{
    char tmp;
    int i, k, m, moveMade, answer[52];
    cardStack *patience = malloc( 52*sizeof( cardStack ));
    while( 1 )
    {
        /* Inicjalizacja */
        for( i = 0; i < 52; ++i )
        {
            for( k = 0; k < 52; ++k )
            {
                patience[i].value[k] = 0;
                patience[i].suit[k] = 0;
            }
            patience[i].topCardIdx = 0;
        }
        /* Input */
        scanf( "%c", &patience[0].value[0]);
        if( patience[0].value[0] == '#' )
        {
            free( patience );
            return 0;
        }
        scanf( "%c%c", &patience[0].suit[0], &tmp);
        for( i = 1; i < 52; ++i )
            scanf( "%c%c%c", &patience[i].value[0], &patience[i].suit[0], &tmp );

        moveMade = 1;
        while( moveMade )
        {
            moveMade = 0;
            for( i = 1; i < 52; ++i ) /* przesuwamy sie w prawo po kolejnych stosach - i=1 bo pierwszy stos nigdy nie ma ruchu */
            {   /* pomijamy puste stosy */
                if( patience[i].topCardIdx >= 0 )
                {
                    k = getLeftIdx( 3, i, patience );
                    m = getLeftIdx( 1, i, patience );
                      /* priorytet maja ruchy co 3 karty wiec najpierw sprawdzamy czy to mozliwe */
                    if( k >= 0 && (patience[i].suit[patience[i].topCardIdx]==patience[k].suit[patience[k].topCardIdx] ||
                                      patience[i].value[patience[i].topCardIdx]==patience[k].value[patience[k].topCardIdx]))
                    {   /* kladziemy na stosie nową karte wiec przepisujemy jej wartosci ze starego stosu i kasujemy / uaktualniamy odpowiednie wartosci */
                        patience[k].topCardIdx++;
                        patience[k].suit[patience[k].topCardIdx] = patience[i].suit[patience[i].topCardIdx];
                        patience[k].value[patience[k].topCardIdx] = patience[i].value[patience[i].topCardIdx];
                        patience[i].suit[patience[i].topCardIdx] = 0;
                        patience[i].value[patience[i].topCardIdx] = 0;
                        patience[i].topCardIdx--;
                        moveMade = 1;
                        break;
                    }
                    else if( patience[i].suit[patience[i].topCardIdx]==patience[m].suit[patience[m].topCardIdx] ||
                            patience[i].value[patience[i].topCardIdx]==patience[m].value[patience[m].topCardIdx] )
                    {
                        patience[m].topCardIdx++;
                        patience[m].suit[patience[m].topCardIdx] = patience[i].suit[patience[i].topCardIdx];
                        patience[m].value[patience[m].topCardIdx] = patience[i].value[patience[i].topCardIdx];
                        patience[i].suit[patience[i].topCardIdx] = 0;
                        patience[i].value[patience[i].topCardIdx] = 0;
                        patience[i].topCardIdx--;
                        moveMade = 1;
                        break;
                    }
                }
            }
        }
        k=0;
        for( i = 0; i < 52; ++i )
        {
            if( patience[i].topCardIdx >= 0 )
            {
                answer[k] = patience[i].topCardIdx + 1;
                ++k;
            }
        }
        if( k == 1)
            printf( "%d pile remaining: ", k );
        else printf( "%d piles remaining: ", k );
        for( i = 0; i < k; ++i )
            printf( "%d ", answer[i] );
        printf( "\n" );
    }
    free( patience );
    return 1;
}
