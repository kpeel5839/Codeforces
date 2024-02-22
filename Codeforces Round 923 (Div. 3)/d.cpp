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

void init(vi& tree, int height) {
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("d.input.txt", "r", stdin);
  
  int t; cin >> t;

  while (t-- > 0) {
    int n; cin >> n;
    vi arr;

    for (int i = 0; i < n; i++) {
      int v; cin >> v; arr.push_back(v);
    }
    
    vi dif;
  
    for (int i = 1; i < n; i++) {
      if (arr[i] != arr[i - 1]) {
        dif.push_back(i + 1);
      }
    }

    int q; cin >> q;

    for (int i = 0; i < q; i++) {
      int a, b; cin >> a >> b;
      
      int tmp = max(a, b);
      a = min(a, b);
      b = tmp;

      int l = 0;
      int r = dif.size() - 1;
      int result = -1;

      while (l <= r) {
        int m = (l + r) / 2;
        
        if (a < dif[m]) {
          r = m - 1;
          result = dif[m];
        } else {
          l = m + 1;
        }
      }

      if (result != -1 && result <= b) {
        cout << result - 1 << " " << result << "\n";
        continue;
      }
      cout << "-1 -1" << "\n";
    }

    cout << "\n";
  }

	return 0;
}