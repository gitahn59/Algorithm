/*
boj_5525_IOIOI(난이도 : 실버1)
KMP
손실함수 부분이 간단한 
KMP 알고리즘 문제

KMP 알고리즘
문자열 탐색을 O(N+M)시간에 전부 탐색하는 알고리즘
비교하는 문자열 내에 중복되는 부분이 있으면
그 부분을 건너띄고 다음 비교를 진행함

이에 대한 손실 값을 전부 미리 계산해둠
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

int N, M;
string str;
string P = "I";
int arr[1000001];
void make_sp() {
	for (int i = 3; i <= P.size(); i++) {
		arr[i] = i - 2;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> str;

	for (int n = 0; n < N; n++) {
		P += "OI";
	}
	make_sp();

	int i = 0, j = 0;
	int cnt = 0;
	for (; i < str.size();) {
		int base = i;
		for (; j < P.size(); j++, i++) {
			if (str[i] == P[j]) continue;
			else break;
		}
		if (j == P.size()) {
			cnt++;
		}
		i = i - j + 1 + arr[j];
		j = arr[j];
	}

	cout << cnt << "\n";

	return 0;
}
