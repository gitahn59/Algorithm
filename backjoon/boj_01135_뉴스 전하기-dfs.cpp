/*
boj_1135_���� ���ϱ�(���̵� : �÷�5)
dfs
dfs�� ���� Ʈ���� Ž���ϸ鼭
�ڽ� ������ �ɸ��ð��� ����Ͽ�
�ڽ��� �ɸ��ð��� ���� �������� ����

�ڽĳ����� �ɸ��ð��� ���� ������������ �����ϰ�
�� ��带 ������������ ���޽ð��� 1�� ��������
(n��° �ڽ��� Ž���Ϸ��� �̸� n-1��°���� �ڽĳ�尡 Ž���Ǿ����)
�����ְ� �������� �ִ� �ð��� ���
int cnt = 0;
while (!q.empty()) {
	ii top = q.top();
	q.pop();
	t = max(t, cnt + top.first);
	cnt++;
}
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

int N;

vi adj[50];
int dist[50];

int dfs(int now) {
	if (adj[now].size() == 0) return dist[now] = 1;
	int t = 0;

	priority_queue<ii> q;
	for (int i : adj[now]) {
		q.push({ dfs(i),i });
	}

	int cnt = 0;
	while (!q.empty()) {
		ii top = q.top();
		q.pop();
		t = max(t, cnt + top.first);
		cnt++;
	}

	return dist[now] = t + 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int p;
	cin >> p;

	for (int i = 1; i < N; i++) {
		cin >> p;
		adj[p].push_back(i);
	}

	cout << dfs(0) - 1 << "\n";
	return 0;
}


