#include <stdio.h>
#define INF 9999
#define MAX 20

int cost[MAX][MAX];
int dist[MAX];
int visited[MAX];
int parent[MAX];
int n;

void dijkstra(int start) {
    int i, j, u, v, min;

    for(i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;

    for(i = 1; i < n; i++) {
        min = INF;
        u = -1;
        for(j = 1; j <= n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        if(u == -1)
            break;

        visited[u] = 1;

        for(v = 1; v <= n; v++) {
            if(cost[u][v] && !visited[v] && dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nShortest distances from node %d:\n", start);
    for(i = 1; i <= n; i++) {
        if(dist[i] == INF)
            printf("%d -> %d : No path\n", start, i);
        else
            printf("%d -> %d : %d\n", start, i, dist[i]);
    }

    printf("\nEdges in shortest path tree:\n");
    for(i = 1; i <= n; i++) {
        if(parent[i] != -1)
            printf("%d - %d\n", parent[i], i);
    }
}

int main() {
    int i, j, edges, u, v, w, start;
    char edgeStr[10];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            cost[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v w) :\n");
    for(i = 0; i < edges; i++) {
        scanf("%s", edgeStr);

        if(sscanf(edgeStr, "%1d%1d%1d", &u, &v, &w) == 3) {
            cost[u][v] = cost[v][u] = w;
        } 
        else {
            sscanf(edgeStr, "%d", &u);
            scanf("%d%d", &v, &w);
            cost[u][v] = cost[v][u] = w;
        }
    }

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(start);
    return 0;
}
