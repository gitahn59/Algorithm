/*
boj_2293_동전(난이도 : 실버1)
bottom dp
여러가지 동전을 이용해 경우의 수를 구하는 문제
임의의 합에 대해 사용된 동전의 종류와 갯수는 상관하지 않고
있는지의 여부만 고려하는 문제

ex) 1,2,3원이 있을때
3원을 고려할 때 1,2 원이 각각 몇개 쓰였는지는 신경쓰지 않고
그 합의 경우의 수만 생각하면 됨
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

int N, K;
int arr[101];
ll mem[10001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int n = 1; n <= N; n++)
		cin >> arr[n];

	mem[0] = 1;
	for (int n = 1; n <= N; n++) {
		for (int i = arr[n]; i <= K; i++) {
			mem[i] += mem[i - arr[n]];
		}
	}

	cout << mem[K] << "\n";

	return 0;
}