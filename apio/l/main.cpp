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
 
const int maxn = (int)3e5 + 10;
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
ll b[maxn];
void solve(int T){
  scanf("%d%d", &n, &k);
  forn(i, 1, n) scanf("%lld", &b[i]);
  multiset<pair<ll, int> > q;
  int ans = 0;
  forev(i, n, 1){
    if(!sz(q)){
      q.insert({b[i], -1});
      continue;
    }
    auto it = q.lower_bound({b[i] + b[i], -inf});
    if(it == q.end()){
      q.insert({b[i], -1});
      continue;
    }else{
      int cur = it -> s;
      //cout << i << endl;
      //cout << it -> f << " == " << it -> s << endl;
      q.erase(it);
      if(cur == -(k - 1)) ans++;
      else q.insert({b[i], cur - 1});
    }
  }
  if(k == 1) ans = n;
  printf("Case #%d: %d\n", T, ans);
}

main () {
  int t = 1;
  scanf("%d", &t);
  forn(i, 1, t)
    solve(i); 
}     