# include <iostream>
# include <vector>
using namespace std;

class graph {
			
	public:
		int vertices;
		int **Edges;
		bool *visited;

		graph(int vertices) {
				
			this -> vertices = vertices;
			Edge = new int* [vertices];

			for(int i = 0; i < vertices; i++) {
				Edge[i] = new int[vertices];
			}

			visited = new bool[vertices];
		}

		vector<int> getPath(int startVertex, int endVertex);
		void getPath(int startVertex, int endVertex);
}

void graph :: getPath(int startVertex, int endVertex, vector<int> v) {
		
	for(int i = 0; i < vertices; i++) {

		if(i == startVertex) {
			continue;
		}
				
		if(Edge[startVertex][i] == 1 && visited[i] == false) {
			if(i == endVertex) {
				v.push_back(i);
			}
			getPath(i, endVertex, v);
		}
	}
}

vector<int> graph :: getPath(int startVertex, int endVertex) {
		
	vector<int> v;

	if(startVertex == endVertex) {
		v.push_back(endVertex);
		return;
	}

	getPath(startVertex, endVertex, v);

	return v;
}

int main(void) {
		
	
	return 0;
}
