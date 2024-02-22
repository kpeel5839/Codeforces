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
const ll INF = 1e18;
const int inf = 2e9;
const int SIZE = 1 << 18;
const int MOD = 1e9 + 7;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int t; cin >> t;

  while (t-- > 0) {
    int n, k, m; cin >> n >> k >> m;
    string s; cin >> s;
    vector<int> point;
    unordered_set<char> set;

    for (int i = 0; i < m; i++) {
      char c = s.at(i);

      if (k < (c - 'a' + 1)) {
        continue;
      }

      set.insert(c);
      if (set.size() == k) {
        point.push_back(i);
        set.clear();
      }
    }

    if (n <= point.size()) {
      cout << "YES" << endl;
      continue;
    }

    cout << "NO" << endl;
    string answer;
    for (auto index : point) {
      answer.push_back(s.at(index));
    }

    for (int i = 0; i < k; i++) {
      char c = i + 'a';
      if (set.end() == set.find(c)) {
        answer.push_back(c);
        break;
      }
    }
    
    while (answer.length() != n) {
      for (int i = k - 1; 0 <= i; i--) {
        answer.push_back(i + 'a');

        if (answer.length() == n) {
          break;
        }
      }
    }
    
    cout << answer << endl;
  }

	return 0;
}