//https://leetcode.com/problems/longest-common-subsequence/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

using namespace std;

#define MaxLen 1000
int dp[MaxLen + 1][MaxLen + 1];

int longestCommonSubsequence(string text1, string text2)
{
    int len1 = text1.size();
    int len2 = text2.size();

    for (int i = 0; i <= len1; i++)
    {
        for (int j = 0; j <= len2; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int len = dp[len1][len2];
    //cout << len << endl;

    return len;
}

int main()
{
    //freopen("input.txt", "r", stdin);

    string str1, str2;
    cin >> str1 >> str2;

    cout << longestCommonSubsequence(str1, str2) << endl;

    return 0;
}