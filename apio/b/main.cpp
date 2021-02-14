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
 
const int maxn = (int)5e4 + 10;
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

int n, k;
struct node{
  int mx[11], mn[11], a[11], sz;
  node(){
    forn(i, 1, k) mx[i] = mn[i] = a[i] = 0;
    sz = 0;
  }
  void build(){
    forn(i, 1, k)
      mn[i] = mx[i] = a[i];
    sz = 1;
  }         
};
set<node> comp;

inline node merge(node a, node b){
  node s = node();
  s.sz = a.sz + b.sz;       
  forn(i, 1, k){
    s.mn[i] = min(a.mn[i], b.mn[i]);
    s.mx[i] = max(a.mx[i], b.mx[i]);
  }
  return s;
}
bool operator < (node a, node b){
  forn(i, 1, k)
    if(b.mx[i] > a.mn[i])
      return 0;
  return 1;
}
bool win(node a, node b){
  forn(i, 1, k)
    if(a.mx[i] > b.mn[i])
      return 1;
  return 0;
}
                                    `
inline void add(node x){
  auto it = comp.lower_bound(x);
  vector<node> del;        
  while(it != comp.end() && win(*it, x)){
    x = merge(x, *it);          
    it = comp.erase(it);
  }
  comp.insert(x);      
  /*for(auto x : comp){
    cout << x.sz << "\n";
    forn(i, 1, k) cout << x.mn[i] << " " << x.mx[i] << endl;
  }*/
  //cout << sz(comp) << " " << x.sz << " " << comp.begin() -> sz << endl;
}
void solve(int T){
  scanf("%d%d", &n, &k);
  forn(i, 1, n){
    node x;
    forn(j, 1, k)
      scanf("%d", &x.a[j]);                 
    x.build();                                          
    add(x);                        
    printf("%d\n", comp.begin() -> sz);
  }
}

main () {
  int t = 1;
  //scanf("%d", &t);
  forn(i, 1, t)
    solve(i); 
}     