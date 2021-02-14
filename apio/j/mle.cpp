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
 
const int maxn = (int)2e3 + 10;
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



int n, m, db[maxn], dg[maxn], dp[maxn][maxn][5];
int p1[maxn], p2[maxn];
string b[maxn], g[maxn];
triple p[maxn][maxn][5];
bool cmp1(int a, int b){
  return db[a] > db[b];
}
bool cmp2(int a, int b){
  return dg[a] > dg[b];
}
int calc(int i, int j, int k){
  if(i == n && j == m) return 0;
  int &res = dp[i][j][k];
  if(res != -1) return res;
  res = inf;
  if(i < n && j < m){
    int x = calc(i + 1, j + 1, 2) + max(db[p1[i + 1]], dg[p2[j + 1]]);
    if(res > x)
      res = x, p[i][j][k] = {i + 1, j + 1, 2};
  }
  if(i && j < m && k + 1 <= 4){
    int x = calc(i, j + 1, k + 1);
    cout << i << " " << j << " " << k << " " << x << endl;
    if(res > x)
      res = x, p[i][j][k] = {i, j + 1, k + 1};
  }
  if(j == m){
    if(i && k <= 3){
      int x = calc(i + 1, j, k + 1);
      if(res > x)
        res = x, p[i][j][k] = {i + 1, j, k + 1};
    }
    int x = calc(i + 1, j, 1) +  + db[p1[i + 1]];
    if(res > x)
      res = x, p[i][j][k] = {i + 1, j, 1}; 
  }
  return res;
}
int id;
vector<string> taxi[maxn];
void rec(int i, int j, int k){
  if(i == n && j == m) return;
  triple cur = p[i][j][k];
  int goi = cur[0], goj = cur[1], gok = cur[2];
  if(goi - i == 1 && goj - j == 1){
    id++;
    taxi[id].pb(b[p1[goi]]);
    taxi[id].pb(g[p2[goj]]);
  }
  else if(goi == i && goj - 1 == j){
    taxi[id].pb(g[p2[goj]]);
  }else{
    if(i && gok == k + 1){
      taxi[id].pb(b[p1[goi]]);
    }else{
      id++;
      taxi[id].pb(b[p1[goi]]);
    }  
  }

  rec(goi, goj, gok);
}
void solve(int T = 0){
  cin >> n;
  forn(i, 1, n){
    cin >> b[i] >> db[i];
    p1[i] = i;
  }
  cin >> m;
  forn(i, 1, m){
    cin >> g[i] >> dg[i];
    p2[i] = i;
  }
  sort(p1 + 1, p1 + n + 1, cmp1);
  sort(p2 + 1, p2 + m + 1, cmp2);
  memset(dp, -1, sizeof(dp));
  cout << calc(0, 0, 0) << endl;
  rec(0, 0, 0);
  cout << id << endl;
  forn(i, 1, id){
    cout << "Taxi " << i << ": ";
    forn(j, 0, sz(taxi[i]) - 1){
      cout << taxi[i][j];
      if(j == sz(taxi[i]) - 1){
        cout << ".\n";
      }else if(j == sz(taxi[i]) - 2){
        cout << " and ";
      }else{
        cout << ", ";
      }
    }
  }
}

main () {
  //freopen("taxi.in","r",stdin);
  int t = 1;
  //scanf("%d", &t);
  forn(i, 1, t)
    solve(i); 
}     