#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned int capacity, queries, which, value, i;
    vector< vector<unsigned int> > tab;
//    vector< unsigned int > answer;
    while( cin >> capacity >> queries )
    {
        if( capacity == 0 && queries == 0 )
            break;
        tab.assign( 1000001, vector<unsigned int>() );
        i = 1;
        while( capacity-- )
        {
            cin >> value;
            tab[value].push_back(i);
            ++i;
        }
        while( queries-- )
        {
            cin >> which >> value;
            if( tab[value].size() >= which )
            {
                cout << tab[value][which-1] << endl;
//                answer.push_back( tab[value][which-1] );
            }
            else
            {
                cout << 0 << endl;
//                answer.push_back(0);
            }
        }
        tab.clear();
    }
    return 0;
}
