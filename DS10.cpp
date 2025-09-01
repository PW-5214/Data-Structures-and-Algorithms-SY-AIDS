#include <iostream>
using namespace std;

const int N = 4;
int graph[N][N];
int mincost = 1000000;  // A high initial value for minimum cost

void tsp(int curr, int count, int cost, int start) {
    if (count == N && graph[curr][start] != 0) {  // Base case: all nodes visited, and return path exists
        if (cost + graph[curr][start] < mincost) {
            mincost = cost + graph[curr][start];
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (graph[curr][i] != 0 && cost + graph[curr][i] < mincost) {  // Path exists and within min cost
            int temp = graph[curr][i];  // Save current edge cost
            graph[curr][i] = graph[i][curr] = 0;  // Mark as visited by setting to 0
            tsp(i, count + 1, cost + temp, start);  // Recur with updated cost
            graph[curr][i] = graph[i][curr] = temp;  // Restore edge after recursion
        }
    }
    
}

int main() {
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    tsp(0, 1, 0, 0);

    cout << "Minimum cost of traversal is: " << mincost << endl;
    return 0;
}
