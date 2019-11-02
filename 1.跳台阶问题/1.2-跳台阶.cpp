/*
https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?tpId=13&tqId=11161&rp=1&ru=%2Factivity%2Foj&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1

时间限制：1秒 空间限制：32768K 热度指数：523734
本题知识点： 递归

题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。


对于本题,前提只有 一次 1阶或者2阶的跳法。  
     a.如果两种跳法，1阶或者2阶，那么假定第一次跳的是一阶，那么剩下的是n-1个台阶，跳法是f(n-1);  
     b.假定第一次跳的是2阶，那么剩下的是n-2个台阶，跳法是f(n-2)  
     c.由a\b假设可以得出总跳法为: f(n) = f(n-1) + f(n-2)?  
     d.然后通过实际的情况可以得出：只有一阶的时候 f(1) = 1 ,只有两阶的时候可以有 f(2) = 2  
     e.可以发现最终得出的是一个斐波那契数列：

*/



/////解法1，解法1更优
class Solution {	
public:

///数组这种解决方案，时间复杂度更小.
//根据斐波拉契数列特性，利用for循环，从前面往后面计算
	int jumpFloor(int number) {
		int *jump = new int[number+1]();
		if (number <= 2)
		{
			return number;
		}
		jump[1] = 1;
		jump[2] = 2;
		for (int i = 3; i < number+1; i++)
		{
			jump[i] = jump[i - 1] + jump[i - 2];
		}
		return jump[number];
	}
};




/////解法2.
class Solution {
public:
/////递归 的解决方案，比较耗时
    int jumpFloor(int number) {
        if(0==number)
        {
            return -1;
        }
        else if(1==number)
        {
            return 1;
        }
        else if(2==number)
        {
            return 2;
        }
        else 
        {
            return (jumpFloor(number-1)+jumpFloor(number-2));
        }
    }
};
