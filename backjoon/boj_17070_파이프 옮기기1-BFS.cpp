/*
boj_17070_파이프 옮기기 1(난이도 : 골드5)
BFS
문제 조건에 맞게 단순 BFS 구현
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <set>
#include <bitset>
#include <climits>
#include <functional>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N;
int arr[17][17];

typedef struct node {
	int type, h, w;
}Node;

typedef vector<vii> vvii;

vii range = { {0,2},{1,2},{2,0},{2,1},{1,2},{2,1},{2,2} };
vii moved = { {0,1},{0,1},{1,0},{1,0},{1,1},{1,1},{1,1} };
vvii needempty = {
{{0,2}},
{{1,1},{1,2},{0,2}},
{{2,0}},
{{2,0},{2,1},{1,1}},
{{1,2}},
{{2,1}},
{{2,1},{2,2},{1,2}}
};
vi nexttype = { 0,2,1,2,0,1,2 };
vii tpyerange = { {0,2},{2,4},{4,7} };
vii candidate = { {0,1},{1,0},{1,1} };
int bfs() {
	queue<Node> q;
	q.push({ 0,1,1 });

	int t = 0;
	int cnt = 0;
	for (t; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			Node now = q.front();
			q.pop();
			int start = tpyerange[now.type].first;
			int end = tpyerange[now.type].second;
			for (start; start != end; start++) {
				if (now.h + range[start].first > N || now.w + range[start].second > N) continue;
				int flag = 0;
				for (flag; flag < needempty[start].size(); flag++) {
					int i = now.h + needempty[start][flag].first;
					int j = now.w + needempty[start][flag].second;
					if (arr[i][j] != 0) break;
				}
				if (flag != needempty[start].size()) continue;

				int type = nexttype[start];
				int i = now.h + moved[start].first;
				int j = now.w + moved[start].second;
				if (i == N && j == N) {
					cnt++;
					continue;
				}
				else if (i + candidate[type].first == N && j + candidate[type].second == N) {
					cnt++;
					continue;
				}
				else {
					if (type == 0 && j + 1 == N) continue;
					else if (type == 1 && i + 1 == N) continue;
					q.push({ type,i,j });
				}
			}
		}
	}

	return cnt;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	cout << bfs() << "\n";

	return 0;
}
