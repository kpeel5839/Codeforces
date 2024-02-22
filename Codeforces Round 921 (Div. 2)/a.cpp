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

  int t;
  cin >> t;
  
  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    
    string s = "";
    for (int i = 0; i < k; i++) {
      s.push_back(i + 'a');
    }

    string answer;
    for (int i = 0; i < n; i++) {
      answer.append(s);
    }

    cout << answer << endl;
  }

	return 0;
}