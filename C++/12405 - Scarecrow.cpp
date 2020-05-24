#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    unsigned int i, caseNumber=1, testCases, scarecrows, fieldSize;
    string field;
    cin >> testCases;
    while ( testCases-- )
    {
        scarecrows = 0;
        cin >> fieldSize;
        cin >> field;
        field += "##";
        for( i = 0 ; i < fieldSize ; ++i )
        {
            if (field[i] == '.')
            {
                field[i] = '#';
                field[i + 1] = '#';
                field[i + 2] = '#';
                i += 2;
                ++scarecrows;
            }
        }
        cout << "Case " << caseNumber << ": " << scarecrows << endl;
        ++caseNumber;
    }
    return 0;
}
