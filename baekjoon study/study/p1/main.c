#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX 10

typedef int element;
typedef struct {
	element queue[MAX];
	int front, rear;
}QueueType;

// ���� �Լ�
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ �Լ�
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
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX;
	return q->queue[q->front];
}

#define MAX_V 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX][MAX];
}GraphType;
int visited[MAX];

// �׷��� �ʱ�ȭ
void graph_init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX; r++)
		for (c = 0; c < MAX; c++)
			g->adj_mat[r][c] = 0;
}

// ���� ���� ����
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX) {
		fprintf(stderr, "�׷���: ���� ���� �ʰ�");
		return;
	}
	g->n++;
}
// ���� ���� ����
void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "�׷���: ���� ��ȣ ����");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;

	queue_init(&q);
	visited[v] = TRUE; // ���� v �湮 ǥ��
	printf("%d �湮-> ", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q); // ť�� ���� ����
		for (w = 0; w < g->n; w++) // ���� ���� Ž��
		{
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE; // �湮 ǥ��
				printf("%d �湮-> ", w);
				enqueue(&q, w);
			}
		}
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);
	for (int i = 0; i < 6; i++)
	{
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 2);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 0, 4);
	insert_edge(g, 4, 5);
	insert_edge(g, 1, 5);

	printf("�ʺ� �켱 Ž��\n");
	bfs_mat(g, 0);
	printf("\n");
	free(g);
	return 0;
}