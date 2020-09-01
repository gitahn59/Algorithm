/*
boj_11687_팩토리얼 0의 개수(난이도 : 골드4)
가장 끝의 0의 개수는 2, 5의 곱에 의해 결정됨
또한 2는 항상 5의 개수보다 많이 존재함(자명함)

따라서 5의 배수만 검사하면서 5의 개수가 차례대로
몇개가 누적되었는지 O(NlogN) 시간에 검사하면 됨
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

int M;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M;

	ll now = 1;
	int m = 0;
	while (1) {
		int cnt = 1;
		ll temp = now;
		while (temp % 5 == 0) {
			temp /= 5;
			cnt++;
		}
		m += cnt;
		if (m >= M) break;
		now += 1;
	}

	if (m == M) {
		cout << now * 5 << "\n";
	}
	else {
		cout << "-1\n";
	}

	return 0;
}


