/*
boj_16925_���ڿ� ����(���̵� : ���5)
���ڿ�
�ĺ� ���ڿ��� Ž���ϰ�
Ž���� �ĺ� ���ڿ��� ���� ���ڿ��� �������� 
���� �� �ִ��� Ȯ���ϴ� ����
�� �ĺ��� ���� �� ���̴� 4���� ������ �˻��غ��ƾ� ��

���� �ð����⵵��
��ü�ĺ� 4 * �� ���̴� 4 * 100 ����
1600���� Ȯ���� �ʿ���
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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

typedef vector<string> vs;

int N;
vs arr[101];
int cnt[101];
ii l[] = { {0,0},{0,1},{1,1},{1,0} };
ii r[] = { {1,1},{1,0},{0,0},{0,1} };
vs order;

bool isAvailable(string candidate, int n, int m) {
	for (int i = 0; i < 4; i++) {
		string a = arr[n][l[i].first] + arr[m][l[i].second];
		string b = arr[m][r[i].second] + arr[n][r[i].first];
		if (a == b && a == candidate)
			return true;
	}
	return false;
}

vs make_candidate(int n, int m) {
	vs candidate;
	for (int i = 0; i < 4; i++) {
		string a = arr[n][l[i].first] + arr[m][l[i].second];
		string b = arr[m][r[i].second] + arr[n][r[i].first];
		if (a == b)
			candidate.push_back(a);
	}
	return candidate;
}

string solution(vs candidate) {
	for (string s : candidate) {
		int ls = 2;
		int rs = N - ls;
		while (ls <= rs) {
			if (isAvailable(s, ls, rs)) {
				ls++;
				rs = N - ls;
			}
			else {
				break;
			}
		}
		if (ls > rs) {
			return s;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int M = ((N - 1) << 1);
	string s;
	for (int i = 0; i < M; i++) {
		cin >> s;
		arr[s.size()].push_back(s);
		order.push_back(s);
	}

	vs candidate = make_candidate(N - 1, 1);
	string result = solution(candidate);
	cout << result << "\n";
	for (string s : order) {
		int len = s.size();
		string sub = result.substr(0, len);
		if (sub == s) {
			if (arr[len][0] == arr[len][1]) {
				if (cnt[len] == 0) {
					cout << "P";
					cnt[len]++;
				}
				else {
					cout << "S";
				}
			}
			else {
				cout << "P";
			}
		}
		else {
			cout << "S";
		}
	}
	cout << "\n";

	return 0;
}