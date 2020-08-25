/*
boj_1893_시저 암호(난이도 : 골드1)
KMP
문자열에서 타켓 문자가 단 1번 존재하는 경우를 찾는 문제
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

int N, K, M, S;
int p[50001];
string A, target, src;
int id[128];
int value[128];

void makep() {
	for (int m = 1, j = 0; m < M; m++) {
		while (j > 0 && target[j] != target[m]) {
			j = p[j - 1];
		}
		if (target[j] == target[m]) {
			j++;
			p[m] = j;
		}
	}
}

bool isSame(int t, int s, int shift) {
	target[(t + shift) % K];
	return value[(id[target[t]] + shift) % K] == src[s];
}

bool kmp(int shift) {
	int cnt = 0;
	for (int m = 0, j = 0; m < S; m++) {
		while (j > 0 && isSame(j, m, shift) == 0) {
			j = p[j - 1];
		}
		if (isSame(j, m, shift)) {
			j++;
			if (j == M) {
				j = p[M - 1];
				cnt++;
				if (cnt > 1) return 0;
			}
		}
	}
	if (cnt == 1) return 1;
	else return 0;
}

vi findShiftValue() {
	cin >> A >> target >> src;
	makep();
	K = A.size();
	M = target.size();
	S = src.size();
	for (int k = 0; k < K; k++) {
		id[A[k]] = k;
		value[k] = A[k];
	}

	vi rst;
	for (int k = 0; k < K; k++) {
		if (kmp(k)) {
			rst.push_back(k);
		}
	}
	sort(rst.begin(), rst.end());
	return rst;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		vi rst = findShiftValue();
		if (rst.size() == 0) cout << "no solution\n";
		else if (rst.size() == 1) cout << "unique: " << rst[0] << "\n";
		else {
			cout << "ambiguous: ";
			for (int i : rst) {
				cout << i << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}


