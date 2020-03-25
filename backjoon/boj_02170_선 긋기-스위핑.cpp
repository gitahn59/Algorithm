/*
boj_02170_�� �߱�(���̵� : ���5)
������ �˰��� Ȱ�� ����
������ ���� O(n)���� ���ϵ��� ��
����) first�� ���� ���ĵ� ���̹Ƿ� second�� ������ ������ �˻��ؾ� ��
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
ii arr[1000001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n].first >> arr[n].second;
		if (arr[n].first > arr[n].second)
			swap(arr[n].first, arr[n].second);
	}

	sort(arr + 1, arr + 1 + N);

	int sum = 0;
	ii now = arr[1];
	for (int n = 2; n <= N; n++) {
		if (now.second >= arr[n].first) {
			if (arr[n].second > now.second) {
				now.second = arr[n].second;
			}
		}
		else {
			sum += now.second - now.first;
			now = arr[n];
		}
	}
	sum += now.second - now.first;
	cout << sum << "\n";

	return 0;
}