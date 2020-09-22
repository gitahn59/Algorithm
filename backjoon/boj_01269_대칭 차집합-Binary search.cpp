/*
boj_1269_대칭 차집합(난이도 : 실버3)
Binary search
이진탐색을 통해 후보 탐색
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

int N, M;
vi arr, brr;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int num;
	for (int n = 0; n < N; n++) {
		cin >> num;
		arr.push_back(num);
	}
	for (int m = 0; m < M; m++) {
		cin >> num;
		brr.push_back(num);
	}

	sort(arr.begin(), arr.end());
	sort(brr.begin(), brr.end());

	vi a, b;
	for (int i : arr) {
		auto it = lower_bound(brr.begin(), brr.end(), i);
		if (it == brr.end()) {
			a.push_back(i);
		}
		else if (*it != i) {
			a.push_back(i);
		}
	}

	for (int j : brr) {
		auto it = lower_bound(arr.begin(), arr.end(), j);
		if (it == arr.end()) {
			b.push_back(j);
		}
		else if (*it != j) {
			b.push_back(j);
		}
	}

	cout << a.size() + b.size() << "\n";

	return 0;
}


