/*
boj_11047_���� 0(���̵� : �ǹ�1)
���� ����
�� ������ ��������ӿ� ���� Greedy ������ ����
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

int N, K;
int arr[10];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}

	reverse(arr, arr + N);

	int cnt = 0;
	for (int n = 0; n < N; n++) {
		if (K >= arr[n]) {
			int num = K / arr[n];
			cnt += num;
			K = K - num * arr[n];
		}
	}

	cout << cnt << "\n";

	return 0;
}
