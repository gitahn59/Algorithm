/*
boj_14465_소가 길을 건너간 이유 5(난이도 : 실버2)
Sweeping
큐를 이용하여 K개의 신호등을 관리한다.
큐를 1칸씩 밀면서 고장난 신호등의 개수를 카운트한다.
이 때 고장난 신호등이 pop되면 cnt를 줄이고,
push 되면 cnt를 증가시킨다.
O(N)에 탐색을 완료할 수 있다.
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

int N, K, B;
bool sign[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K >> B;
	int num = 0;
	for (int b = 0; b < B; b++) {
		cin >> num;
		sign[num] = 1;
	}

	int cnt = 0;
	queue<bool> q;
	for (int i = 1; i <= K; i++) {
		if (sign[i]) cnt++;
		q.push(sign[i]);
	}

	int rst = cnt;
	for (int i = K + 1; i <= N; i++) {
		if (q.front()) cnt--;
		q.pop();
		if (sign[i]) cnt++;
		q.push(sign[i]);
		rst = min(rst, cnt);
	}

	cout << rst << "\n";
	return 0;
}


