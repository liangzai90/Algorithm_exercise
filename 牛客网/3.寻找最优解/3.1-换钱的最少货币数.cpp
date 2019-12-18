/*

链接：https://www.nowcoder.com/questionTerminal/4e05294fc5aa4d4fa8eacef2e606e5a8?f=discussion
来源：牛客网


这道题可用动态规划的方法求解。动态规划的实质就是在计算过程中，根据动态规划表计算下一个目标值，并更新动态规划表。本题中，可以构造动态规划表dp[i][j]:
i:代表可以使用的货币种类为arr[0],arr[1],...,arr[i]
j:代表需要兑换的面值，其范围是[0, aim], 因此二维数组的列数应为aim+1
构造过程：
1、边界值
dp[0...N-1][0]:规划表的第一列，表示当需要兑换0元时，需要的货币数，显然需要货币数为0，因此直接设置为0；
dp[0][0...aim+1]:规划表的第一行，表示只使用一种货币arr[0]兑换面值0...aim面值需要的货币数，因此只要tmp_aim能够整除arr[0],返回整除后得到的商即可。
2、更新动态规划表
逐行更新，每行从左至右更新。
更新公式：
dp[i][j] = min(dp[i][j-arr[i]]+1, dp[i-1][j])
空间优化：通过计算发现，动态规划表的下一行与上一行有直接联系，每次计算之后上一行实际上就不再起作用了，因此在计算时只需知道“前一行”即可。所以，本题可将空间优化成

*/

///////////【解题，非原创】
// 做法1(复杂度低)：
// 把所有的钱能够凑成的总数作为状态i，dp[i]表示凑成i金额的钱币的数目
// 内循环为给的不同钱币，新增一种不同面值的钱，就去更新大于该币种的所有状态

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using  namespace std;

#define INT_MAX   1000

int main(){
	int n, aim;
	cin >> n >> aim;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; ++i){
		cin >> arr[i];
	}

	vector<int> dp(aim + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = arr[i]; j <= aim; ++j)	
		{
			if (dp[j - arr[i]] != INT_MAX)
			{		
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
			}
		}
	}

	if (dp[aim] == INT_MAX) cout << "-1" << endl;
	else  cout << dp[aim] << endl;

	system("pause");
	return 0;
}


/*

一行一行扫描，尝试每种面额，从0~aim，需要多少张。


 aim=6,arr=[2,1,3]
  
row_0:  0,1000,1,1000,2,1000,3,
row_1:  0,1,1,2,2,3,3,
row_2:  0,1,1,1,2,2,2,

dp[6] 2	

*/

