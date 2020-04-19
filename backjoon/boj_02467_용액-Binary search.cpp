/*
boj_2467_���(���̵� : ���5)
lower bound
lower bound�� -arr[n]�� value�� �Ͽ� ���� ����� ���� ã��
��, lower bound �̹Ƿ� Ž���� �ε������� 1 ���� �ε����� ����
�ĺ��� �� �� ������ ����ؾ� ��
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
int arr[100010];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	int myMin = abs(arr[1] + arr[2]);
	int a = arr[1];
	int b = arr[2];
	for (int n = 1; n < N; n++) {
		auto it = lower_bound(arr + n + 1, arr + N + 1, -arr[n]);
		int temp;
		int idx = it - arr;
		if (idx > N) {
			temp = abs(arr[N] + arr[n]);
			if (temp < myMin) {
				myMin = temp;
				a = arr[n];
				b = arr[N];
			}
		}
		else {
			temp = abs(arr[n] + *it);
			if (temp < myMin) {
				myMin = temp;
				a = arr[n];
				b = *it;
			}
			if (idx - 1 != n) {
				temp = abs(arr[n] + *(it - 1));
				if (temp < myMin) {
					myMin = temp;
					a = arr[n];
					b = *(it - 1);
				}
			}
		}
	}

	cout << a << " " << b << "\n";

	return 0;
}



