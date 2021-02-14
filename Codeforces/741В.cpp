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
 
const int maxn = (int)1e5 + 10;
const int maxM = (int)1.5e7 + 100;
const int mod = (int)1e9 + 7;
const int P = (int) 1e6 + 7; 
const double pi = acos(-1.0);
 
#define inf mod
  
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;                        
typedef array<int, 3> triple;

int n;
vector<pair<int, char> > g[maxn];
void dfs1(int v){
  sz[v] = 1;
  for(auto [to : cur] : g[v]){
    
  }
}
void solve(int T = 0){
  scanf("%d", &n);
  forn(v, 2, n){
    int p;
    char cur;
    scanf("%d %s\n", &p, cur);
  }
  dfs1(1);
    
   
}

main () {
  //freopen("zeros.in","r",stdin);
  int t = 1;
  //scanf("%d", &t);
  forn(i, 1, t)
    solve(i); 
}     