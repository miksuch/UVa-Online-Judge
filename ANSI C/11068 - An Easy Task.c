#include <stdio.h>
int comp( int a, int b, int c, int d )
{
    if( a * d == c * b )
        return 1;
    else return 0;
}
int main()
{
    int gh = 1;
    double ax[2],by[2],c[2],i,a[2][2], W, Wx, Wy;
    while( gh )
    {
        scanf( "%lf %lf %lf", &ax[0], &by[0], &c[0] );
        scanf( "%lf %lf %lf", &ax[1], &by[1], &c[1] );

        if( ax[0] == 0  && ax[1] == 0 && by[0] == 0 && by[1] == 0 && c[0] == 0 && c[1] == 0 )
            break;

        a[0][0] = ax[0]*(-1);
        a[0][1] = by[0];

        a[1][0] = ax[1]*(-1);
        a[1][1] = by[1];

        if( comp( a[0][0], a[0][1], a[1][0], a[1][1] ) )
        {
            printf( "No fixed point exists.\n" );
        }
        else
        {
            W = ax[0] * by[1] - ax[1] * by[0];
            Wx = c[0] * by[1] - c[1] * by[0];
            Wy = ax[0] * c[1] - ax[1] * c[0];
            ax[0] = (double)(Wx / W);
            by[0] = (double)(Wy / W);
            if( by[0] == 0 )
                by[0] = 0;
            if( ax[0] == 0 )
                ax[0] = 0;
            printf( "The fixed point is at %.2lf %.2lf\n", ax[0], by[0] );
        }

    }

    return 0;
}
