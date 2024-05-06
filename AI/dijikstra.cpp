#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;

const int INF = numeric_limits<int>::max();

typedef pair<int,int> Edge;
typedef vector<vector<Edge>> Graph;

vector<int> dijikstra_algorithm(const Graph& G,int source)
{
	int V=G.size();
	vector<int> cost(V, INF);
	cost[source]=0;
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,source});
	
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		
		for(const Edge& edge : G[u])
		{
			int v = edge.first;
			int weight=edge.second;
			
			if(cost[u] + weight < cost[v])
			{
				cost[v]=cost[u]+weight;
				pq.push({cost[v],v});
			}
		}
	}
	return cost;
}

int main()
{
	int V=6;
	int source = 0;
	
	Graph G(V);
	G[0].emplace_back(1,2);
	G[0].emplace_back(2,4);
	G[0].emplace_back(2,1);
	G[0].emplace_back(3,7);
	G[0].emplace_back(4,3);
	G[0].emplace_back(4,1);
	G[0].emplace_back(5,5);
	G[0].emplace_back(5,2);
	
	vector<int> shortest_paths = dijikstra_algorithm(G, source);
	for(int i=0;i<V;i++)
	{
		cout<<"To Vertex"<<i<<":"<<shortest_paths[i]<<"\n";
	}
	return 0;
}
