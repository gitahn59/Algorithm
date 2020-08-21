/*
boj_16172_나는 친구가 적다(Large) (난이도 : 골드4)
기본적인 KMP 탐색 문제
일치하는 경우에도 마찬가지로
j = p[j-1] 해주면 됨
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
string S, K;
int p[200001];
void makep() {
	int j = 0;
	for (int m = 1; m < M; m++) {
		while (j > 0 && K[j] != K[m]) {
			j = p[j - 1];
		}
		if (K[j] == K[m]) {
			j++;
			p[m] = j;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> S >> K;

	string src = "";
	for (char c : S) {
		if (c >= '0' && c <= '9') continue;
		else src += c;
	}

	N = src.size();
	M = K.size();
	makep();

	int j = 0;
	int flag = 0;
	for (int n = 0; n < N; n++) {
		while (j > 0 && K[j] != src[n]) {
			j = p[j - 1];
		}
		if (K[j] == src[n]) {
			j++;
			if (j == M) {
				flag = 1;
				break;
			}
		}
	}

	cout << flag << "\n";

	return 0;
}


