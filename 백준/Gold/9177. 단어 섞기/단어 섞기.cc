#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string a, b, res;
bool find_flag;
int aLen, bLen, resLen;

bool test() {
	vector<int>alp(27, 0);
	for (int i = 0; i < aLen; i++)
		alp[a[i] - 'a']++;
	for (int i = 0; i < bLen; i++)
		alp[b[i] - 'a']++;
	for (int i = 0; i < resLen; i++)
		alp[res[i] - 'a']--;
	bool flag = false;
	for (int i = 0; i < 26; i++) {
		if (alp[i] != 0)
			flag = true;
	}
	if (flag)
		return false;
	else
		return true;
}

void dfs(int a_idx, int b_idx, int len) {
	if (find_flag)
		return;
	if (len == resLen) {
		find_flag = true;
		return;
	}
	if (a[a_idx] == res[len])
		dfs(a_idx + 1, b_idx, len + 1);
	if (b[b_idx] == res[len])
		dfs(a_idx, b_idx + 1, len + 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> res;
		find_flag = false;
		aLen = a.length(); bLen = b.length();
		resLen = res.length();
		cout << "Data set " << i << ": ";
		if (test())
			dfs(0, 0, 0);
		if (find_flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}