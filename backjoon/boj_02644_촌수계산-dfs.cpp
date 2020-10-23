/*
boj_2644_�̼����(���̵� : �ǹ�2)
dfs
�θ� �Ѹ� �־����Ƿ� �̼� ���踦 �׷����� �𵨸�

1. �̼��� ����� �� ���߿� �� ���� ��Ʈ�� ����
2. DFS�� ���� ������ ������ ���̸� ���

���̴� ��Ʈ������ �Ÿ��� ��Ÿ��
���� �������� ���� ������ �� ����� ���̰� �̼��� ��
���� ���̰� ������ �ʾҴٸ� �̼��� ������� �����Ƿ�
-1 ���
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
int A, B;
int M;

vi arr[101];
int height[101];

void dfs(int now, int p, int h) {
	height[now] = h;
	for (int i : arr[now]) {
		if (i == p) continue;
		dfs(i, now, h + 1);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> A >> B;
	cin >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	dfs(A, -1, 0);
	if (height[B] == 0) {
		cout << "-1\n";
	}
	else {
		cout << height[B] << "\n";
	}

	return 0;
}
