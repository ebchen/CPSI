#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

/*

public class charles {

		int[][] matrix = new int[N][N];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				matrix[i][j] = Integer.MAX_VALUE / 3;
			}
		}

		Edge[] edges = new Edge[M];
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());

			int a = Integer.parseInt(st.nextToken()) - 1;
			int b = Integer.parseInt(st.nextToken()) - 1;
			int w = Integer.parseInt(st.nextToken());

			edges[i] = new Edge(a, b, w);

			matrix[a][b] = w;
			matrix[b][a] = w;
		}

		int normal = d(matrix);

		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < M; i++) {
			Edge e = edges[i];

			int t = Integer.parseInt(st.nextToken());
			matrix[e.a][e.b] += t;
			matrix[e.b][e.a] += t;
		}

		int charles = d(matrix);

		System.out.println(charles - normal);

	}

	static int d(int[][] matrix) {
		boolean visited[] = new boolean[matrix.length];
		int[] weights = new int[matrix.length];
		int filled = 0;
		Arrays.fill(weights, Integer.MAX_VALUE / 3);
		weights[0] = 0;

		while (filled != matrix.length) {
			int leastWeight = Integer.MAX_VALUE / 3;
			int leastWeightIndex = -1;
			for (int i = 0; i < matrix.length; i++) {
				if (!visited[i]) {
					if (weights[i] < leastWeight) {
						leastWeight = weights[i];
						leastWeightIndex = i;
					}
				}
			}

			visited[leastWeightIndex] = true;
			filled++;

			for (int j = 0; j < matrix.length; j++) {
				weights[j] = Math.min(weights[j], weights[leastWeightIndex] + matrix[leastWeightIndex][j]);
			}
		}

		return weights[matrix.length - 1];
	}

	static class Edge {

		int a, b, w;

		public Edge(int a, int b, int w) {
			this.a = a;
			this.b = b;
			this.w = w;
		}

	}
}
*/
class Edge
{
public:
	int a1;
	int weight;

	Edge(int x,int w)
	{
		a1 = x;
		weight = w;	
	}

	bool operator< (const Edge& otherEdge) const
	{
		if (weight < otherEdge.weight) return true;
		else if (weight == otherEdge.weight)
		{
			if (a1 < otherEdge.a1) return true;
			else return false;
		}
		else return false;
	}

	bool operator> (const Edge& otherEdge) const
	{
		if (weight > otherEdge.weight) return true;
		else if (weight == otherEdge.weight)
		{
			if (a1 > otherEdge.a1) return true;
			else return false;
		}
		else return false;
	}

};

class Solution
{
public:
	vector <vector<int>> matrix;
	int vertices;
	int edges;
	vector<int> times;
	vector<vector<int>> regular;
	vector <vector<int>> campusCharles;
	vector<vector<int>> campusOther;
	vector <vector<Edge>> edgesC;
	vector<vector<Edge>> edgesO;

	int dijikstrasCharles(int start, int end)
	{
		vector < bool > visited;
		for (int i = 0; i < vertices; i++)
		{
			visited.push_back(false);
		}
		
		priority_queue< Edge, std::vector<Edge>, std::greater<Edge> > pq;
		Edge e(start, 0);
		pq.push(e);

		while (!pq.empty())
		{
			Edge next = pq.top();
			pq.pop();

			if (visited[next.a1]) continue;
			visited[next.a1] = true;

			if (next.a1 == end) return next.weight;

			for (int i = 0; i < edgesC[next.a1].size(); i++)
			{
				Edge neighbor = edgesC[next.a1][i];
				if (!visited[neighbor.a1])
				{
					Edge e(neighbor.a1, neighbor.weight + next.weight);
					pq.push(e);
				}
			}
		}

	}

	int dijikstrasOther(int start, int end)
	{
		vector < bool > visited;
		for (int i = 0; i < vertices; i++)
		{
			visited.push_back(false);
		}
		priority_queue<Edge> pq;
		Edge e(start, 0);
		pq.push(e);

		while (!pq.empty())
		{
			Edge next = pq.top();
			pq.pop();
			//cout << "this is the edge going to " << next.a1 << " weight " << next.weight << endl;
			if (visited[next.a1]) continue;
			visited[next.a1] = true;

			if (next.a1 == end) return next.weight;

			for (int i = 0; i <edgesO[next.a1].size(); i++)
			{
				Edge neighbor = edgesO[next.a1][i];
				if (!visited[neighbor.a1])
				{
					Edge e(neighbor.a1, neighbor.weight + next.weight);
					pq.push(e);
				}
			}
		}

	}
	/*
	int floyd(int a, int start, int end)
	{
		if (a == 0)
		{
			int n = campusCharles.size();
			for (int k = 0; k < n; k++)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						campusCharles[i][j] = min(campusCharles[i][j], campusCharles[i][k] + campusCharles[k][j]);
						campusCharles[j][i] = campusCharles[i][j];
					}
				}
			}
			return campusCharles[start][end];
		}
		else
		{
			int n = campusOther.size();
			for (int k = 0; k < n; k++)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						campusOther[i][j] = min(campusOther[i][j], campusOther[i][k] + campusOther[k][j]);
						campusOther[j][i] = campusOther[i][j];
					}
				}
			}
			return campusOther[start][end];
		}

		
	}
	*/
	void output()
	{
		cin >> vertices;
		cin >> edges;

		for (int i = 0; i < edges; i++)
		{
			vector<int> path;
			int a;
			int b;
			int c;
			cin >> a;
			cin >> b;
			cin >> c;
			path.push_back(a);
			path.push_back(b);
			path.push_back(c);
			regular.push_back(path);

		}

		for (int i = 0; i < edges; i++)
		{
			int time;
			cin >> time;
			times.push_back(time);
		}
		/*
		for (int i = 0; i < vertices; i++)
		{
			vector<int> x;
			x.resize(vertices);
			campusCharles.push_back(x);
		}

		for (int i = 0; i < vertices; i++)
		{
			vector<int> x;
			x.resize(vertices);
			campusOther.push_back(x);
		}*/
		for (int i = 0; i < vertices; i++)
		{
			vector<Edge> x;
			vector<Edge> y;
			edgesC.push_back(x);
			edgesO.push_back(y);
		}
		for (int i = 0; i < edges; i++)
		{
			int x = regular[i][0] - 1;
			int y = regular[i][1] - 1;
			int charlesWeight = regular[i][2] + times[i];
			//campusCharles[x][y] = charlesWeight;
			//campusCharles[y][x] = charlesWeight;
			
			Edge e(y, charlesWeight);
			edgesC[x].push_back(e);
			Edge e1(x, charlesWeight);
			edgesC[y].push_back(e1);
		}

		for (int i = 0; i < edges; i++)
		{
			int x = regular[i][0] - 1;
			int y = regular[i][1] - 1;
			//campusOther[x][y] = regular[i][2];
			Edge e(y, regular[i][2]);
			Edge e1(x, regular[i][2]);
			edgesO[x].push_back(e);
			edgesO[y].push_back(e1);
		}

		int charles = dijikstrasCharles(0, vertices - 1);
 		int normal = dijikstrasOther(0, vertices - 1);

		cout << charles - normal << endl;
	}
};

int main()
{
	Solution solution;
	solution.output();

	return 0;
}

/*
3 3
1 2 10
2 3 10
1 3 10
-5 0 15



3 3
1 2 10
2 3 10
1 3 10
5 0 0



*/

/*
when using pq use a state.
store weights



*/