/*
pro_60060_���� �˻�(���̵� : level 4)
tri
tri�� �̿��� ���ϵ� ī�尡 ���Ե� ���ڿ��� �󵵼��� ���
�ð� ����
- �ߺ��� �ܾ�� �̸� ���� �� ���
- ���λ簡 ?�� �����ϴ� ���ڿ��� ����� �˻�
  (�պκп��� �ɷ����� ��ġ���� �ʴ� ���ڿ��� ���ܵǱ� ����)
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

typedef struct tri {
	tri* t[26];
	int cnt;

	tri() {
		for (int i = 0; i < 26; i++) {
			t[i] = nullptr;
		}
		cnt = 0;
	}

	~tri() {
		for (int i = 0; i < 26; i++) {
			if (t[i] = nullptr) continue;
			else free(t[i]);
		}
	}

	void insert(const char* str) {
		if (str[0] == '\0') {
			cnt++;
			return;
		}
		char now = str[0];

		if (t[now - 'a'] == nullptr) {
			t[now - 'a'] = new tri();
		}
		t[now - 'a']->insert(str + 1);
	}

	int find(const char* str) {
		if (str[0] == '\0') {
			return cnt;
		}
		char now = str[0];
		if (now == '?') {
			int sum = 0;
			for (int i = 0; i < 26; i++) {
				if (t[i] != nullptr) {
					sum += t[i]->find(str + 1);
				}
			}
			return sum;
		}

		if (t[now - 'a'] == nullptr) {
			return 0;
		}
		else {
			return t[now - 'a']->find(str + 1);
		}

	}
}Tri;

vector<int> solution(vector<string> words, vector<string> queries) {
	Tri* t = new Tri();
	Tri* rt = new Tri();
	for (string s : words) {
		t->insert(s.c_str());
		reverse(s.begin(), s.end());
		rt->insert(s.c_str());
	}

	set<string> ss;
	map<string, int> msi;
	vector<int> answer;
	for (string s : queries) {
		int cnt;
		if (ss.find(s) == ss.end()) {
			ss.insert(s);
			if (s[0] != '?') {
				cnt = t->find(s.c_str());
			}
			else {
				string temp = s;
				reverse(temp.begin(), temp.end());
				cnt = rt->find(temp.c_str());
			}
			msi[s] = cnt;
		}
		else {
			cnt = msi[s];
		}
		answer.push_back(cnt);
	}

	free(t);
	free(rt);
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution({ "frodo", "front", "frost", "frozen", "frame", "kakao" },
		{ "fro??", "????o", "fr???", "fro???", "pro?" });

	return 0;
}
