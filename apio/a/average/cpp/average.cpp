#include "average.h"
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
//#pragma GCC target("avx,avx2")
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

void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
  // cin.exceptions(cin.failbit); 
  // throws exception when do smth illegal
  // ex. try to read letter into int
  if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 2e5 + 123;                                          
const int M = 199999;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd (int l, int r) {
  return uniform_int_distribution<int> (l, r)(gen);
}
int ptr;
ll f[N];

using pt = pair<ld, ll>;

ld eval(pt a, ld x) {
  return a.first * x + a.second;
}

vector < pt > st[N*4];
int cnt[N*4];

ld inter(pt a, pt b) {
    return (ld)(a.S - b.S) / (ld)(b.F - a.F);
}

bool is_bad(pt a, pt b, pt c) {
    return inter(b, c) < inter(b, a);
}  

void add (vector < pt > &st, pt x) {
  int len = sz(st);
  
  if (len && st[len-1].second >= x.second) return;
  
  while(len > 1 && is_bad(st[len - 2], st[len-1], x)) {
    st.pop_back(); --len;
  }
  
  st.pb(x);
}

ld get (vector < pt > &st, ld x) {
  int l = 0, r = sz(st) - 1;
    while (r - l > 3) {
    int mid = (l + r) >> 1;
        if (eval(st[mid], x) <= eval(st[mid + 1], x)) {
            l = mid + 1;
        } else r = mid;
  }
    ld res = -1e50;
    while (l <= r) {
    res = max(res, eval(st[l], x));
    ++l;
  }
  
    return res;
}

void init() {
  for (int v = 1; v <= ptr * 4; ++v) {
    st[v].clear();
    cnt[v] = 0;
  }
  ptr = 0;
}

void upd (int p, int v = 1, int tl = 1, int tr = M) {
  ++cnt[v];
  
  if (tl == tr) {
    st[v].pb(mp(p, -f[p]));
    return;
  }
  
  int tm = (tl+tr) >> 1;
  if (p <= tm) upd (p, v<<1, tl, tm);
  else upd (p, v<<1|1, tm + 1, tr);
  
  if(cnt[v] == tr - tl + 1) {
    st[v].clear();
    cnt[v] = 0;
    
    for (auto it : st[v<<1|1])
      add(st[v], it);
    for (auto it : st[v<<1])
      add(st[v], it);
    
  }
}
vector < int > ver;
void get (int l, int r, int v = 1, int tl = 1, int tr = M) {
  if (l > tr || r < tl) return;
  if (tl >= l && tr <= r) {
    ver.pb(v);
    return;
  }
  
  int tm = (tl+tr) >> 1;
  get(l, r, v<<1, tl, tm);
  get(l, r, v<<1|1, tm + 1, tr);
}

void addMonth(int K) {
  
  if(ptr) upd (ptr);
  ++ptr;
  f[ptr] = f[ptr-1] + K;
}

double maximumAverage(int L, int R) {
  ld zer = 0;
  if(!L) {
    zer = (ld)(f[ptr] - f[L]) / ptr;  
    ++L;
  }
  
  ld l = zer, r = 1e18+1;
  r /= 1e9;
  
  ver.clear();
  if(L <= R)
    get(L, R);
  
  for (int it = 0; it < 100; ++it) {
    ld x = (l+r) / 2;
    ld res = -1e50;
    
    for (auto v : ver) res = max(res, get(st[v], (ld)x));
    
    if (res < x * (ld)ptr - f[ptr])
      r = x;
    else
      l = x;
  }
  return l;
}