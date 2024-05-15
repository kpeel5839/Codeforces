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
typedef vector<double> vd;
typedef vector<vd> vdd;
typedef vector<vdd> vddd;
typedef vector<vddd> vdddd;
const ll INF = 1e18;
const int inf = 2e9;
const int size = 1 << 18;
double MOD=998244353;
vl assignSize(2e5+1,0);
double mod(double a){
    if(abs(a)<MOD){
        return a;
    }
    if(a<0){
        a+=floor((abs(a)-MOD)/MOD)*MOD;
    }else{
        a-=floor((abs(a)-MOD)/MOD)*MOD;
    }
    while(abs(a)>=MOD){
        if(a<0){
            a+=MOD;
        }else{
            a-=MOD;
        }
    }
    return a;
}
double add(double a,double b){
    return mod(a+b);
}
double sub(double a,double b){
    a=mod(a);
    b=mod(b);
    return mod(a+MOD-b);
}
void solve() {
    double n,k;cin>>n>>k;
    vd arr(n+1,0);
    vd arr1(n+1,0);
    vd arr2(n+1,0);
    vd se(n+1,0);
    vd th(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){//arr1, second 구하기
        if(assignSize[i]==1){
            arr1[i]=arr[i];
            se[i]=add(arr1[i],se[i-1]);
        }else{
            ll as=assignSize[i];
            double v=sub(se[i-1],se[i-as]);
            arr1[i]=sub(arr[i],v);
            se[i]=add(arr1[i],se[i-1]);
        }
    }
    for(int i=1;i<=n;i++){//arr2, third 구하기
        if(assignSize[i]==1){
            arr2[i]=arr[i];
            th[i]=add(arr2[i],th[i-1]);
        }else{
            ll as=assignSize[i];
            double v=sub(th[i-1],th[i-as]);
            arr2[i]=sub(arr1[i],v);
            th[i]=add(arr2[i],th[i-1]);
        }
    }
    if(k==1){
        for(int i=1;i<arr1.size();i++){
            cout<<arr1[i]<<" ";
        }
        cout<<"\n";
        return;
    }else if(k==2){
        for(int i=1;i<arr2.size();i++){
            cout<<arr2[i]<<" ";
        }
        cout<<"\n";
        return;
    }    
    vd ans(n+1,0);
    vd sum(n+1,0);
    sum[1]=mod(arr[1]*k);
    ans[1]=arr[1];
    for(int i=1;i<=n;i++){
        if(assignSize[i]==1){
            ans[i]=arr[i];
            sum[i]=add(sum[i-1],arr[i]*k);
            continue;
        }
        ll as=assignSize[i];
        double v=sub(sum[i-1],sum[i-as]);
        ans[i]=sub(arr[i],v);
        double diff1=sub(arr[i],arr1[i]);
        double diff2=sub(arr1[i],arr2[i]);
        double diff3=diff2-diff1;
        double a=mod((((1+k)*k)/2*diff1));
        double b=mod((((1+k-1))*(k-1)/2*diff3));
        double diff4=mod(a+b);
        sum[i]=add(sum[i-1],sub(arr[i]*k,diff4));
    }
    for(int i=1;i<=n;i++){
        cout<<(ll)mod(ans[i])<<" ";
    }
    cout<<"\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("f.input.txt", "r", stdin);
    for(int i=1;i<=2e5;i++){
        for(int j=0;j<20;j++){
            if((i&(1<<j))!=0){
                assignSize[i]=1<<j;
                break;
            }
        }
    }
    int T;
    cin >> T;
    while (T-- > 0) {
        solve();
    }
    return 0;
}
