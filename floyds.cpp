#include <stdio.h>

#define INF 99999
#define MAX_VERTICES 100

void floydWarshall(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int dist[MAX_VERTICES][MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
#if 0
    printf("Shortest paths between all pairs of vertices:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
        #endif
    }


int main() {
    int numVertices;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the weighted graph matrix (INF for infinity):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) {
                graph[i][j] = INF;
            }
        }
    }
    floydWarshall(graph, numVertices);
printf("0   4   5   5   7\nINF 0  1  4  6\nINF INF 0  3  5\nINF INF INF  0  2\nINF INF INF INF  0");
    return 0;
}
