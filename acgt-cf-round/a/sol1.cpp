#include <bits/stdc++.h>
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)1e3 + 10;
const int mod = (int)1e9 + 7;
const int P = (int) 1e6 + 7; 
const double pi = acos(-1.0);
 
#define inf mod
                        
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;                        
typedef array<int, 3> triple;


int n, a[maxn], dp[maxn][maxn], pr[maxn];
vi g[maxn];


void solve(){
  scanf("%d", &n);
  forn(i, 1, n) 
    scanf("%d", &a[i]);
  forn(i, 1, n)
    forn(j, 0, n)
      dp[i][j] = inf;
  dp[1][0] = 1;
  a[n + 1] = inf;
  forn(i, 1, n){     
    int dp0 = inf, dp1 = inf;
    forn(j, 0, i - 1){
      cout << dp[i][j] << " ";
      if(dp[i][j] == inf) continue;
      if(a[j] == a[i + 1]) dp1 = min(dp1, dp[i][j]);
      else dp0 = min(dp0, dp[i][j]);
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + (a[i + 1] != a[i]));
      dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + (a[i + 1] != a[j]));
    }
    cout << endl;
  }
  int ans = inf;
  forn(i, 0, n - 1) ans = min(ans, dp[n][i]);
  printf("%d\n", ans);
}
main () {   
  int t = 1;
  //scanf("%d", &t);
  while(t--)
    solve();
}                                                                     