#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Show
{
    Show(int stime, int etime)
    :stime(stime), etime(etime) {}
    int stime, etime;
    bool operator < (const Show &other) const
    {
        return etime < other.etime;
    }
};

int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n) {
        vector<Show> shows;
        for (int i = 0; i < n; i++) {
            int st, et;
            scanf("%d %d", &st, &et);
            Show show(st, et);
            shows.push_back(show);
        }
        sort(shows.begin(), shows.end());
        int count = 0;
        int time = 0;
        for (int i = 0; i < shows.size(); i++) {
            if (time <= shows[i].stime) {
                time = shows[i].etime;
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}