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
 
const int maxn = (int)2e5 + 10;
const ll BIG = (ll)1e18;
const int maxM = (int)1.5e7 + 100;
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


int n, m, a[maxn], b[maxn], c[maxn], d[maxn];
pii p1[maxn], p2[maxn];

int get(int x){
  int mx = 0;
  forn(i, 1, n){
    int curA = a[i] + x;
    forn(j, 1, 2){
      if(curA > c[j]) continue;
      mx = max(mx, d[j] - b[i] + 1);
    }
  }
  return x + mx;
}
multiset<pii> s[3];
multiset<int> bs[3];
void solve(){
  cin >> n >> m;
  forn(i, 1, n) {
    cin >> a[i] >> b[i];
    s[1].insert({a[i], b[i]});
    s[2].insert({a[i], b[i]});
    bs[1].insert(b[i]);
    bs[2].insert(b[i]);
  }
  forn(i, 1, m) {       
    cin >> c[i] >> d[i];
    p1[i] = {c[i], d[i]};
    p2[i] = {d[i], c[i]};
  }
  sort(p1 + 1, p1 + m + 1);
  sort(p2 + 1, p2 + m + 1);
  c[1] = p1[m].f, d[1] = p1[m].s;
  c[2] = p2[m].s, d[2] = p2[m].f;
  int ans = inf;
  forn(x, 0, 2000000){
    int mx = 0;
    forn(i, 1, 2){
      while(sz(s[i])){
        auto it = *s[i].rbegin();
        if(it.f > c[i] - x){
          bs[i].erase(bs[i].find(it.s));
          s[i].erase(s[i].find(it));
        }else break;  
      }
      if(sz(bs[i])){
        auto x = *bs[i].begin();
        mx = max(mx, d[i] - x + 1);
      }                
    }
    ans = min(ans, mx + x);
  }
  cout << ans;
}

main () {
  int t = 1;
  //scanf("%d", &t);
  while(t--)
    solve(); 
}     