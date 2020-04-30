/*
pro_Ʃ��(���̵� : level2)
���ڿ� �ڸ���
strtok :
���ϴ� ���ڿ��� �߶󳻴� �Լ�
ù ��° ���ڿ� NULL�� �����ϸ� �տ� 
����ߴ� ���ڿ��� �״�� ���

���� : 
char* p = strtok(str, "}");
while (p != NULL) {
	arr[++cnt] = p;
	p = strtok(NULL, "}");
}
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

char str[1000010];
int cnt;
char* arr[501];
bool visited[501][100001];
int M;
int myMax;

void solve(int now) {
	vi v;
	char* p = strtok(arr[now], "{,");
	while (p != NULL) {
		if ('0' <= p[0] && p[0] <= '9') {
			v.push_back(stoi(p));
			myMax = max(myMax, v.back());
		}
		p = strtok(NULL, "{,");
	}

	int size = v.size();
	for (int a : v) {
		visited[size][a] = 1;
	}
	M = max(M, size);
}

vector<int> solution(string s) {
	for (int n = 0; n < s.size(); n++) {
		str[n] = s[n];
	}
	char* p = strtok(str, "}");
	while (p != NULL) {
		arr[++cnt] = p;
		p = strtok(NULL, "}");
	}

	for (int c = 1; c <= cnt; c++) {
		solve(c);
	}

	vector<int> answer;
	for (int m = 1; m <= M; m++) {
		for (int n = 1; n <= myMax; n++) {
			if (visited[m][n] == 1 && visited[m - 1][n] == 0) {
				answer.push_back(n);
				break;
			}
		}
	}

	return answer;
}
