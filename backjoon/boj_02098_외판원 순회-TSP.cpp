/*
boj_2098_���ǿ� ��ȸ(���̵� : ���1)
TSP
���ǿ� ��ȸ �˰���, 
1. �������� ������� �ִ� ��δ� �� 1���� ������
2. ��� ������ ���� ���� �Ÿ�, ������ �Ÿ� 2���� �������Ƿ�
	� ������ �����ϴ� �������
3. ����Ž������ Ž������
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
int arr[16][16];
int dist[16][1 << 16];
int INF = 50000000;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	int end = (1 << N) - 1;
	for (int n = 0; n < N; n++) {
		for (int i = 0; i <= end; i++) {
			dist[n][i] = INF;
		}
	}

	// base
	for (int n = 1; n < N; n++) {
		if (arr[0][n] != 0)
			dist[n][1 << n] = arr[0][n];
	}

	for (int i = 1; i <= end; i++) { // 2^N
		for (int n = 0; n < N; n++) { // N
			if (dist[n][i] == INF) continue;
			for (int m = 0; m < N; m++) { // N 
				if (arr[n][m] == 0) continue;
				if (i & (1 << m)) continue;
				int state = i | (1 << m);
				if (dist[m][state] > dist[n][i] + arr[n][m]) {
					dist[m][state] = dist[n][i] + arr[n][m];
				}
			}
		}
	}

	cout << dist[0][(1 << N) - 1] << "\n";

	return 0;
}

