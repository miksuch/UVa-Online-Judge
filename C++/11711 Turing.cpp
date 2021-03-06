#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int main()
{
	//freopen("11711.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);

	int testsCount, rulesCount;

	while ( cin >> rulesCount >> testsCount )
	{

        if( !testsCount && !rulesCount )
            break;

        #define RULES_SIZE 1000
        #define STATE 0
        #define CONTENT 1
        #define NEXT_STATE 2
        #define NEXT_CONTENT 3
        #define MOV 4
        int rules[RULES_SIZE][5];
        for( int i = 0; i < rulesCount; ++i )
        {

            int stateCurr, contentCurr, stateNext, contentNext;
            char tapeMov;

            cin >> stateCurr >> contentCurr >> stateNext >> contentNext >> tapeMov;

            rules[i][STATE] = stateCurr;
            rules[i][CONTENT] = contentCurr;
            rules[i][NEXT_STATE] = stateNext;
            rules[i][NEXT_CONTENT] = contentNext;
            if( tapeMov == 'L' )
                rules[i][MOV] = -1;
            else rules[i][MOV] = 1;

        }

        #define TAPE_SIZE 1000
        bool tape[TAPE_SIZE];
        for( int t = 0; t < testsCount; ++t )
        {
            int input, expectedResult;
            cin >> input >> expectedResult;

            // setting up tape
            for( int i = 0; i < TAPE_SIZE; ++i )
            {
                if( i < input )
                    tape[i] = 1;
                else tape[i] = 0;
            }

            // main loop of the machine
            string verdict = "";
            int state = 0, head = 0, iterations = 0, allowedIterations = 10000;
            bool checkForRules = true; // if no rules match machine should stop
            while( checkForRules )
            {
                checkForRules = false;
                ++iterations;
                if( iterations > allowedIterations )
                {
                    verdict = "TLE";
                    break;
                }
                for( int i = 0; i < rulesCount; ++i )
                {
                    if( state == rules[i][STATE] && tape[head] == rules[i][CONTENT] )
                    {
                        state = rules[i][NEXT_STATE];
                        tape[head] = rules[i][NEXT_CONTENT];
                        head += rules[i][MOV];
                        //cout << "chosen rule: " << i+1 << endl << "head: " << head << endl;
                        if( head < 0 || head >= TAPE_SIZE )
                            verdict = "MLE";
                        else checkForRules = true;

                        break; // at most one rule will match
                    }
                }
            }

            // if no verdict yet check for result
            if( verdict == "" )
            {
                // counting sequence of ones
                int counter = 0;
                for( int i = 0; i < TAPE_SIZE; ++i )
                {
                    if( tape[i] == 1 )
                        ++counter;
                    else break;
                }
                // checking if the rest of tape is zeroes
                for( int i = counter; i < TAPE_SIZE; ++i )
                {
                    if( tape[i] != 0 )
                        counter = -1;
                }

                if( counter == expectedResult )
                    verdict = "AC";
                else verdict = "WA";
            }

            cout << verdict << '\n';

        }


	}

	return 0;
}
