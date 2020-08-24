/*
boj_16900_이름 정하기(난이도 : 골드1)
KMP 알고리즘
특정 단어를 N번 포함하는 최소길이의 문자열을 생성해야 하는 문제
특정 단어에 반복되는 부분이 있다면 이를 고려해서 문자열을 생성해야함

1. 따라서 중복된 최대 길이를 파악하기 위해 KMP 알고리즘의 접미사 함수를 생성
2. 결과 = M + (M-중복길이) * (N-1)  : M은 단어의 길이

O(M)의 시간복잡도로 문제를 해결할 수 있음
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

int N, M;
int p[500001];
string src;

void makep(string& target) {
	M = target.size();
	for (int m = 1, j = 0; m < M; m++) {
		while (j > 0 && target[m] != target[j]) {
			j = p[j - 1];
		}
		if (target[m] == target[j]) {
			j++;
			p[m] = j;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> src >> N;
	makep(src);

	int hover = p[M - 1];
	int add = M - hover;
	ll rst = (ll)(N - 1) * add + M;
	cout << rst << "\n";

	return 0;
}


