/*
boj_19236_청소년 상어(난이도 : 골드3)
Simulation
문제 조건에 맞게 시뮬레이션
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

typedef struct node {
	int h, w, dir;
}Node;

int N, M;
int ni[] = { -1,-1,0,1,1,1,0,-1 };
int nj[] = { 0,-1,-1,-1,0,1,1,1 };
int nd[] = { 1,2,3,4,5,6,7,0 };
int myMax = 0;

int SHARK = 50;
int VACANT = -1;
int END = 50;

void dfs(Node shark, Node fishes[17], int arr[4][4], int cost) {
	myMax = max(myMax, cost);

	int temp_arr[4][4];
	Node temp_fishes[17];

	memcpy(temp_fishes, fishes, sizeof(Node) * 17);
	memcpy(temp_arr, arr, sizeof(4) * 4 * 4);

	for (int k = 1; k <= 16; k++) {
		if (temp_fishes[k].dir == VACANT) continue;
		else {
			int h = temp_fishes[k].h;
			int w = temp_fishes[k].w;
			int d = temp_fishes[k].dir;

			for (int a = 0; a < 8; a++) { // 이동이 가능한 방향
				int i = h + ni[temp_fishes[k].dir];
				int j = w + nj[temp_fishes[k].dir];
				if (i < 0 || i>3 || j < 0 || j>3) {
					temp_fishes[k].dir = nd[temp_fishes[k].dir];
					continue;
				}
				if (temp_arr[i][j] == SHARK) {
					temp_fishes[k].dir = nd[temp_fishes[k].dir];
					continue;
				}
				else if (temp_arr[i][j] == VACANT) {
					swap(temp_arr[i][j], temp_arr[h][w]);
					temp_fishes[k].h = i;
					temp_fishes[k].w = j;
					break;
				}
				else if (temp_arr[i][j] != SHARK && temp_arr[i][j] != VACANT) {
					swap(temp_arr[i][j], temp_arr[h][w]);
					swap(temp_fishes[k].h, temp_fishes[temp_arr[h][w]].h);
					swap(temp_fishes[k].w, temp_fishes[temp_arr[h][w]].w);
					break;
				}
			}
		}
	}

	int h = shark.h;
	int w = shark.w;
	int d = shark.dir;

	for (int b = 1; b <= 3; b++) {
		int i = h + ni[d] * b;
		int j = w + nj[d] * b;
		if (i < 0 || i>3 || j < 0 || j>3) break;
		if (temp_arr[i][j] != VACANT) {
			int idx = temp_arr[i][j];
			int nxt_arr[4][4];
			Node nxt_fishes[17];

			memcpy(nxt_fishes, temp_fishes, sizeof(Node) * 17);
			memcpy(nxt_arr, temp_arr, sizeof(int) * 4 * 4);

			nxt_arr[h][w] = VACANT;
			nxt_arr[i][j] = SHARK;
			Node nxt_shark = { i,j,nxt_fishes[idx].dir };
			nxt_fishes[idx].dir = VACANT;
			dfs(nxt_shark, nxt_fishes, nxt_arr, cost + idx);
		}
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	N = M = 4;
	int arr[4][4];
	Node fishes[17];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			fishes[arr[i][j]] = { i,j,0 };
			cin >> fishes[arr[i][j]].dir;
			fishes[arr[i][j]].dir--;
		}
	}

	int cost = arr[0][0];
	Node shark = { 0,0, fishes[cost].dir };
	arr[0][0] = SHARK;
	fishes[cost].dir = VACANT;

	dfs(shark, fishes, arr, cost);
	cout << myMax << "\n";

	return 0;
}


