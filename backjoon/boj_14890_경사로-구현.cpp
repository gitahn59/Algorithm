/*
boj_14890_경사로(난이도 : 골드4)
구현
각 행과 열에 대해 조건을 검사
주의) 이미 경사로가 놓인 곳은 다시 사용할 수 없음
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

#define PRIME 1000000007

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

int tetro[5] = { 2,1,4,4,2 };
vector<vvi> model;

void init() {
	vvi md1 = { {1,1,1,1} };
	vvi md2 = { {1,1},{1,1} };
	vvi md3 = { {1,1,1},{0,1,0} };
	vvi md4 = { {1,0},{1,0},{1,1} };
	vvi md5 = { {1,0},{1,1},{0,1} };

	model.push_back(md1);
	model.push_back(md2);
	model.push_back(md3);
	model.push_back(md4);
	model.push_back(md5);
}

vvi rotate(vvi& src) {
	int h = src.size();
	int w = src[0].size();

	vvi rst(w, vi(h));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			rst[j][h - i - 1] = src[i][j];
		}
	}
	return rst;
}

vvi reverse(vvi& src) {
	int h = src.size();
	int w = src[0].size();

	vvi rst(h, vi(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			rst[i][w - j - 1] = src[i][j];
		}
	}
	return rst;
}

int N, M;
int arr[502][502];

int task(vvi& md) {
	int h = md.size();
	int w = md[0].size();
	int myMax = 0;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (n + h - 1 > N) continue;
			if (m + w - 1 > M) continue;

			int temp = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (md[i][j] == 1) {
						temp += arr[n + i][m + j];
					}
				}
			}
			myMax = max(myMax, temp);
		}
	}
	return myMax;
}

int solve() {
	int myMax = 0;
	for (int i = 0; i < 3; i++) {
		vvi md = model[i];
		for (int j = 0; j < tetro[i]; j++) {
			myMax = max(myMax, task(md));
			md = rotate(md);
		}
	}

	for (int i = 3; i < 5; i++) {
		vvi md = model[i];
		vvi rvse = reverse(model[i]);
		for (int j = 0; j < tetro[i]; j++) {
			myMax = max(myMax, task(md));
			myMax = max(myMax, task(rvse));
			md = rotate(md);
			rvse = rotate(rvse);
		}
	}

	return myMax;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	init();
	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> arr[n][m];
		}
	}

	cout << solve() << "\n";

	return 0;
}
