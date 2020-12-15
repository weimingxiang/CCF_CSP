#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k ,t, x1, y1, x2, y2;

    cin >> n >> k >> t >> x1 >> y1 >> x2 >> y2;
    vector < vector < pair < int, int > > > all_user(n);
    int x, y;
    int cross = 0;
    int stay = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            cin >> x >> y;
            all_user[i].push_back(pair<int, int>(x, y));
        }

    }
    for (vector < vector < pair < int, int > > >::iterator user = all_user.begin(); user != all_user.end(); user++)
    {
        bool cross_t = 0, stay_t = 0;
        int count = 0;
        for(vector < pair < int, int > >::iterator iter = user->begin(); iter != user->end(); iter++)
        {
            if(iter->first >= x1 && iter->first <= x2 && iter->second >= y1 && iter->second <= y2)
            {
                cross_t = 1;
                count++;
                if(count >= k) stay_t = 1;
            }
            else count = 0;
        }
        cross += cross_t;
        stay += stay_t;

    }
    cout << cross << endl << stay << endl;
    return 0;
}
