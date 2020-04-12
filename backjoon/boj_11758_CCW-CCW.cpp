/*
boj_11758_CCW(난이도 : 골드5)
기하 : CCW
외적 벡터 k가 향하는 방향에 따라 오른손 법칙에 의해 AB, AC의 위치가 정해짐
k가 양수이면 AB가 AC보다 오른쪽에 있으므로 반시계 방향
K가 0이면 AB, AC가 평행
k가 음수이면 AB가 AC보다 왼쪽에 있으므로 시계방향

외적 U x V = m1n2 - m2n1 ( U = (m1,m2) V = (n1, n2) )
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

ii A, B, C;
ii AB, AC;

int ccw(ii left, ii right) {
	int rst = left.first * right.second - left.second * right.first;
	if (rst == 0) return 0;
	else if (rst > 0) return 1;
	else return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;

	AB = { B.first - A.first, B.second - A.second };
	AC = { C.first - A.first, C.second - A.second };

	cout << ccw(AB, AC) << "\n";

	return 0;
}

