#include <bits/stdc++.h>

/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

*/
 
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
 
const int maxn = (int)2e5 + 100;
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

inline ll R() {
  char c;
  ll ans = 0;
  bool started = 0, is_negative = 0;
  while (true) {
    c = getchar();
    if ((c < '0' || c > '9') && c != '-' && !started) continue;
    if ((c < '0' || c > '9') && c != '-' && started) break;
    if (started) 
      ans = ans * 10ll;
    started = 1;
    if (c == '-') is_negative = 1;
    else ans += c - '0';
  }
  if (is_negative) 
    ans = -ans;
  return ans;
}

int n, mx = -1, root, p[maxn], r, ans, nxt[maxn], node, r1;
vi g[maxn];
void dfs(int v, int par = 0, int lvl = 0){
  p[v] = par;
  if(mx < lvl)
    mx = lvl, root = v;
  for(auto to : g[v])
    if(to != par)
      dfs(to, v, lvl + 1);
}
vi mxs;
void calc(int v, int par = 0, int lvl = 0){
  if(ans < lvl + mx){
    mxs.clear();
    mxs.pb(v);
    ans = lvl + mx;
  }else if(ans == lvl + mx)
    mxs.pb(v);
  for(auto to : g[v]){
    if(to == par) continue;
    if(nxt[v] == to)
      calc(to, v, lvl);
    else
      calc(to, v, lvl + 1);
  }
}
int main () {
  n = R();
  forn(i, 1, n - 1){
    int u = R(), v = R();
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  mx = -1;
  r = root;
  dfs(root);
  r1 = root;
  vi path;
  while(root){
    path.pb(root);
    root = p[root];
  }
  reverse(all(path));
  forn(i, 0, sz(path) - 2)
    nxt[path[i]] = path[i + 1];
  calc(r);
  for(auto x : mxs)
    if(x != r && x != r1)
      node = x;
  cout << ans << endl << r << " " << r1 << " " << node << endl;
}  
