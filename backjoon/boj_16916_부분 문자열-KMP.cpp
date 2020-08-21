/*
boj_16916_부분 문자열(난이도 : 골드4)
KMP 알고리즘
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
int p[1000100];
char str[1000100];
char target[1000100];

void makep() {
	M = strlen(target);
	int j = 0;
	for (int i = 1; i < M; i++) {
		while (j > 0 && target[i] != target[j]) { // 다르면
			j = p[j - 1]; // j를 다음에 봐야할 j로 조정
		}
		if (target[i] == target[j]) { // 같으면
			j++; // 다음 j부터 보면 됨
			p[i] = j; // 다음에 볼 위치
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin.getline(str, 1000005);
	N = strlen(str);
	cin.getline(target, 1000005);
	M = strlen(target);
	makep();

	int j = 0;
	vi rst;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		while (j > 0 && str[i] != target[j]) { // 다르면
			j = p[j - 1]; // j를 다음에 봐야할 j로 조정
		}
		if (str[i] == target[j]) { // 같으면
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


