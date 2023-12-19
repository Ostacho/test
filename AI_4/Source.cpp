#include <iostream>
#include <vector>
#include <queue>
#include <stack>

void bfs(int s, int e, std::vector<int> edge_graph[], bool visit[]) {
    std::queue<int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        std::cout << u << " ";
        q.pop();

        if (u == e) {
            break;
        }

        for (int i = 0; i < edge_graph[u].size(); i++) {
            if (!visit[edge_graph[u][i]]) {
                q.push(edge_graph[u][i]);
                visit[edge_graph[u][i]] = true;
            }
        }
    }
}

void fn_dfs(int s, int e, std::vector<int> edge_graph[], bool visit[]) {
    std::stack<int> stk;
    stk.push(s);
    visit[s] = true;
    while (!stk.empty()) {
        int u = stk.top();
        std::cout << u << " ";
        stk.pop();

        if (u == e) {
            break;
        }

        for (int i = 0; i < edge_graph[u].size(); i++) {
            if (!visit[edge_graph[u][i]]) {
                stk.push(edge_graph[u][i]);
                visit[edge_graph[u][i]] = true;
            }
        }
    }
}

void edge(std::vector<int> edge_graph[], int u, int v) {
    edge_graph[u].push_back(v);
    edge_graph[v].push_back(u);
}

int main() {
    int N = 6;
    std::vector<int> edge_graph[7];
    bool visit[7] = { false };

    edge(edge_graph, 1, 2);
    edge(edge_graph, 1, 3);
    edge(edge_graph, 1, 6);
    edge(edge_graph, 3, 4);
    edge(edge_graph, 4, 5);

    int start;
    std::cout << "Enter the starting vertex: ";
    std::cin >> start;

    int end;
    std::cout << "Enter the ending vertex: ";
    std::cin >> end;

    if (start < 1 || start > N) {
        std::cerr << "Invalid starting vertex. Exiting.\n";
        return 1;
    }

    std::cout << "\nBFS: ";
    bfs(start, end, edge_graph, visit);
    std::cout << std::endl;

    for (int i = 1; i <= N; i++) {
        visit[i] = false;
    }

    std::cout << "DFS: ";
    fn_dfs(start, end, edge_graph, visit);
    std::cout << std::endl;

    return 0;
}
