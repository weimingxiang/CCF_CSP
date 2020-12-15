#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct node
{
    /* data */
    int x, y;
    int num;
    float length()
    {
        return sqrt(x * x + y * y);
    }
}node;

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n, X, Y;
    cin >> n >> X >> Y;
    vector<node> location(n);
    int num = 1;
    int x, y;
    for(vector<node>::iterator iter = location.begin(); iter != location.end(); iter++)
    {
        cin >> x >> y;
        iter->x = x - X;
        iter->y = y - Y;
        iter->num = num++;
    }
    vector< pair<int, int> > distanceMin(3);
    for(int i  = 0; i < 3; i++)
    {
        distanceMin[i].first = location[i].num;
        distanceMin[i].second = location[i].length();
    }
    
    sort(distanceMin.begin(), distanceMin.end(), myCmp);

    for(int i = 4; i < n; i++)
    {
        if(location[i].length() < distanceMin[2].second)
        {
            distanceMin[2].first = location[i].num;
            distanceMin[2].second = location[i].length();
        }
        sort(distanceMin.begin(), distanceMin.end(), myCmp);
    }

    for(int i  = 0; i < 3; i++)
    {
        cout << distanceMin[i].first << endl;
    }

    return 0;
}