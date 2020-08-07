/*
boj__(난이도 : )
동전 교환 문제
사면체의 각 크기가 배수관계가 아니므로
DP를 이용하여 풀어야 함
각 사면체에 대해 각각의 사면체를 1개씩 사용하는 경우에 대해
Bottom UP DP를 구성하면 됨
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
vi candidate;
vi tetra;
int cnt[300001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int temp = 0;
	int now = 1;
	while (1) {
		temp += now;
		if (temp <= N) candidate.push_back(temp);
		else break;
		now++;
	}

	temp = 0;
	for (int i : candidate) {
		temp += i;
		if (temp <= N) tetra.push_back(temp);
		else break;
	}

	cnt[0] = 1;
	for (int i : tetra) {
		for (int j = i; j <= N; j++) {
			if (cnt[j - i] == 0) continue;
			if (cnt[j]) cnt[j] = min(cnt[j], 1 + cnt[j - i]);
			else cnt[j] = 1 + cnt[j - i];
		}
	}

	cout << cnt[N] - 1 << "\n";

	return 0;
}

