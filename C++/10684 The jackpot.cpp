#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);

	int size;
		while (cin >> size)
		{
			if (size == 0)
				break;

			int streak = 0; int bestStreak = 0; int tmpBestStreak = 0;
			while (size--)
			{
				cin >> streak;
				tmpBestStreak += streak;
				if( tmpBestStreak > bestStreak )
                    bestStreak = tmpBestStreak;
                if( tmpBestStreak <= 0 )
                    tmpBestStreak = 0;

			}
			if (bestStreak > 0)
				cout << "The maximum winning streak is " << bestStreak << ".\n";
			else cout << "Losing streak.\n";

		}

	return 0;
}
