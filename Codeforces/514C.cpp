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

int n, L, a[maxn];
bool check(double T){
  double l = 0, r = L;
  int v1 = 1, v2 = 1;
  double t = T;
  forn(i, 1, n + 1){
    double cur = (a[i] - l + .0) / (v1 + .0);
    if(cur <= t){
      t -= cur;
      v1++;
      l = a[i];
    }else{
      l += t * (v1 + .0);
      break;
    }
  }
  t = T;
  forev(i, n, 0){
    double cur = (r - a[i] + .0) / (v2 + .0);
    if(cur <= t){
      t -= cur;
      v2++;
      r = a[i];
    }else{
      r -= t * (v2 + .0);
      break;
    }
  }     
  return (l >= r);
}
void solve(){
  cin >> n >> L;
  forn(i, 1, n) cin >> a[i];
  a[n + 1] = L;
  double l = 0, r = 1e9;
  bool ok = 0;
  forn(iter, 1, 100){
    double mid = (l + r) / 2.0;
    if(check(mid)) r = mid, ok = 1;
    else l = mid;
  }
  cout << fixed << setprecision(7) << r << endl;
}

main () {
  int t = 1;
  cin >> t;
  //scanf("%d", &t);
  while(t--)
    solve(); 
}               