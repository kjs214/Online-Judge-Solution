#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> getPi(string p)
{
	int m = (int)p.size(), j = 0; vector<int> pi(m, 0);
	for (int i = 1; i < m; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}

int solve(string s, string p)
{
	vector<int> ans, pi = getPi(p);
	int n = (int)s.size(), m = (int)p.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];
		if (s[i] == p[j])
		{
			if (j == m - 1)
			{
				ans.push_back(i - m + 1);
				j = 0;
			}
			else
			{
				j++;
			}
		}
	}
	return ans.size();
}


int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	cout << solve(a, b) << endl;
	return 0;
}