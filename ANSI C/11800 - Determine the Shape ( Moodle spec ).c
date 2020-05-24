#include <stdio.h>
#define NumOfEdges 6
#define NumOfPoints 4
typedef struct Point Point;
typedef struct Edge Edge;
struct Point
{
    int x, y;
};
struct Edge
{
    Point A, B;
    int dist;
};
void printEdges( Edge *e )
{
    unsigned int i;
    for( i = 0; i < NumOfEdges; ++i )
        printf( "Edge no. %d, points: ( %d, %d ) - ( %d, %d ), distance(squared) : %d\n", i+1, e[i].A.x, e[i].A.y, e[i].B.x, e[i].B.y, e[i].dist );
}
int perpendicular( Edge *e, Edge *f ) /* obliczam przez wspolczynnik kierunkowy */
{   
    int a = e->A.y - e->B.y;
    int b = e->A.x - e->B.x;
    int c = f->A.y - f->B.y;
    int d = f->A.x - f->B.x;
    if( a * c == b * d * (-1) )
        return 1;
    else return 0;
}
int parallel( Edge *e, Edge *f ) /* obliczam przez wspolczynnik kierunkowy */
{  
    int a = e->A.y - e->B.y;
    int b = e->A.x - e->B.x;
    int c = f->A.y - f->B.y;
    int d = f->A.x - f->B.x;
    if( a * d == b * c  )
        return 1;
    else return 0;
}
void swapEdges( Edge *e, Edge *f ) 
{
    Edge tmp = *e;
    *e = *f;
    *f = tmp;
    return;
}
int distanceFast( Point *pointA, Point *pointB )
{
    int x1 = pointA->x - pointB->x;
    int y1 = pointA->y - pointB->y;
    return x1*x1 + y1*y1;
}
void makeEdges( Point *p, Edge *e )
{
    unsigned int i, k, m = 0;
    for( i = 0; i < NumOfPoints && m < NumOfEdges; ++i )
    {
        for( k = i + 1; k < NumOfPoints; ++k )
        {
            e[m].A = p[i];
            e[m].B = p[k];
            e[m].dist = distanceFast( &e[m].A, &e[m].B );
            ++m;
        }
    }
}
int orientation( Point *A, Point *B, Point *C )
{
    int det = (B->y - A->y) * (C->x - B->x) - (B->x - A->x) * (C->y - B->y);
    if( det > 0 )
        return 1;
    else return -1;
    /* nie zwracam zera bo ze specyfikacji zadania zadne 3 punkty nie sa wspolliniowe */
}
int intersect( Edge *e, Edge *f )
{
    int o1 = orientation( &(e->A), &(e->B), &(f->A) );
    int o2 = orientation( &(e->A), &(e->B), &(f->B) );
    int o3 = orientation( &(f->A), &(f->B), &(e->A) );
    int o4 = orientation( &(f->A), &(f->B), &(e->B) );
    if ( o1 != o2 && o3 != o4 )
        return 1;
    else return 0;
}
int sharingPoint( Edge *e, Edge *f )
{
    return ( ( ( e->A.x == f->A.x && e->A.y == f->A.y )||( e->A.x == f->B.x && e->A.y == f->B.y ) )||
             ( ( e->B.x == f->A.x && e->B.y == f->A.y )||( e->B.x == f->B.x && e->B.y == f->B.y ) ) );
}
void findDiagonals( Edge *e )
{
    int i, k;
    for( i = 0; i < NumOfEdges; ++i )
    {
        for( k = i + 1; k < NumOfEdges; ++k )
        {
            if( intersect( &e[i], &e[k] ) && !sharingPoint( &e[i], &e[k] ) ) /* to znaczy ze te dwa odcinki to przekatne */
            {
                /* przenosze na poczatek i teraz wiem ze pozostale krawedzie to boki */
                swapEdges( &e[0], &e[i] );
                swapEdges( &e[1], &e[k] );
                break;
            }
        }
    }
}
int allSidesEqual( Edge *e )
{
    int i;
    for( i = 3; i < NumOfEdges; ++i )
        if( e[i-1].dist != e[i].dist )
            return 0;
    return 1;
}
int oppositeSidesEqual( Edge *e )
{
    int i, k, parallelSides = 0;
    for( i = 2; i < NumOfEdges; ++i )
    {
        for( k = i + 1; k < NumOfEdges; ++k )
        {
            if( parallel( &e[i], &e[k] ) )
            {
                ++parallelSides;
                if( e[i].dist == e[k].dist );
                else return 0;
            }
        }
    }
    if( parallelSides == 2 )
        return 1;
    else return 0;
}
int trapezium( Edge *e )
{
    int i, k;
    for( i = 2; i < NumOfEdges; ++i )
    {
        for( k = i + 1; k < NumOfEdges; ++k )
        {
            if( parallel( &e[i], &e[k] ) )
                return 1;
        }
    }
    return 0;
}
int main()
{
    int testCases, caseNumber = 1, i;
    Edge edges[ NumOfEdges ];
    Point points[ NumOfPoints ];
    scanf( "%d", &testCases );
    while( caseNumber <= testCases )
    {
        for( i = 0; i < NumOfPoints; ++i )
            scanf("%d %d", &points[i].x, &points[i].y );

        makeEdges( points, edges );
        findDiagonals( edges );
        if( edges[0].dist == edges[1].dist && allSidesEqual( edges ) )
            printf( "Case %d: Square\n", caseNumber );
        else if( edges[0].dist == edges[1].dist && oppositeSidesEqual( edges ) )
            printf( "Case %d: Rectangle\n", caseNumber );
        else if( perpendicular( &edges[0], &edges[1] ) && allSidesEqual( edges ) )
            printf( "Case %d: Rhombus\n", caseNumber);
        else if( edges[0].dist != edges[1].dist && oppositeSidesEqual( edges ) )
            printf( "Case %d: Parallelogram\n", caseNumber );
        else if( trapezium( edges ) )
            printf( "Case %d: Trapezium\n", caseNumber );
        else printf( "Case %d: Ordinary Quadrilateral\n", caseNumber );
        ++caseNumber;
    }
    return 0;
}
