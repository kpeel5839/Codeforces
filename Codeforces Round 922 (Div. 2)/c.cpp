#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <string.h>
#include <cstdio>
#include <cmath> 
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vector<int> > vii;
typedef vector<vector<ll> > vll;
typedef vector<vector<vector<int> > > viii;
typedef vector<vector<vector<vector<int> > > > viiii;
typedef vector<vector<vector<ll> > > vlll;
typedef vector<vector<vector<vector<ll> > > > vllll;
typedef vector<bool> vb;
typedef vector<vector<bool> > vbb;
typedef vector<vector<vector<bool> > > vbbb;
typedef vector<vector<vector<vector<bool> > > > vbbbb;
const ll INF = 1e18;
const int inf = 2e9;
const int SIZE = 1 << 18;
const int MOD = 1e9 + 7;

void printArray(vii& arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << "";
    }
    cout << "\n";
  }
}

ll calculate(ll a, ll b, ll m) {
  return abs((a ^ m) - (b ^ m));
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("c.input.txt", "r", stdin);

  int t; cin >> t;
  
  while (t-- > 0) {
    ll a, b, r; cin >> a >> b >> r;

    if (b < a) {
      ll tmp = a;
      a = b;
      b = tmp;
    }

    bool firstBitFound = false;
    ll sum = 0;
  
    for (int i = 62; 0 <= i; i--) {
      int ab = ((a & (1ll << i)) != 0) ? 1 : 0;
      int bb = ((b & (1ll << i)) != 0) ? 1 : 0;

      if (!firstBitFound && (ab == 0 && bb == 1)) {
        firstBitFound = true;
        continue;
      }

      if (!firstBitFound) {
        continue;
      }
      
      if (ab == bb) {
        continue;
      }
      
      if (ab == 0 && (sum + (1ll << i)) <= r) {
        a += (1ll << i);
        b -= (1ll << i);
        sum += (1ll << i);
      }
    }

    cout << abs(b - a) << "\n";
  }

	return 0;
}