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

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("e.input.txt", "r", stdin);

  int t; cin >> t;

  while (t-- > 0) {
    int n, k; cin >> n >> k;
    
    vi answer(n, 0);
    vb visited(n, false);
    int highValue = n;
    int lowValue = 1;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j += k) {
        if (visited[j]) {
          break;
        }
        visited[j] = true;

        if (i % 2 == 0) {
          answer[j] = highValue;
          highValue--;
        } else {
          answer[j] = lowValue;
          lowValue++;
        }
      }
    }

    for (auto v : answer) {
      cout << v << " ";
    }
    cout << "\n";
  }

	return 0;
}