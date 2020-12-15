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

bool mycmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<node> location(n);
    int num = 1;
    for(vector<node>::iterator iter = location.begin(); iter != location.end(); iter++)
    {
        cin >> x >> y;
        iter->x = x - x;
        iter->y = y - y;
        iter->num = num++;
    }
    vector< pair<int, int> > distancemin(3);
    for(int i  = 0; i < 3; i++)
    {
        distancemin[i].first = location[i].num;
        distancemin[i].second = location[i].length();
    }
    sort(distancemin.begin(), distancemin.end(), mycmp);
    for(int i = 4; i < n; i++)
    {
        if(location[i].length() < distancemin[2].second)
        {
            distancemin[2].first = location[i].num;
            distancemin[2].second = location[i].length();
        }
        sort(distancemin.begin(), distancemin.end(), mycmp);
    }
    for(int i  = 0; i < 3; i++)
    {
        cout << distancemin[i].first << endl;
    }
    return 0;
}