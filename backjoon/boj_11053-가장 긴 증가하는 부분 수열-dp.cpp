/*
boj_11053_가장 긴 증가하는 부분 수열(난이도 : 실버2)
bottomup dp
문제의 크기가 작아 dp로 해결 가능한 문제
문제의 크기가 커지면 segment tree 필요
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
int arr[1001];
int mem[1001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	mem[1] = 1;
	for (int n = 2; n <= N; n++) {
		mem[n] = 1;
		for (int i = 1; i <= n - 1; i++) {
			if (arr[n] > arr[i]) {
				mem[n] = max(mem[n], mem[i] + 1);
			}
		}
	}

	int myMax = 1;
	for (int n = 1; n <= N; n++) {
		myMax = max(myMax, mem[n]);
	}

	cout << myMax << "\n";
	return 0;
}

