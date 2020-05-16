/*
boj_1484_다이어트(난이도 : 골드3)
Binary Search
후보를 미리 생성하고
조건에 맞는 후보를 이진탐색
후보의 갯수가 크지 않으므로
NlogN풀이로 해결 가능
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
typedef set<int> si;
typedef vector<string> vs;

int G;
vll candidate;
vll rst;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> G;

	candidate.push_back(1);
	ll now = 1;
	while (true) {
		ll next = now * now;
		if (next - candidate.back() <= G) {
			candidate.push_back(next);
		}
		else {
			break;
		}
		now++;
	}

	for (int i = 0; i < candidate.size(); i++) {
		ll target = candidate[i] + G;
		if (binary_search(candidate.begin(), candidate.end(), target)) {
			rst.push_back(sqrt(target));
		}
	}

	sort(rst.begin(), rst.end());
	if (rst.size() == 0) cout << -1 << "\n";
	else {
		auto end = unique(rst.begin(), rst.end());
		for (auto it = rst.begin(); it != end; it++) {
			cout << *it << "\n";
		}
	}
}

