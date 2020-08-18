/*
boj_1202_���� ����(���̵� : ���2)
Greedy
��ġ DESC, ���� DESC ������ �����ϰ�,
upper bound�� ������ ������ ���� ���� ���� Ž��
������ �߰�, ������ ����
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

int N, K;
ii item[300001];
int bag[300001];

bool myCmp(ii a, ii b) {
	if (a.second == b.second) return a.first > b.first;
	else return a.second > b.second;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	int m, v;
	for (int n = 1; n <= N; n++) {
		cin >> m >> v;
		item[n] = { m,v };
	}
	sort(item + 1, item + 1 + N, myCmp);

	int c;
	multiset<int> set;
	for (int k = 1; k <= K; k++) {
		cin >> bag[k];
		set.insert(bag[k]);
	}

	ll sum = 0;
	for (int n = 1; set.size() && n <= N; n++) {
		auto it = set.lower_bound(item[n].first);
		if (it != set.end()) {
			set.erase(it);
			sum += item[n].second;
		}
	}

	cout << sum << "\n";

	return 0;
}


