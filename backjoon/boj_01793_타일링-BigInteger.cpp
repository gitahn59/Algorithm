/*
boj_1793_타일링(난이도 : 실버1)
dp, 큰수출력
boj_11727 과 똑같은 문제지만 나머지가 아닌 수 그대로를 출력해야함
주의) n=0일 때도 1개로 취급함
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
string mem[251];

string add(string a, string b) {
	int sum = 0;
	string rst;
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		rst.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(rst.begin(), rst.end());
	return rst;
}

string topdown(int n) {
	string& ref = mem[n];
	if (ref != "F") return ref;
	string left = topdown(n - 1);
	string right = topdown(n - 2);
	right = add(right, right);
	return ref = add(left, right);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	fill(mem + 1, mem + 250 + 1, "F");
	mem[0] = "1";
	mem[1] = "1";
	mem[2] = "3";
	while (scanf("%d", &N) != EOF) {
		cout << topdown(N) << "\n";
	}

	return 0;
}

