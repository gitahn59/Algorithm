/*
pro_17685_�ڵ��ϼ�(���̵� : level 4)
tri
tri�� �̿��ؼ� ��θ� ������ ���ڿ��� ������ ����ϰ�
��θ� ���� ���ڿ��� 1���ۿ� ���ٸ�
�� �̻� �Է��� �ʿ䰡 �����Ƿ� �� ��������
����-1�� �����ϸ� ��
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
	tri* word[26];
	int cnt;
	tri() {
		for (int i = 0; i < 26; i++) word[i] = nullptr;
		cnt = 0;
	}

	~tri() {
		for (int i = 0; i < 26; i++)
			if (word[i] != nullptr) {
				delete word[i];
			}
	}

	void insert(const char* str) {
		if (str[0] == '\0') {
			cnt++;
			return;
		}

		int i = str[0] - 'a';
		if (word[i] == nullptr) {
			word[i] = new tri();
		}
		cnt++;
		word[i]->insert(str + 1);
	}

	int find(const char* str, int depth) {
		if (str[0] == '\0') {
			return depth - 1;
		}
		if (cnt == 1) {
			return depth - 1;
		}
		int i = str[0] - 'a';
		return word[i]->find(str + 1, depth + 1);
	}

}Tri;

int N;
Tri t;

int solution(vector<string> words) {
	N = words.size();
	for (int n = 0; n < N; n++) {
		t.insert(words[n].c_str());
	}

	int sum = 0;
	for (int n = 0; n < N; n++) {
		sum += t.find(words[n].c_str(), 1);
	}

	int answer = sum;
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution({ "go", "gone", "guild" });

	return 0;
}