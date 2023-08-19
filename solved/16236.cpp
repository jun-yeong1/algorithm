#include <bits/stdc++.h>

using namespace std;

int n, shark = 2, result = 0; // 맵 크기, 상어 크기, 시간
int eat = 0; // 먹은 수
int graph[22][22]; // 맵 저장
int visited[22][22];
pair<int, int> now_shark; // 현재 상어 위치
// x, y 위치
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<pair<int, pair<int, int> > > find_food() {
  // 시간, x좌표, y좌표
  vector<pair<int, pair<int, int> > > eat_dir; // 먹이 위치 저장 백터
  queue<pair<int, int> > q;
  q.push({now_shark.first, now_shark.second});
  visited[now_shark.first][now_shark.second] = 1; // 처음 상어 위치 방문처리
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    // 위치
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (0 <= nx && nx < n && 0 <= ny && ny < n) {
        if (visited[nx][ny] != 0) continue; // 방문했으면 패스
        if (graph[nx][ny] > shark) continue; // 상어 크기보다 크면 패스
        else if (graph[nx][ny] == shark || graph[nx][ny] == 0) {
          q.push({nx, ny});
          visited[nx][ny] = visited[x][y] + 1; // 지나갈 위치를 현재 위치에 +1(거리)
          continue;
        }
        else if (graph[nx][ny] < shark) { // 먹을 수 있는 먹이 만나면
          eat_dir.push_back({visited[x][y], {nx, ny}}); // 먹이 벡터에 위치와 거리 저장
        }
      }
    }
  }
  return eat_dir; //먹이 위치 벡터 반환
}

int eat_food(vector<pair<int, pair<int, int> > > eat_dir){
  if (eat_dir.size() == 0) { // 먹이 없는 경우
    cout << result;
    return 0;
  }
  else if (eat_dir.size() == 1) { // 먹이가 하나인 경우
    result += eat_dir[0].first; // 먹이 벡터 시간 더해주기
    eat++; //먹은 개수 +1
    if(eat == shark) { // 상어가 ??
      eat = 0;
      shark++;
    }
    graph[now_shark.first][now_shark.second] = 0;
    now_shark.first = eat_dir[0].second.first;
    now_shark.second = eat_dir[0].second.second;
    graph[now_shark.first][now_shark.second] = 0;
    return 1;
  }
  else { // 먹이 두 개 이상
    sort(eat_dir.begin(), eat_dir.end()); // 먹이 위치 벡터 정렬
    int min_dir = eat_dir[0].first;
    int top = 100000, left = 100000;
    int idx = 0;

    for (int i = 0; i < eat_dir.size(); i++) {
      if (eat_dir[i].first == min_dir) {
        if (eat_dir[i].second.first < top) {
          top = eat_dir[i].second.first;
          left = eat_dir[i].second.second;
          idx = i;
        }
        if (eat_dir[i].second.first == top) {
          if (eat_dir[i].second.second < left) {
            left = eat_dir[i].second.second;
            idx = i;
          }
        }
      }
    }
    result += eat_dir[idx].first;
    eat++;
    if (eat == shark) {
      eat = 0;
      shark++;
    }
    graph[now_shark.first][now_shark.second] = 0;
    now_shark.first = eat_dir[idx].second.first;
    now_shark.second = eat_dir[idx].second.second;
    graph[now_shark.first][now_shark.second] = 0;

    return 1;
  }
}

int main() {
  cin >> n;
  getchar();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%1d", &graph[i][j]); // 맵 저장
      if (graph[i][j] == 9) { //상어 처음 위치 저장
        now_shark = {i, j};
        graph[i][j] = 0; //상어 처음 위치를 0으로
      }
    }
    getchar();
  }
  while(1) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) visited[i][j] = 0;
    }
    vector<pair<int, pair<int, int> > > eat_dir = find_food();
    int check = eat_food(eat_dir);
    if (check == 0) break;
    eat_dir.clear();
  }
  return 0;
}