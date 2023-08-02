#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX 1000
#define MAXE 10000

int visited[MAX];
int visited1[MAX];
typedef int element;
typedef struct {
	element queue[MAX];
	int front, rear;
}QueueType;

// 오류 함수
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화 함수
void queue_init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX;
	return q->queue[q->front];
}

typedef struct GraphType {
	int n; // 정점의 개수
	int adj_mat[MAX][MAXE];
}GraphType;
// 그래프 초기화
void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX; r++)
		for (c = 0; c < MAXE; c++)
			g->adj_mat[r][c] = 0;
}
// 정점 삽입 연산
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}
// 간선 삽입 연산
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE;
	printf("%d ", v+1);
	for (w = 0; w < g->n; w++)
	{
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w); // 정점 w에서 DFS 새로 시작
	}
}

void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;

	queue_init(&q);
	visited1[v] = TRUE; // 정점 v 방문 표시
	printf("%d ", v+1);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q); // 큐에 정점 추출
		for (w = 0; w < g->n; w++) // 인접 정점 탐색
		{
			if (g->adj_mat[v][w] && !visited1[w]) {
				visited1[w] = TRUE; // 방문 표시
				printf("%d ", w+1);
				enqueue(&q, w);
			}
		}
	}
}

int main() {
	int N, M, V;
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < N; i++)
		insert_vertex(g, i);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		insert_edge(g, u-1,v-1);
	}
	dfs_mat(g, V - 1);
	printf("\n");
	bfs_mat(g, V - 1);
	free(g);
}