#include<iostream>
#include<list>
#include<map>
#include<queue>

using namespace std;

class Graph{
	public:
	map<int, list<int>> adjList;
	map<int, bool> visited;
	queue<int> q;
	
	void addEdge(int src, int dest)
	{
		adjList[src].push_back(dest);
		adjList[dest].push_back(src);
	}
	void DFS(int node)
	{
		visited[node]=true;
		cout<<node<<" ";
		for(int i:adjList[node])
		{
			if(!visited[i])
			{
				DFS(i);
			}
		}
	}
	
	void BFS()
	{
		if(q.empty()) return;
		
		int node=q.front();
		q.pop();
		cout<<node<<" ";
		for(int i: adjList[node])
		{
			if(!visited[i])
			{
				visited[i]=true;
				q.push(i);
			}
		}BFS();
	}
}g;

int main()
{
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,4);
	g.addEdge(1,5);
	g.addEdge(3,6);
	g.addEdge(2,7);
	
	cout<<"DFS::"<<endl;
	g.DFS(0);
	cout<<"BFS::"<<endl;
	g.q.push(0);
	g.visited[0] = true;
	g.BFS();
	return 0;
}
