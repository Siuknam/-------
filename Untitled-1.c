#include<stdio.h>

#define V 6 // 정점 개수 정의 // 
int INF = 123456789; // 무한대값 정의 //

int W[V][V] = {
	{0,10,2,1,INF,INF},
	{10,0,6,INF,8,7},
	{2,6,0,3,5,INF},
	{1,INF,3,0,4,INF},
	{INF,8,5,4,0,9},
	{INF,7,INF,INF,9,0}
}; // 그래프 생성 //

bool v[V]; // 방문한 노드 정의 //
int D[V]; // 거리 정의 // 

int Getindex() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < V; i++) {
		if (D[i] < min && !v[i])
		{
			min = D[i];
			index = i;
		}
	}
	return index;
} // 가장 최소 거리를 가지는 정점을 반환 // 

void dijkstra(int start){
	for (int i = 0; i < V; i++)
	{
		D[i] = W[start][i];
	}
	v[start] = true;
	for (int i = 0; i < V - 2; i++)
	{
		int current = Getindex();
		v[current] = true;
		for (int j = 0; j < 6; j++)
		{
			if (!v[j])
			{
				if (D[current] + W[current][j] < D[j])
				{
					D[j] = D[current] + W[current][j];
				}
			}
		}
	}
} // Dijkstar 알고리즘 구현 // 

int main(void)
{
	dijkstra(0);
	printf("거리 출력 \n");
	for (int i = 0; i < V; i++)
	{
		printf("%d ", D[i]);
	}
}