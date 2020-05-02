/*
pro_60061_��հ� �� ��ġ(���̵� : level 3)
�ùķ��̼�
������ ũ�Ⱑ �۾� ����Ž������ �� ���� �˻�
** ��հ� ���� ���� ��ġ�ǰ�, ��ġ, ���� ���� �˻� ����
** ���� ���־�� ��
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
#include <tuple>

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

// a : 0��� 1�� //// b : 0���� 1��ġ
typedef struct node {
	int x, y, a, b;
}Node;

int N, M;
bool arr[102][102][2];
Node tasks[1001];

int pillar = 0;
int dam = 1;
int uninstall = 0;
int install = 1;

bool can() {
	for (int n = 0; n <= N; n++) {
		for (int i = 0; i <= N; i++) {
			if (arr[n][i][pillar] == 1) {
				if (i == 0) continue;
				else if (arr[n][i - 1][pillar]) continue;
				else if (arr[n][i][dam]) continue;
				else if (n > 0 && arr[n - 1][i][dam]) continue;
				else return false;
			}
		}
	}

	for (int n = 0; n <= N; n++) {
		for (int i = 0; i <= N; i++) {
			if (arr[n][i][dam] == 1) {
				if (arr[n][i - 1][pillar]) continue; // ���ʿ� ���
				else if (n + 1 <= N && arr[n + 1][i - 1][pillar]) continue; // �����ʿ� ���
				else if (n > 0 && n < N && arr[n - 1][i][dam] && arr[n + 1][i][dam]) continue;
				else return false;
			}
		}
	}
	return true;
}

void solve() {
	for (int m = 1; m <= M; m++) {
		Node now = tasks[m];
		if (now.b == uninstall) {
			arr[now.x][now.y][now.a] = 0;
			if (!can()) {
				arr[now.x][now.y][now.a] = 1;
			}
		}
		else if (now.b == install) {
			arr[now.x][now.y][now.a] = 1;
			if (!can()) {
				arr[now.x][now.y][now.a] = 0;
			}
		}
	}
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	N = n;
	M = build_frame.size();

	for (int m = 1; m <= M; m++) {
		tasks[m] = { build_frame[m - 1][0],build_frame[m - 1][1],build_frame[m - 1][2],build_frame[m - 1][3] };
	}

	solve();

	vector<vector<int>> answer;
	for (int n = 0; n <= N; n++) {
		for (int i = 0; i <= N; i++) {
			if (arr[n][i][pillar]) {
				answer.push_back({ n,i,pillar });
			}
			if (arr[n][i][dam]) {
				answer.push_back({ n,i,dam });
			}
		}
	}

	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution(5, { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1} });

	return 0;
}
