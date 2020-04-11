/*
boj_11726_2xn 타일링 2(난이도 : 실버3)
dp
나머지 길이가 1, 2인 경우
2가지 부분 문제로 분해 가능
단, 나머지 길이가 2일 때 1가지 경우가 나머지 길이1일 때와
동일 하므로 이는 중복을 제거해줘야 함
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
int FIRST = -1;
int mem[1001];

int topdown(int n) {
	if (n < 1) return 0;
	if (n == 1) return 1;
	if (n == 2) return 3;

	int& ref = mem[n];
	if (ref != FIRST) return ref;
	return ref = (1 * topdown(n - 1) + 2 * topdown(n - 2)) % 10007;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	fill(mem + 1, mem + 1 + (N), FIRST);
	cout << topdown(N) << "\n";

	return 0;
}

