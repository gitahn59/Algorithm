/*
boj_2056_�۾�(���̵� : ���4)
��������
�������� �������� �� ��尡 ���� �� �ִ� �ִ� �ð��� ����ؾ� ��
���� indegree�� 0�� �� �� �� �ƴ϶� update ��������
�ð� ���� ������־�� ��
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

int N;
int arr[10001];
int cost[10001];
vi adj[10001];
int cnt[10001];
ii costMax[10001];

queue<ii> qi;

int topologicalSort() {
	ii myMax = { 1, cost[1] };
	while (!qi.empty()) {
		int qsize = qi.size();
		for (int i = 1; i <= qsize; i++) {
			ii now = qi.front();
			qi.pop();
			for (int child : adj[now.first]) {
				cnt[child]--;
				if (costMax[child].second < cost[child] + now.second) {
					costMax[child] = { child, cost[child] + now.second };
				}
				if (cnt[child] == 0) {
					qi.push(costMax[child]);
				}
			}

			if (myMax.second < now.second) {
				myMax = now;
			}
		}
	}
	return myMax.second;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int pre;
	for (int n = 1; n <= N; n++) {
		cin >> cost[n];
		cin >> cnt[n];
		if (cnt[n] == 0) qi.push({ n,cost[n] });
		for (int c = 1; c <= cnt[n]; c++) {
			cin >> pre;
			adj[pre].push_back(n);
		}
	}

	cout << topologicalSort() << "\n";

	return 0;
}

