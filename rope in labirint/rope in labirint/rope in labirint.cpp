#include <list>
using namespace std;
class Graph {
private:
	int nv;
	list<int>* g;
public:
	Graph() {};
	~Graph() {};
	int BFS(int); 

};