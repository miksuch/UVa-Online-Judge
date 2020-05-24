#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;
stack <int> stos;
queue <int> kolejka;
priority_queue <int> kolejkaPro;
void flush()
{
    while( !stos.empty() )
        stos.pop();
    while( !kolejka.empty() )
        kolejka.pop();
    while( !kolejkaPro.empty() )
        kolejkaPro.pop();
}
int main()
{
    bool czyStos, czyKolejka, czyKolejkaPro;
    int n,tryb,a;
    string N;
    while( cin >> n )
    {
        czyStos =1; czyKolejka =1; czyKolejkaPro =1;
        while( n > 0 )
        {
            cin >> tryb >> a;
            if( tryb == 1 )
            {
                if( czyStos )
                    stos.push(a);
                if( czyKolejka )
                    kolejka.push(a);
                if( czyKolejkaPro )
                    kolejkaPro.push(a);
            }
            else
            {
                if( czyStos )
                {
                    if( stos.empty() )
                        {
                            czyStos = 0; czyKolejka = 0; czyKolejkaPro = 0;
                        }
                    else if( a != stos.top() )
                        czyStos = 0;
                    else stos.pop();
                }
                if( czyKolejka )
                {
                    if( kolejka.empty() )
                        {
                            czyStos = 0; czyKolejka = 0; czyKolejkaPro = 0;
                        }
                    if( a != kolejka.front() )
                        czyKolejka = 0;
                    else kolejka.pop();
                }
                if( czyKolejkaPro )
                {
                    if( kolejkaPro.empty() )
                        {
                            czyStos = 0; czyKolejka = 0; czyKolejkaPro = 0;
                        }
                    if( a != kolejkaPro.top() )
                        czyKolejkaPro = 0;
                    else kolejkaPro.pop();
                }
            }
            --n;
        }
        flush();
        //cout << czyStos << " " << czyKolejka << " " << czyKolejkaPro << endl;
        if( czyStos + czyKolejka + czyKolejkaPro == 0 )
            cout << "impossible";
        else if( czyStos + czyKolejka + czyKolejkaPro == 1 )
        {
            if( czyStos )
                cout << "stack";
            else if( czyKolejka )
                cout << "queue";
            else cout << "priority queue";
        }
        else cout << "not sure";
        cout << endl;
    }
    return 0;
}
