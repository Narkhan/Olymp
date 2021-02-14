//#pragma GCC target("avx2")
//#pragma GCC optimize("O3")

//# include <x86intrin.h>
# include <bits/stdc++.h>

# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
 
template<typename T> using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
  //freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n, m, k;
struct node {
  int mx[11], mn[11], sz;
  
};

bool operator < (node a, node b) {
  for (int i = 1; i <= k; i ++) if (b.mx[i] > a.mn[i]) return 0;
  return 1;
}

node operator + (node a, node b) {
  for (int i = 1; i <= k; i ++) {
    a.mx[i] = max(a.mx[i], b.mx[i]);
    a.mn[i] = min(a.mn[i], b.mn[i]);
  }
  a.sz += b.sz;
  return a;
}

bool can (node a, node b) {
  for (int i = 1; i <= k; i ++) if (a.mx[i] > b.mn[i]) return 1;

  return 0;
}

set < node > all;

int main () {
    SpeedForce;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    node x;
      for (int j = 1; j <= k; ++j) {
        cin >> x.mx[j];
        x.mn[j] = x.mx[j];
      } 

      x.sz = 1;
      for (auto it = all.lower_bound(x); it != all.end() && can(*it, x); ) {
        cout << "OK " << i << endl;
        x = x + *it;
        it = all.erase(it);
      }
      all.insert(x);
      //cout << x.sz << " : ";

        cout << all.begin() -> sz << '\n';
    }
    return Accepted;
}

// B...a