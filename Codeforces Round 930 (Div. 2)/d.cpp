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

int n;
string s;
struct comp{
    bool operator()(ll o1,ll o2){
        return o1>o2;
    }
};
void solve() {
    cin>>n>>s;
    vl dis(n+1,0);
    {
        priority_queue<ll,vl,comp>left;
        vl right;
        for(int i=0;i<n;i++){
            if(s[i]=='>'){
                left.push(i+1);
            }else{
                right.push_back(i+1);
            }
        }
        deque<ll>leftQ;
        ll leftSum=0;
        ll rightSum=0;
        int rightLeftPointer=0;
        int rightRightPointer=0;
        for(int i=1;i<=n;i++){
            while(left.size()!=0&&left.top()<i){
                leftQ.push_back(left.top());left.pop();
                leftSum+=leftQ.back();
            }
            while(rightLeftPointer<right.size()&&right[rightLeftPointer]<=i){
                rightSum-=right[rightLeftPointer];rightLeftPointer++;
                rightSum=max(0ll,rightSum);
                rightRightPointer=max(rightRightPointer,rightLeftPointer);
            }
            while(rightRightPointer<right.size()&&rightRightPointer-rightLeftPointer<leftQ.size()){
                rightSum+=right[rightRightPointer];rightRightPointer++;
            }
            while(rightRightPointer-rightLeftPointer+1<leftQ.size()){
                leftSum-=leftQ.front();leftQ.pop_front();
            }
            if(s[i-1]=='>'){
                continue;
            }
            if(leftQ.size()!=0){
                if(leftQ.size()==rightRightPointer-rightLeftPointer+1){
                    dis[i]=rightSum*2-leftSum*2+leftQ.back()+leftQ.front()+n-leftQ.front()+1+i-leftQ.back();
                }else{
                    dis[i]=rightSum*2-leftSum*2+leftQ.back()+i-leftQ.back();
                }
            }else{
                dis[i]=i;
            }
        }
    }
    {
        priority_queue<ll,vl,comp>left;
        vl right;
        for(int i=0;i<n;i++){
            if(s[i]=='<'){
                left.push(n-i);
            }else{
                right.push_back(n-i);
            }
        }
        sort(right.begin(),right.end());
        deque<ll>leftQ;
        ll leftSum=0;
        ll rightSum=0;
        int rightLeftPointer=0;
        int rightRightPointer=0;
        for(int i=1;i<=n;i++){
            while(left.size()!=0&&left.top()<i){
                leftQ.push_back(left.top());left.pop();
                leftSum+=leftQ.back();
            }
            while(rightLeftPointer<right.size()&&right[rightLeftPointer]<=i){
                rightSum-=right[rightLeftPointer];rightLeftPointer++;
                rightSum=max(0ll,rightSum);
                rightRightPointer=max(rightRightPointer,rightLeftPointer);
            }
            while(rightRightPointer<right.size()&&rightRightPointer-rightLeftPointer<leftQ.size()){
                rightSum+=right[rightRightPointer];rightRightPointer++;
            }
            while(rightRightPointer-rightLeftPointer+1<leftQ.size()){
                leftSum-=leftQ.front();leftQ.pop_front();
            }
            if(s[n-i]=='<'){
                continue;
            }
            if(leftQ.size()!=0){
                if(leftQ.size()==rightRightPointer-rightLeftPointer+1){
                    dis[n-i+1]=rightSum*2-leftSum*2+leftQ.back()+leftQ.front()+n-leftQ.front()+1+i-leftQ.back();
                }else{
                    dis[n-i+1]=rightSum*2-leftSum*2+leftQ.back()+i-leftQ.back();
                }
            }else{
                dis[n-i+1]=i;
            }
        }
    }
    for(int i=1;i<dis.size();i++){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("d.input.txt", "r", stdin);
    int T; cin >> T;
    while (T-- > 0) {
        solve();
    }
	return 0;
}