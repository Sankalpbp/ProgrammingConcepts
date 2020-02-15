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

		bool isConnected() {
				
			queue<int> q;

			q.push(0);
			visited[0] = true;
			
			while(q.empty() == false) {
				
				int found = q.front();
				q.pop();

				for(int i = 0; i < vertices; i++) {
					if(Edge[found][i] == 1 && visited[i] == false) {
						q.push(i);
						visited[i] = true;
					}
				}
			}
					
			for(int i = 0; i < vertices; i++) {
				if(visited[i] == false) {
					return false;
				}
			}

			return true;
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

	if(g -> isConnected()) {
		cout << "\nGraph is connected.";
	} else {
		cout << "\nGraph is disconnected.";
	}

	return 0;
}
