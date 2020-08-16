/*
boj_133334_ö��(���̵� : ���2)
Sweeping
1. ���� ������ �������� ����
2. ���� ������ �������� set���� ������ ������ ���ϴ� 
������ ���� ī����
���� ������ ���ԵǴ� ������ ������ �� ������ ������ �ǹ���
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

int N, D;
ii arr[100000];
bool myCmp(ii a, ii b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n].first >> arr[n].second;
		if (arr[n].first > arr[n].second) swap(arr[n].first, arr[n].second);
	}
	sort(arr, arr + N, myCmp);
	cin >> D;

	multiset<int> candidate;
	int rst = 0;
	for (int n = 0; n < N; n++) {
		candidate.insert(arr[n].first);
		int target = arr[n].second - D;
		auto end = candidate.lower_bound(target);
		for (auto it = candidate.begin(); it != end;) {
			it = candidate.erase(it);
		}
		rst = max(rst, int(candidate.size()));
	}

	cout << rst << "\n";

	return 0;
}


