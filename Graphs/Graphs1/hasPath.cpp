# include <iostream>
using namespace std;

class graph {
		
	public: 
		int vertices;
		int **Edge;
		bool *visited;

		graph(int vertices) {
				
			this -> vertices = vertices;
			Edge = new int*[vertices];

			for(int i = 0; i < vertices; i++) {
				Edge[i] = new int[vertices];
			}

			visited = new bool[vertices];
		}

		bool hasPath(int start, int end) {
				
			visited[start] = true;
			if(start == end) {
				return true;
			}

			for(int i = 0; i < vertices; i++) {
				if(i == start) {
					continue;
				}

				if(Edge[start][i] == 1 && visited[i] == false) {
					if(hasPath(i, end)) {
						return true;
					}
				}
						
			}

			return false;
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

	int start, end;
	cin >> start >> end;

	if(g -> hasPath(start, end)) {
		cout << "\nThere is a path";
	} else {
		cout << "\nThere isn't any path";
	}

	cout << endl << endl;

	return 0;
}
