/*
boj_1865_��Ȧ(���̵� : ���4)
��������
�ִܰŸ��� �ƴ϶� ��������Ŭ�� ���翩�ΰ� �ش��� ����
�׷����� ���Ῡ�ε� ���������
��� ������ �����ϵ� ��������Ŭ�� �����ϸ� ��
���� �Ÿ� dist�� ������ ū ������ �ʱ�ȭ�ϰ�
�������� �˰����� ���� ���� ����Ŭ�� Ȯ���ϸ� ��
�̶� INF�� �������� �ʰ� ��� ����Ͽ�
����Ŭ�� �߻��ϴ��� Ȯ���ؾ� ��
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

typedef struct node {
	int s, e, t;
}Node;
typedef vector<Node> vn;

int TC;
int N, M, W;
int INF = 10000 * 10000;

bool bf(vn& adj) {
	int dist[501];
	for (int n = 1; n <= N; n++) {
		dist[n] = INF;
	}

	for (int n = 1; n <= N; n++) {
		for (Node now : adj) {
			int cost = dist[now.s] + now.t;
			if (dist[now.e] > cost) {
				dist[now.e] = cost;
			}
		}
	}

	int nxt[501];
	for (int n = 1; n <= N; n++) {
		nxt[n] = dist[n];
	}
	for (Node now : adj) {
		int cost = nxt[now.s] + now.t;
		if (nxt[now.e] > cost) {
			nxt[now.e] = cost;
			return true;
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N >> M >> W;
		vn adj;
		int s, e, t;
		for (int m = 0; m < M; m++) {
			cin >> s >> e >> t;
			adj.push_back({ s, e, t });
			adj.push_back({ e, s, t });
		}
		for (int w = 0; w < W; w++) {
			cin >> s >> e >> t;
			adj.push_back({ s, e, -t });
		}

		if (bf(adj)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}

