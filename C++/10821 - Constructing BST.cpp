#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
using namespace std;
void bestRoot(int start, int finish, int height)
{
    if ( height == 0 || start > finish )
        return;
    int root;
    if( start > ( finish - ( pow(2, height-1) - 1) ) )
        root = start;
    else root = finish - ( pow(2, height-1) - 1);

    cout << " " << root;

    bestRoot( start, root - 1, height - 1 );
    bestRoot( root + 1 , finish, height - 1 );
}
int main()
{
    int numbers, height;
    unsigned int caseNumber = 1;
    while( cin >> numbers >> height )
    {
        if( numbers == 0 && height == 0 )
            break;

        if ( numbers > (pow(2, height) - 1 ) )
            cout << "Case " << caseNumber << ": Impossible.";
        else
        {
            cout << "Case " << caseNumber << ":";
            bestRoot( 1, numbers, height );
        }
        cout << endl;
        ++caseNumber;
    }

    return 0;
}
