
{
cin >> int n;
int [][] adj = new int[n][n]
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < n; j++)
		cin>> adj[i][j]
}

floyd(adj);
}

// FLOYD WARSHELLS
public static void floyd(int[][]dist)
{
	int n = dist.length;
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}