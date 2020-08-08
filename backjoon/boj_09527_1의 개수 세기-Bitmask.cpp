/*
boj_09527_1의 개수 세기(난이도 : 골드2)
최대 비트의 자리수에 따라 나머지 비트의 개수로 가질수 있는
1의 개수가 달라짐
전처리를 하고
최대 자리수의 비트에 따라 수를 분리하여
분리된 수에 따라 1비트의 개수 카운팅

주의 ) 비트 연산시 long long의 범위라면
연산의 대상이 되는 숫자 역시 ll형을 사용해야
오버플로우를 방지 할 수 있음
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

ll dist[56];
ll acc[56];

void preprocessing() {
	dist[0] = 1;
	for (int i = 1; i < 56; i++) {
		ll sum = 0;
		sum += ((ll)1 << i);
		for (int j = 0; j < i; j++) {
			sum += dist[j];
		}
		dist[i] = sum;
	}

	acc[0] = 1;
	for (int i = 1; i < 56; i++) {
		acc[i] = acc[i - 1] + dist[i];
	}
}

int myidx = 0;
void binSearch(ll num, int a, int b) {
	if (a > b) return;
	int mid = (a + b) >> 1;
	ll shift = ((ll)1 << mid);
	if (num >= shift) {
		myidx = max(myidx, mid);
		binSearch(num, mid + 1, b);
	}
	else {
		binSearch(num, a, mid - 1);
	}
}

ll getCnt(ll num) {
	if (num <= 0) return 0;
	ll sum = 0;
	int idx = 0;
	myidx = 0;
	binSearch(num, 0, 56);
	idx = myidx;
	ll left = ((ll)1 << idx);
	ll cnt = num - left + 1;
	sum += cnt;
	if (idx >= 1)
		sum += acc[idx - 1];
	sum += getCnt(num - left);
	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	preprocessing();
	ll A, B;
	cin >> A >> B;
	ll left = getCnt(B);
	ll right = getCnt(A - 1);
	cout << left - right << "\n";

	return 0;
}
