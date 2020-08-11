/*
boj_16194_카드 구매하기 2(난이도 : 실버1)
Coin
boj_11052의 반대 문제
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

int N;
int arr[1001];
int dist[1001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	dist[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			int pre = j - i;
			if (dist[pre]) {
				if (dist[j]) dist[j] = min(dist[j], dist[pre] + arr[i]);
				else dist[j] = dist[pre] + arr[i];
			}
		}
	}

	cout << dist[N] - 1 << "\n";

	return 0;
}

