#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;

int getMaxGold(int gold[][MAX], int m, int n)
{
	int goldTable[n+2][m+2];
	memset(goldTable, 0, sizeof(goldTable));
	for(int i=1;i<m+1;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        goldTable[i][j]=gold[i-1][j];
	    }
	}
    for (int j=0; j<n; j++)
	{
		for (int i=1; i<m+1; i++)
		{
			
			int right = goldTable[i][j-1] ;
			int right_up = goldTable[i-1][j-1] ;
			int right_down = goldTable[i+1][j-1] ;

			// Max gold collected from taking either of the
			// above 3 paths
			goldTable[i][j] = goldTable[i][j] +
							max(right, max(right_up, right_down));
													;
		}
	}

	int res = goldTable[1][n-1];
	for (int i=2; i<m+1; i++)
		res = max(res, goldTable[i][n-1]);
	return res;
}

// Driver Code
int main()
{
	int gold[MAX][MAX]= {{10, 33, 13, 15},
                  {22, 21, 4, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};
	int m = 4, n = 4;
	cout << getMaxGold(gold, m, n);
	return 0;
}
