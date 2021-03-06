# include <iostream>
# include <queue>
using namespace std;

class graph {
		
	public:
		int vertices;
		int **Edge;
		bool *visited;

		graph(int vertices) {
			
			this -> vertices = vertices;
			
			Edge = new int* [vertices];
			for(int i = 0; i < vertices; i++) {
				Edge[i] = new int[vertices];
			}

			visited = new bool[vertices];
			for(int i = 0; i < vertices; i++) {
				visited[i] = false;
			}
		}
		
		void dfs(int startingVertex) {

			cout << startingVertex << "\t";
			visited[startingVertex] = true;
			for(int i = 0; i < vertices; i++) {
				
				if(i == startingVertex) {
					continue;
				} 
					
				if(Edge[startingVertex][i] == 1) {
					if(visited[i] == true) {
						continue;
					}
					dfs(i);
				}
			}
		}

		void bfs(int startingVertex) {
				
			queue<int> q;
			q.push(startingVertex);
			visited[startingVertex] = true;

			while(q.empty() == false) {
					
				int x = q.front();
				q.pop();

				cout << x << "\t";

				for(int i = 0; i < vertices; i++) {
					if(i == x) {
						continue;
					} 

					if(Edge[x][i] == 1) {
						if(visited[i] == false) {
							q.push(i);
							visited[i] = true;
						}
					}
				}
			}
		}	


		void bfsDisconnected(int startingVertex) {
			
			for(int i = 0; i < vertices; i++) {
				visited[i] = false;
			}

			bfs(startingVertex);
			for(int i = 0; i < vertices; i++) {
				
				if(visited[i] == false) {
					bfs(i);
				}
			}
		}

		void dfsDisconnected(int startingVertex) {
				
			for(int i = 0; i < vertices; i++) {
				visited[i] = false;
			}
			
			dfs(startingVertex);
			for(int i = 0; i < vertices; i++) {

				if(visited[i] == false) {
					dfs(i);
				}
			}
		}
};

int main(void) {
		
	int vertices;
	cin >> vertices;

	int edges; 
	cin >> edges;

	graph *g = new graph(vertices);
	for(int i = 0; i < edges; i++) {
		int first, second;
		cin >> first >> second;

		g -> Edge[first][second] = 1;
		g -> Edge[second][first] = 1;
	}

	int startingVertex;
	cin >> startingVertex;

	g -> dfsDisconnected(startingVertex);

	cout << endl << endl << endl;

	g -> bfsDisconnected(startingVertex);
	cout << endl << endl;

	int vertex;
	cin >> vertex;

	for(int i = 0; i < vertices; i++) {
		delete[] g -> Edge[i];
	}

	delete[] g -> Edge;
	delete g;

	return 0;
}
