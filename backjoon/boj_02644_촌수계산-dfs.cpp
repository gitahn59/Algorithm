/*
boj_2644_촌수계산(난이도 : 실버2)
dfs
부모가 한명만 주어지므로 촌수 관계를 그래프로 모델링

1. 촌수를 계산할 두 점중에 한 점을 루트로 설정
2. DFS로 도달 가능한 노드들의 높이를 계산

높이는 루트까지의 거리를 나타냄
따라서 선택하지 않은 나머지 한 노드의 높이가 촌수가 됨
만약 높이가 계산되지 않았다면 촌수로 연결되지 않으므로
-1 출력
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
