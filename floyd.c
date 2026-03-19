#include <stdio.h>
#include <limits.h>
#define INF INT_MAX/2
#define N 4        //节点数量



void floyd(int** dist, int n,int path[N][N]);

void printFloyd(int path[N][N], int sta, int end);

int main(void)
{
	int dist[N][N] = {
		{0, 2, INF, INF},
		{INF, 0, -3, INF},
		{INF, INF, 0, 2},
		{INF, INF, INF, 0}
	};
	int* dist_ptr[N];
	for (int i = 0; i < N; i++) {
		dist_ptr[i] = dist[i];
	}
	int path[N][N];
	floyd(dist_ptr, N,path);

	int start, end;
	start = 0;
	end = 2;
	printf("节点 %d 到节点 %d 的最短路径：\n", start, end);
	printFloyd(path,start, end);
	printf("\n路径长度：%d\n", dist[start][end]);

	return 0;
}

void floyd(int** dist, int n,int path[N][N])
{//要求输入距离矩阵（二维数组），节点数
	int i,j,k;
	                         
	for (i = 0; i<n;i++){  /*初始化前驱矩阵*/
		for (j=0;j<n;j++){
			if (dist[i][j] !=INF)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}

	for (k=0;k<n;k++){
		for (i=0;i<n;i++){
			for (j=0;j<n;j++){
				if (dist[i][k] != INF && dist[k][j] != INF
					&& dist[i][j] > dist[i][k] + dist[k][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}	
}
void printFloyd(int path[N][N], int sta, int end)
{//递归，打印任意两个节点之间的路径
	if (sta == end) {
		printf("%d",sta); return;
	}
	if (path[sta][end] == -1) {
		puts("无法达到。"); return;
	}
	printFloyd(path, sta, path[sta][end]);
	printf("  -> %d", end);
}

