# include <iostream>
# include <vector>
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
		
		vector<int> bfs(int startingVertex) {
			
			queue<int> q;
			vector<int> v;

			q.push(startingVertex);
			visited[startingVertex] = true;

			while(q.empty() == false) {
				
				int x = q.front();
				q.pop();
				v.push_back(x);

				for(int i = 0; i < vertices; i++) {
					if(Edge[x][i] == 1 && visited[i] == false) {
						q.push(i);
						visited[i] = true;
					}
				}
			}

			return v;
		}

		vector<vector<int>> allConnectedComponents() {
			
			for(int i = 0; i < vertices; i++) {
				visited[i] = false;
			}

			vector<vector<int>> v;

			for(int i = 0; i < vertices; i++) {
				if(visited[i] == false) {
					vector<int> a = bfs(i);
					v.push_back(a);
				}
			}

			return v;
		}
};

int main(void) {
		
	int vertices, edges;
	cin >> vertices >> edges;

	graph *g = new graph(vertices);

	for(int i = 0; i < edges; i++) {

		int first, second;
		cin >> first >> second;
		
		g -> Edge[first][second] = 1;
		g -> Edge[second][first] = 1;
	}

	cout << endl << endl;
	vector<vector<int>> v = g -> allConnectedComponents();
	cout << endl << endl;

	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
				
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
