/* 1 
  2 题目标题：翻硬币
  3 
  4     小明正在玩一个“翻硬币”的游戏。
  5 
  6     桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。
  7 
  8     比如，可能情形是：**oo***oooo
  9 
 10     如果同时翻转左边的两个硬币，则变为：oooo***oooo
 11 
 12     现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？
 13     我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求：
 14 
 15 程序输入：
 16 两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度<1000
 17 
 18 程序输出：
 19 一个整数，表示最小操作步数
 20 
 21 例如：
 22 用户输入：
 23 **********
 24 o****o****
 25 
 26 程序应该输出：
 27 5
 28 
 29 再例如：
 30 用户输入：
 31 *o**o***o***
 32 *o***o**o***
 33 
 34 程序应该输出：
 35 1
36 
 37 
 38 
 39 
 40 资源约定：
 41 峰值内存消耗 < 64M
 42 CPU消耗  < 1000ms
 43 
 44 
 45 请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。
 46 
 47 所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。
 48 
 49 注意: main函数需要返回0
 50 注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
 51 注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。
 52 
 53 提交时，注意选择所期望的编译器类型。
 *
 * 
 * 解题方法：
 * 		广搜状态；
 * 		广搜思路：(1)先将一行相联两个的搜素一遍，存入队列;
 * 			(2)再出队，将队头状态与目标状态相比，若相同，则返回步数;
 * 			(3)否则，以目前状态按照第(1)步进行;
 * */

#include <iostream>
#include <queue>
#include <string>

using namespace std;
string target;

typedef struct {
	string status;
	int step;
} Node;

int bfs(Node begin) {
	int i;
	queue <Node> status;
	status.push(begin);

	while(!status.empty()) {
		Node head = status.front();
		status.pop();
		// 对比
		if(head.status == target)
			return head.step;

		for(i=0; i<target.length()-1; i++) {
			Node temp = head;
			// 翻转
			if(temp.status[i] == '*')
				temp.status[i] = 'o';
			else
				temp.status[i] = '*';

			if(temp.status[i+1] == '*')
				temp.status[i+1] = 'o';
			else
				temp.status[i+1] = '*';

			temp.step ++;

			// 入队
			status.push(temp);
		}
	}
}

int main(void) {
	Node begin;
	
	cin >> begin.status >> target;
	begin.step = 0;

	cout << bfs(begin) << endl;
	
	return 0;
}
