#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to find the minimum of three numbers
int min(int x, int y, int z)
{
	if (x <= y && x <= z)
		return x;
	if (y <= x && y <= z)
		return y;
	return z;
}

int editDistDP(char* str1, char* str2, int m, int n ,int wi , int wd , int ws)
{

	int dp[m + 1][n + 1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			// If first string is empty, only option is to
			// insert all characters of second string
			if (i == 0)
				dp[i][j] = j * wi; // Min. operations = j

			// If second string is empty, only option is to
			// remove all characters of second string
			else if (j == 0)
				dp[i][j] = i * wd; // Min. operations = i

			// If last characters are same, ignore last char
			// and recur for remaining string
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			// If the last character is different, consider
			// all possibilities and find the minimum
			else
				dp[i][j]
					= min(dp[i][j - 1] + wi, // Insert
							dp[i - 1][j] + wd, // Remove
							dp[i - 1][j - 1] + ws); // Replace
		}
	}

	return dp[m][n];
}


int main()
{
	char str1[] = "sunday";
	char str2[] = "saturday";

	int m = strlen(str1);
	int n = strlen(str2);
  int wi , wd , ws;

	printf("%d\n", editDistDP(str1, str2, m, n , wi , wd , ws));

	return 0;
}
