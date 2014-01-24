/*
标题: 振兴中华

    小明参加了学校的趣味运动会，其中的一个项目是：跳格子。

地上画着一些格子，每个格子里写一个字，如下所示：（也可参见p1.jpg）

从我做起振
我做起振兴
做起振兴中
起振兴中华


    比赛时，先站在左上角的写着“从”字的格子里，可以横向或纵向跳到相邻的格子里，但不能跳到对角的格子或其它位置。一直要跳到“华”字结束。


    要求跳过的路线刚好构成“从我做起振兴中华”这句话。

    请你帮助小明算一算他一共有多少种可能的跳跃路线呢？(35)

答案是一个整数，请通过浏览器直接提交该数字。
注意：不要提交解答过程，或其它辅助说明类的内容。

 * 
 * */

#include <stdio.h>
#include <string.h>
// 从(c)我(w)做(z)起(q)振(e)兴(x)中(o)华(h)
int a[][5] = {
	{'c','w','z','q','e'},
	{'w','z','q','e','x'},
	{'z','q','e','x','o'},
	{'q','e','x','o','h'}
};
// right down left up
int mx[] = {1, 0, -1, 0};
int my[] = {0, 1, 0, -1};

int road;
void dfs(int vis[][5], char word[], int num, int x, int y) {
	if(num >= 8) {
		word[8] = '\0';
		if(!strcmp(word, "cwzqexoh"))
			road ++;
		return ;
	}

	// 4 directions
	for(int i=0; i<4; i++) {
		x += mx[i];
		y += my[i];
		if(x>=0&&x<5 && y>=0&&y<4 && !vis[y][x]) {
			vis[y][x] = 1;
			word[num] = a[y][x];
			dfs(vis, word, num+1, x, y);
			vis[y][x] = 0;
		}	
		x -= mx[i];
		y -= my[i];
	}
}

int main(void) {
	int i, j;
	int vis[4][5];
	char word[9];

	for(i=0; i<4; i++) {
		for(j=0; j<5; j++)
			printf("%c ", a[i][j]);
		printf("\n");
	}

	road = 0;
	memset(vis, 0, sizeof(vis));
	word[0] = 'c';
	vis[0][0] = 1;
	dfs(vis, word, 1, 0, 0);

	printf("%d\n", road);

	return 0;
}
