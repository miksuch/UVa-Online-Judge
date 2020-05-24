#include <stdio.h>
#include <stdlib.h>
typedef struct coordinates coordinates;
typedef struct fraction fraction;
struct fraction
{
    int numerator;
    int denominator;
};
struct coordinates
{
    int x;
    int y;
};
int parallel( int a, int b, int c, int d )
{
    if( a * d == b * c  )
        return 1;
    else return 0;
}
void sort( int *tab, int n )
{
    int i,j,min,tmp;
    for( i=0; i < (n - 1); i++)
    {
        min = i;
        for (j = i+1; j < n; ++j)
            if ( tab[j] < tab[min] )
                min = j;

        tmp = tab[i];
        tab[i] = tab[min];
        tab[min] = tmp;
    }

}
int distance( coordinates *pointA, coordinates *pointB )
{
    int x = pointA->x - pointB->x;
    int y = pointA->y - pointB->y;
    if( x < 0 )
        x *= (-1);
    if( y < 0 )
        y *= (-1);
    return x*x + y*y;
}
int main()
{
    int caseNumber,counter=1,i,k,m,lengths[6];
    coordinates point[4];
    fraction gradient[6];
    scanf( "%d", &caseNumber );
    while( counter <= caseNumber )
    {
        for( i = 0; i < 4; ++i )
            scanf("%d %d", &point[i].x, &point[i].y );
        lengths[0]=distance( &point[0], &point[1] );
        lengths[1]=distance( &point[0], &point[2] );
        lengths[2]=distance( &point[0], &point[3] );
        lengths[3]=distance( &point[1], &point[2] );
        lengths[4]=distance( &point[1], &point[3] );
        lengths[5]=distance( &point[2], &point[3] );


        /*for( i = 0; i < 6; ++i )
            printf( "%d | ", lengths[i] );
        printf("\n");*/

        sort( lengths, 6 );

        /*for( i = 0; i < 6; ++i )
            printf( "%d | ", lengths[i] );*/
        if( lengths[0] == lengths[1] && lengths[2] == lengths[3] && lengths[1] == lengths[2] && lengths[4] == lengths[5] )
            printf( "Case %d: Square\n", counter );
        else if( (lengths[1] == lengths[2] && lengths[3] == lengths[4] && lengths[2] == lengths[3]) ||
               ( lengths[0] == lengths[1] && lengths[2] == lengths[3] && lengths[1] == lengths[2] && lengths[4] != lengths[5] ))
            printf( "Case %d: Rhombus\n", counter);
        else if( lengths[0] == lengths[1] && lengths[2] == lengths[3] && lengths[1] != lengths[2] && lengths[4] == lengths[5] && lengths[0] + lengths[2] == lengths[4])
            printf( "Case %d: Rectangle\n", counter );
        else
        {
            m = 0;
            for( i = 0; i < 4;  ++i )
            {
                for( k = i + 1; k < 4; ++k )
                {
                    /*printf( "%d : %d\n", i, k);*/
                    gradient[m].numerator=point[i].y - point[k].y;
                    gradient[m].denominator=point[i].x - point[k].x;
                    ++m;
                }
            }
            m = 0;
            for( i = 0; i < 6;  ++i )
            {
                for( k = i + 1; k < 6; ++k )
                {
                    /*printf( "%d : %d\n", i, k);*/
                    if( parallel( gradient[i].numerator, gradient[i].denominator, gradient[k].numerator, gradient[k].denominator) )
                        ++m;
                }
            }
            /*printf( "%d\n", m);*/
            if( m == 2 )
                printf( "Case %d: Parallelogram\n", counter );
            else if( m == 1 )
                printf( "Case %d: Trapezium\n", counter );
            else printf( "Case %d: Ordinary Quadrilateral\n", counter );
        }

        ++counter;
    }
    return 0;
}
