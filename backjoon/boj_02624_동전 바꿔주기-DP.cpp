/*
boj_2624_���� �ٲ��ֱ�(���̵� : ���5)
DP
�⺻���� bottom up dp ����
��, ������ ������ ������ �����Ƿ�
�̿� ���� ������ ����ؾ� ��
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

int dist[101][10001];
ii coin[101];
int T, K;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T >> K;
	for (int k = 1; k <= K; k++) {
		cin >> coin[k].first >> coin[k].second;
	}

	dist[0][0] = 1;
	for (int k = 1; k <= K; k++) {
		for (int i = coin[k].first; i <= T; i++) {
			int pre = i - coin[k].first;
			if (dist[k - 1][pre]) {
				for (int j = 1; j <= coin[k].second; j++) {
					int cost = pre + j * coin[k].first;
					if (cost <= T) dist[k][cost] += dist[k - 1][pre];
					else break;
				}
			}
		}
		for (int i = 0; i <= T; i++) {
			dist[k][i] += dist[k - 1][i];
		}
	}

	cout << dist[K][T] << "\n";
	return 0;
}


