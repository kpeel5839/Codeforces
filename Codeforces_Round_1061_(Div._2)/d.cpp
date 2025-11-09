class Solution {
  public:
    typedef vector<int> vi;
    typedef vector<vi> vii;
    typedef vector<bool> vb;
    typedef vector<vb> vbb;
    vii mat;
    int h, w;
    vi dy = {0, -1, 0, 1};
    vi dx = {-1, 0, 1, 0};

    vi parent;
    vi ranked;
    unordered_set<int> f;

    int flood = 0;
    int trapped = 0;

    bool isOutOfRange(int y, int x) {
      return y < 0 || y >= h || x < 0 || x >= w;
    }

    int getIdx(int i, int j) { return i * w + j; }

    int find(int x) {
      if (parent[x] == x) {
        return x;
      }
      return parent[x] = find(parent[x]);
    }

    void uni(int a, int b) {
      // a, b의 부모를 찾고, 이가 f라면 trapped에서 빼준다.
      // 만일, 새롭게 f가 되는 것이 아니라면, f에서 빼주지 않는다.
      a = find(a);
      b = find(b);

      if (a == b) {
        return;
      }

      bool isAExists = f.find(a) != f.end();
      bool isBExists = f.find(b) != f.end();

      if (isAExists && isBExists) {
        // a, b 둘 다 있는 경우 (둘 다 flood)
        parent[b] = a;
        ranked[a] += ranked[b]; // flood는 여기서는 기록을 따로 안함
      }

      if (isAExists && !isBExists) {
        // a 만 flood (flood)
        // b 집합은 flood로 넘어가는거임, 즉 trapped에서 빼줘야함
        parent[b] = a;
        ranked[a] += ranked[b];
        trapped -=
            ranked[b]; // 대신 trapped는 요소 탐색할 때 마다, 추가해줘야함
      }

      if (!isAExists && isBExists) {
        // b 만 있는 경우 (flood)
        parent[a] = b;
        ranked[b] += ranked[a];
        trapped -= ranked[a];
      }

      if (!isAExists && !isBExists) {
        // 둘 다 flood 아닌 경우
        parent[b] = a;
        ranked[a] += ranked[b];
      }
    }

    int trapRainWater(vector<vector<int> > &heightMap) {
      this->mat = heightMap;
      this->h = mat.size();
      this->w = mat[0].size();

      map<int, vii> m;

      parent = vi(h * w, 0);
      ranked = vi(h * w, 1);
      for (int i = 0; i < parent.size(); i++) {
        parent[i] = i;
      }

      for (int i = 0; i < w; i++) {
        int idx1 = getIdx(0, i);
        int idx2 = getIdx(h - 1, i);

        f.insert(idx1);
        f.insert(idx2);
      }

      for (int i = 0; i < h; i++) {
        int idx1 = getIdx(i, 0);
        int idx2 = getIdx(i, w - 1);

        f.insert(idx1);
        f.insert(idx2);
      }

      flood = f.size();

      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          m[mat[i][j]].push_back({i, j});
        }
      }

      vector<pair<int, vii> > arr;

      for (auto &v: m) {
        arr.push_back({v.first, v.second});
      }

      sort(arr.begin(),
           arr.end(),
           [](pair<int, vii> &a, pair<int, vii> &b) {
             return a.first < b.first;
           });

      int answer = 0;

      for (int i = 0; i < arr.size(); i++) {
        int diff = (i == 0 ? 0 : arr[i].first - arr[i - 1].first);
        // cout<<"value : " <<arr[i].first<<" trapped : "<<trapped<<"\n";
        answer += (diff * trapped);

        for (auto &v: arr[i].second) {
          int y = v[0];
          int x = v[1];
          int idx = getIdx(y, x);

          if (f.find(idx) == f.end()) {
            trapped++;
          }

          for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (isOutOfRange(ny, nx) || mat[ny][nx] > mat[y][x]) {
              continue;
            }

            int nIdx = getIdx(ny, nx);
            uni(idx, nIdx);
          }
        }
      }

      return answer;
    }
};
