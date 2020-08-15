/*
boj_1689_��ġ�� ����(���̵� : ���4)
Greedy
�����ϴ� ���������� 1�� ����
������ ���������� 1�� ����

������ ������ �����ϰ� ����
������ �������� �����ϴ� ������ �����
O(N)�ð��� �˻��� �� �ִ�.
�� ������ ���а� ���� �����ϴ� ������ ����
���� ��츦 �� ����ؾ� �Ѵ�.

�� ������ ��� �ܼ��� �ִ��� ã���� �ǹǷ�
������ ������ ���� ���ָ� �ȴ�.
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

int N;
ii arr[2000000];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int M = N << 1;
	int a, b;
	for (int m = 0; m < M; m += 2) {
		cin >> a >> b;
		arr[m] = { a,1 };
		arr[m + 1] = { b,-1 };
	}

	sort(arr, arr + M);
	int rst = 0;
	int now = 0;
	for (int m = 0; m < M; m++) {
		now += arr[m].second;
		rst = max(rst, now);
	}
	cout << rst << "\n";

	return 0;
}


