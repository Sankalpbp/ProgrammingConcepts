# include <iostream>
# include <map>
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

		void getPathBFS(int start, int end, map<int, int> &m);
};

void graph :: getPathBFS(int start, int end, map<int, int> &parentOf) {
		
	queue<int> q;

	q.push(start);
	visited[start] = true;

	int currentVertex;

	while(q.empty() == false) {
			
		currentVertex = q.front();
		q.pop();

		if(currentVertex == end) {
			break;
		}

		for(int i = 0; i < vertices; i++) {
			if(Edge[currentVertex][i] == 1 && visited[i] == false) {
				visited[i] = true;
				q.push(i);
				parentOf[i] = currentVertex;
			}
		}
	}

	if(currentVertex == end) {
		int vertex = end;
		while(vertex != start) {
			cout << vertex << " ";
			vertex = parentOf[vertex];
		}
		cout << start;
	}
			
}

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

	map<int, int > m;
	g -> getPathBFS(start, end, m);

	cout << endl << endl;

	return 0;
}
