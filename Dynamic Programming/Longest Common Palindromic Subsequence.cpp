//https://leetcode.com/problems/longest-palindromic-subsequence/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

using namespace std;

#define MaxLen 1000
int dp[MaxLen + 1][MaxLen + 1];

int longestPalindromeSubseq(string s)
{
    string s2 = s;
    reverse(s.begin(), s.end());

    int len = s.size();
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int ans = dp[len][len];
    //cout << ans << endl;

    return ans;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	string str;
	cin >> str;
	
	cout << longestPalindromeSubseq(str) << endl;

	return 0;
}