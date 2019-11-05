/*

链接：https://www.nowcoder.com/questionTerminal/32c71b52db52424c89a565e4134bfe4e
来源：牛客网

时间限制：1秒空间限制：32768K

小易准备去魔法王国采购魔法神器,购买魔法神器需要使用魔法币,但是小易现在一枚魔法币都没有,但是小易有两台魔法机器可以通过投入x(x可以为0)个魔法币产生更多的魔法币。
魔法机器1:如果投入x个魔法币,魔法机器会将其变为2x+1个魔法币
魔法机器2:如果投入x个魔法币,魔法机器会将其变为2x+2个魔法币
小易采购魔法神器总共需要n个魔法币,所以小易只能通过两台魔法机器产生恰好n个魔法币,小易需要你帮他设计一个投入方案使他最后恰好拥有n个魔法币。

输入描述:
输入包括一行,包括一个正整数n(1 ≤ n ≤ 10^9),表示小易需要的魔法币数量。

输出描述:
输出一个字符串,每个字符表示该次小易选取投入的魔法机器。其中只包含字符'1'和'2'。
示例1
输入
10
输出
122

----------------------------------------------------------
思路：
魔法机器1只能产生奇数，魔法机器2只能产生偶数。
从n不断按奇偶倒推回0就可以了。
------------------------------------------------------------
*/


#include <iostream>
#include <stack>
using namespace std;

//倒推
int output(int input,stack<char>& myStack)
{
    if(0 == input%2)
    {
        myStack.push('2');
        return (input-2)/2;
    }
    else
    {
        myStack.push('1');
        return (input-1)/2;
    }
}

int main()
{
    int cinNum=0;
    cin>>cinNum;
    stack<char> myStack;
    while(cinNum>2)
    {
        cinNum = output(cinNum,myStack);
    }
    if(1 == cinNum)
    {
        myStack.push('1');
    }
    else if(2==cinNum)
    {
        myStack.push('2');        
    }
    
    while(!myStack.empty())
    {
        printf("%c",myStack.top());
        myStack.pop();
    }
    return 0;
}

