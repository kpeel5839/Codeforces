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

void printArray(vi& arr) {
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

struct comp {
  bool operator()(vi& p1, vi& p2) {
    return p1[3] > p2[3];
  }
};

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// freopen("b.input.txt", "r", stdin);

  int t; cin >> t;

  while (t-- > 0) {
    int n; cin >> n;
    vi a(n, 0);
    vi b(n, 0);
    priority_queue<vi, vector<vi>, comp> q;
    
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    for (int i = 1; i < n; i++) {
      q.push({i, a[i], b[i], a[i] + b[i]});
    }

    for (int i = 0; i < n; i++) {
      while (q.size() != 0 && q.top()[3] < a[i] + b[i]) {
        if (q.top()[0] <= i) {
          q.pop();
          continue;
        }

        vi v = q.top();
        q.pop(); q.push({v[0], a[i], b[i], a[i] + b[i]});
        a[v[0]] = a[i];
        b[v[0]] = b[i];
        a[i] = v[1];
        b[i] = v[2];
      }
    }
    
    printArray(a);
    printArray(b);
  }

	return 0;
}