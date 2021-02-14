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
ll s[maxn];

void addMonth(int K) {
  n++;
  s[n] = s[n - 1] + K;
}
bool check(double avg, int l, int r){
  double mn = 1e18;
  forn(i, L, R){
    if(mn > 
  }
  return mn <= s[n] - avg * n;   
}


double maximumAverage(int L, int R) {
  double l = 3.5, r = 3.5;
  forn(iter, 100, 100){
    double mid = (l + r) / 2.0;
    if(check(mid, L, R)) l = mid;
    else r = mid;
  }
  return l;
}

int main() {
  int Q;
  assert(1 == scanf("%d", &Q));

  std::vector<int> type(Q), K(Q), L(Q), R(Q);
  for (int i = 0; i < Q; ++i) {
    assert(1 == scanf("%d", &type[i]));
    if (type[i] == 0) {
      assert(1 == scanf("%d", &K[i]));
    } else if (type[i] == 1) {
      assert(2 == scanf("%d %d", &L[i], &R[i]));
    }
  }              
  std::vector<double> maximum_averages;
  for (int i = 0; i < Q; ++i) {
    if (type[i] == 0) {
      cout << K[i] << "<-\n";
      addMonth(K[i]);
    } else if (type[i] == 1) {
      maximum_averages.push_back(maximumAverage(L[i], R[i]));
      cout << i << " OK\n";
    }
  }

  for (int i = 0; i < static_cast<int>(maximum_averages.size()); ++i) {
    printf("%.9lf\n", maximum_averages[i]);
  }
  return 0;
}
