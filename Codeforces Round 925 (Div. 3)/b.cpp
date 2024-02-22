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
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef vector<viii> viiii;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<vll> vlll;
typedef vector<vlll> vllll;
typedef vector<char> vc;
typedef vector<vc> vcc;
typedef vector<vcc> vccc;
typedef vector<vccc> vcccc;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef vector<vbb> vbbb;
typedef vector<vbbb> vbbbb;
const ll INF = 1e18;
const int inf = 2e9;
const int size = 1 << 18;
const int mod = 1e9 + 7;

void solve() {
  int N; cin >> N;
  vi arr(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  int average = sum / N;
  int exceed = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i] < average) {
      exceed-=(average-arr[i]);
    } else {
      exceed+=arr[i]-average;
    }
    if (exceed < 0) {
      cout << "NO"<<"\n";
      return;
    }
  }
  cout<<"YES"<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("b.input.txt", "r", stdin);
  int T; cin >> T;
  while (T-- > 0) {
    solve();
  }
	return 0;
}