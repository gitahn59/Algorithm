/*
boj_1912_������(���̵� : �ǹ�1)
�� ���Ҹ��� ���簪�� ���簪+�������� ���ؼ�
1. ���簪�� �� ũ�� ���� ���� ������
2. ���簪+�������̸� �״�� ������
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
typedef pair<int, ii> iii;
typedef set<int> si;

int N;
int arr[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	int now = arr[1];
	int myMax = now;
	for (int n = 2; n <= N; n++) {
		int next = now + arr[n];
		if (next < arr[n]) {
			next = arr[n];
		}
		now = next;
		myMax = max(myMax, next);
	}

	cout << myMax << "\n";

	return 0;
}
