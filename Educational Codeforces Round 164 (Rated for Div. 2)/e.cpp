#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> arr;
vector<long long> tree;
long long n;
long long height;
long long leafNodeCnt;
vector<long long> add;
vector<long long> cnt;

void initTree() {
    for (int i = height - 1; 0 <= i; i--) {
        for (int j = 1 << i; j < (1 << (i + 1)); j++) {
            long long leftIdx = tree[2 * j];
            long long rightIdx = tree[2 * j + 1];
            if (arr[leftIdx] <= arr[rightIdx]) {
                tree[j] = leftIdx;
            } else {
                tree[j] = rightIdx;
            }
        }
    }
}

long long searchMin(int cur, int left, int right, int sl, int sr) {
    if (sl <= left && right <= sr) {
        return tree[cur];
    }
    if (sr < left || right < sl) {
        return 0;
    }
    long long leftIdx = searchMin(cur * 2, left, (left + right) / 2, sl, sr);
    long long rightIdx = searchMin(cur * 2 + 1, (left + right) / 2 + 1, right, sl, sr);
    if (arr[leftIdx] <= arr[rightIdx]) {
        return leftIdx;
    }
    return rightIdx;
}

void dnq(long long left, long long right) {
    if (left == right) {
        add[arr[left]]--;
        return;
    }
    long long addSum = -1;
    long long minIdx = searchMin(1, 1, leafNodeCnt, left, right);
    if (left != minIdx) {
        dnq(left, minIdx - 1);
        addSum++;
    }
    if (right != minIdx) {
        dnq(minIdx + 1, right);
        addSum++;
    }
    add[arr[minIdx]] += addSum;
}

void solve() {
    cin >> n;
    arr.resize(n + 1, 0);
    arr[0] = 2e9;
    long long maxElement = 0;
    for (int i = 1; i < arr.size(); i++) {
        cin >> arr[i];
        maxElement = max(maxElement, arr[i]);
    }
    height = ceil(log2(n));
    leafNodeCnt = 1 << height;
    tree.resize(leafNodeCnt * 2, 0);
    for (int i = 0; i < n; i++) {
        tree[i + leafNodeCnt] = i + 1;
    }
    initTree();
    add.resize(maxElement + 2, 0);
    cnt.resize(maxElement + 2, 0);
    dnq(1, n);
    long long addSum = 1;
    for (int i = 1; i < add.size(); i++) {
        cnt[i] = addSum;
        addSum += add[i];
    }
    for (int i = 1; i <= maxElement; i++) {
        long long result = 0;
        long long num = 0;
        while (true) {
            if (cnt.size() <= num + 1 || cnt[num + 1] == 0) {
                break;
            }
            result += cnt[num + 1];
            num += i;
        }
        cout << result << " ";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("e.input.txt", "r", stdin);
    solve();
    return 0;
}
