/*
pro_67257_���� �ִ�ȭ(���̵� : level2)
����Ž��
���Ŀ� �켱������ �ο��ϰ�
�� �ݺ����� �켱������ �´� ���길 �����ϰ�
�������� �״�� �̵��Ͽ�
��� �����ڿ� ���� ������ ����
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

vector<ll> numbers;
vector<char> ops;

void preprocessing(string expression) {
	string num = "";

	for (char c : expression) {
		if (c == '+' || c == '-' || c == '*') {
			numbers.push_back(stoll(num.c_str()));
			ops.push_back(c);
			num = "";
		}
		else {
			num += c;
		}
	}
	numbers.push_back(stoi(num.c_str()));
}

ll cal(ll a, ll b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else return a * b;
}

long long solution(string expression) {
	long long answer = 0;
	preprocessing(expression);

	vvi order = { {0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0} };
	int weight[120];

	for (int i = 0; i < 6; i++) {
		weight['+'] = order[i][0];
		weight['-'] = order[i][1];
		weight['*'] = order[i][2];
		deque<ll> l, r, c;
		for (ll i : numbers) {
			r.push_back(i);
		}
		l.push_back(r.front());
		r.pop_front();

		string exp = "";
		for (char i : ops) {
			exp += i;
		}

		for (int w = 0; w < 3; w++) {
			string temp = "";
			for (char c : exp) {
				if (weight[c] == w) {
					ll rst = cal(l.back(), r.front(), c);
					l.pop_back();
					r.pop_front();
					l.push_back(rst);
				}
				else {
					temp += c;
					l.push_back(r.front());
					r.pop_front();
				}
			}
			while (!l.empty()) {
				r.push_back(l.front());
				l.pop_front();
			}
			l.push_back(r.front());
			r.pop_front();
			exp = temp;
		}
		answer = max(abs(l.back()), answer);
	}

	return answer;
}
