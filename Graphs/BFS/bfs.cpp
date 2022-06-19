#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MaxNodes 11

int nNodes, nEdges;
vector<int> adjList[MaxNodes];
bool isVisited[MaxNodes];

void bfs(int src)
{
	queue<int> que;

	que.push(src);
	isVisited[src] = true;

	while (!que.empty())
	{
		src = que.front();
		que.pop();

		for (int i = 0; i < adjList[src].size(); i++)
		{
			if (isVisited[adjList[src][i]] == false)
			{
				cout << adjList[src][i] << endl;

				que.push(adjList[src][i]);
				isVisited[adjList[src][i]] = true;
			}
		}
	}
}


int main()
{
	//freopen("input.txt", "r", stdin);
	
	int a, b;
	
	cin >> nNodes >> nEdges;
	for (int i = 0; i < nNodes; i++)
	{
		isVisited[i] = false;
	}

	for (int i = 0; i < nEdges; i++)
	{
		cin >> a >> b; //considering bi-directional path
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	int src;
	cin >> src;

	bfs(src);

	return 0;
}

// input
/*10 10
1 2
1 3
1 4
2 5
2 6
2 7
3 7
4 8
8 9
8 10
5*/