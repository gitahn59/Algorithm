/*
boj_03830_�������� ��ٸ��� �ʴ´�(���̵� : �÷� 4)
Disjoint set
������� ������ ���̸� ���μ� ������ ���� 
������ ���� a, b �� ���� ���� ��ǥ ���ҿ��� ���̸� ���� ���

1.
merge �������� (a,b) �� ��ǥ ���Ұ� �ƴ� ���
��ǥ ���Ҹ� ã�� w�� ��ǥ ���Ұ��� ���� ���� ���踦 ����ؾ� ��

2.
��� ���� �������� dist�� ���� update �Ͽ� �ð� ����
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

int N, M;
ll pnt[100001];
ll dist[100001];

LL find(ll a) {
	if (a == pnt[a])
		return { a, 0 };
	LL rst = find(pnt[a]);
	pnt[a] = rst.first;
	dist[a] += rst.second;
	return { rst.first, dist[a] };
}

bool isSet(ll a, ll b) {
	a = find(a).first;
	b = find(b).first;
	return a == b;
}

void merge(ll a, ll b, ll w) {
	LL left = find(a);
	LL right = find(b);

	pnt[left.first] = right.first;
	dist[left.first] = right.second + w - left.second;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;

		for (int n = 1; n <= N; n++) {
			pnt[n] = n;
			dist[n] = 0;
		}

		char str[5];
		ll a, b, w;
		for (int m = 1; m <= M; m++) {
			cin >> str;
			if (str[0] == '!') {
				cin >> a >> b >> w;
				if (isSet(a, b)) continue;
				merge(a, b, w);
			}
			else {
				cin >> a >> b;
				if (isSet(a, b)) {
					cout << dist[a] - dist[b] << "\n";
				}
				else {
					cout << "UNKNOWN\n";
				}
			}
		}
	}

	return 0;
}

