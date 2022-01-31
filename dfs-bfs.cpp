#include <list> 
#include <iostream> 
using namespace std;
class dfs{
public:
	dfs(int size_input){
		size = size_input;
		DFS_Stack = new list<int>[size_input];
	}
	void DFS() {
		bool* find = new bool[size];
		for (int i = 0; i < size; i++)
			find[i] = false;
		for (int i = 0; i < size; i++)
			if (find[i] == false)
				print(i, find);
		cout << "null"<<endl;
	}
	void Add_Edge(int pos, int value) {
		DFS_Stack[pos].push_back(value);
	}

private:
	int size;
	list<int>* DFS_Stack;
	void print(int i, bool find[]) {
		find[i] = true;
		cout << i << " --> ";
		list<int>::iterator j;
		for (j = DFS_Stack[i].begin(); j != DFS_Stack[i].end(); ++j)
			if (!find[*j])
				print(*j, find);		
	}
};

class bfs {
public:
	bfs(int size_input) {
		size = size_input;
		BFS_Stack = new list<int>[size_input];
	}
	void BFS(int pos = 0) {
		bool* find = new bool[size];
		for (int i = 0; i < size; i++)
			find[i] = false;
		list<int> arr;
		find[pos] = true;
		arr.push_back(pos);
		list<int>::iterator i;
		while (!arr.empty()) {
			pos = arr.front();
			cout << pos << " --> ";
			arr.pop_front();
			for (i = BFS_Stack[pos].begin(); i!=BFS_Stack[pos].end(); ++i) {
				if (!find[*i]) {
					find[*i] = true;
					arr.push_back(*i);
				}
			}
		}
		cout << "null"<<endl;
	}
	void Add_Edge(int pos, int value) {
		BFS_Stack[pos].push_back(value);
	}
private:
	int size;
	list<int>* BFS_Stack;
};

void main(){
	dfs first(5);
	bfs seccond(4);

	first.Add_Edge(0, 1);
	first.Add_Edge(0, 2);
	first.Add_Edge(0, 3);
	first.Add_Edge(1, 2);
	first.Add_Edge(2, 4);
	first.Add_Edge(3, 3);
	first.Add_Edge(4, 4);
		
	seccond.Add_Edge(0, 1);
	seccond.Add_Edge(0, 2);
	seccond.Add_Edge(1, 2);
	seccond.Add_Edge(2, 0);
	seccond.Add_Edge(2, 3);
	seccond.Add_Edge(3, 3);

	first.DFS();
	seccond.BFS();
}