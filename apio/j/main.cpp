#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <cstdio>
#include <cassert>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <sstream>
#include <ctime>

using namespace std;

#define CIN_FILE "input.txt"
#define COUT_FILE "output.txt"

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define forv(i, v) forn(i, v.size())

#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

#define NMAX 2020
#define INF 1000000000

struct Person
{
    string name;
    int dist;
};

inline bool operator<(const Person& p1, const Person& p2)
{
    return p1.dist > p2.dist;
}

int d[NMAX][NMAX];
int pi[NMAX][NMAX], pj[NMAX][NMAX];
int n, m;
Person a[NMAX], b[NMAX];
vector< vector<string> > ans;

void rec_out(int i, int j)
{
    if (i == 0 && j == 0) return;
    rec_out(pi[i][j], pj[i][j]);

    vector<string> vs;

    for (int k = pi[i][j]; k < i; k++)
    {
        vs.pb(a[k].name);
    }

    for (int k = pj[i][j]; k < j; k++)
    {
        vs.pb(b[k].name);
    }

    ans.pb(vs);
}

int main()
{
    freopen("taxi.in", "rt", stdin);
    cin >> n;
    forn(i, n)
    {
        cin >> a[i].name >> a[i].dist;
    }
    cin >> m;
    forn(i, m)
    {
        cin >> b[i].name >> b[i].dist;
    }

    sort(a, a + n);
    sort(b, b + m);

    forn(i, n + 1)
    {
        forn(j, m + 1)
        {
            d[i][j] = INF;
        }
    }

    d[0][0] = 0;

    forn(i, n + 1)
    {
        forn(j, m + 1)
        {
            if (d[i][j] == INF) continue;

            for (int x = 1; x <= 4 && x + i <= n; x++)
            {
                for (int y = 0; x + y <= 4 && y + j <= m; y++)
                {
                    int cost = a[i].dist;
                    if (y) cost = max(cost, b[j].dist);

                    if (d[i + x][j + y] > d[i][j] + cost)
                    {
                        d[i + x][j + y] = d[i][j] + cost;
                        pi[i + x][j + y] = i;
                        pj[i + x][j + y] = j;
                    }
                }
            }
        }
    }

    printf("%d\n", d[n][m]);
    rec_out(n, m);

    printf("%d\n", ans.size());

    forv(i, ans)
    {
        printf("Taxi %d: ", i + 1);

        forv(j, ans[i])
        {
            if (j > 0)
            {
                if (j < ans[i].size() - 1) cout << ", "; else cout << " and ";                
            }
            cout << ans[i][j];
        }

        cout << ".\n";
    }
    return 0;
}
            
