/*
boj_16570_앞뒤가 맞는 수열(난이도 : 골드1)
KMP 
앞에서부터 임의의 개수의 숫자를 제거할 때
접미사 배열과 접두사 배열의 공통 수열의 최대 길이를 파악하는 문제

앞에서부터자르는 조건을 뒤집어서 자르는 것으로 바꾸면
이는 KMP 문제로 치환할 수 있음
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

int M;
int target[10000001];
int p[10000001];
void makep() {
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

	cin >> M;
	for (int m = M - 1; m >= 0; m--) {
		cin >> target[m];
	}
	makep();
	sort(p, p + M);
	int myMax = p[M - 1];
	int cnt = 1;
	if (myMax == 0) {
		cout << -1 << "\n";
		return 0;
	}

	for (int m = M - 2; m >= 0; m--) {
		if (myMax == p[m]) {
			cnt++;
		}
		else break;
	}

	cout << myMax << " " << cnt << "\n";

	return 0;
}


