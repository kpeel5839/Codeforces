#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
#define y first
#define x second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
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

const ll MOD=1e7;
vi zf(string& s){
    int n=s.size();
    int L=0,R=0;
    vi z(n,0);
    for(int i=1;i<n;i++){
        if(i<=R){
            z[i]=min(z[i-L],R-i+1);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            z[i]++;
        }
        if(R<i+z[i]-1){
            R=i+z[i]-1;L=i;
        }
    }
    return z;
}
int f(int m,vi& z){
    int n=z.size();
    int cnt=1;
    for(int i=m;i<n;){
        if(z[i]>=m){
            cnt++;
            i+=m;
        }else{
            i++;
        }
    }
    return cnt;
}
void solve() {
    int n,l,r;cin>>n>>l>>r;
    string s;cin>>s;
    vi ans(n+1,0);
    int e=ceil(sqrt(n));
    vi z=zf(s);
    for(int i=1;i<=e;i++){
        int left=1;
        int right=n;
        int ansValue=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(f(mid,z)>=i){
                ansValue=mid;
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        ans[i]=ansValue;
    }
    for(int i=1;i<=e;i++){
        int cnt=1;
        for(int j=i;j<n;){
            if(z[j]>=i){
                cnt++;
                j+=i;
            }else{
                j++;
            }
        }
        ans[cnt]=max(ans[cnt],i);
    }
    for(int i=n-1;e<=i;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    for(int i=l;i<=r;i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("h.input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    return 0;
}
