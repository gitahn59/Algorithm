/*
boj_10026_적록색약(난이도 : 골드5)
bfs
bfs를 이용한 구역 개수 판단
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
int arr[105][105];
int brr[105][105];

int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

void bfs(int h, int w, int num, int arr[][105]) {
	queue<ii> q;
	q.push({ h,w });
	int target = arr[h][w];
	arr[h][w] = num;

	while (!q.empty()) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			ii now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int i = ni[k] + now.first;
				int j = nj[k] + now.second;

				if (i < 0 || i == N || j < 0 || j == N) continue;
				if (arr[i][j] != target) continue;
				arr[i][j] = num;
				q.push({ i,j });
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	char str[110];
	for (int n = 0; n < N; n++) {
		cin >> str;
		for (int i = 0; i < N; i++) {
			arr[n][i] = str[i];
			if (str[i] == 'G') {
				brr[n][i] = 'R';
			}
			else {
				brr[n][i] = str[i];
			}
		}
	}

	int num = 1000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] < 1000) {
				bfs(i, j, num, arr);
				num++;
			}
		}
	}

	cout << num - 1000 << " ";
	num = 1000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (brr[i][j] < 1000) {
				bfs(i, j, num, brr);
				num++;
			}
		}
	}
	cout << num - 1000 << "\n";

	return 0;
}
