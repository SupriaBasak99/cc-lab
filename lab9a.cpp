#include<bits/stdc++.h>
using namespace std; 
int min(int distance[], bool visited[],int V) 
{ 
	int min=INT_MAX,min_index; 
	for(int v=0;v<V;v++) 
		if(visited[v]==false&&distance[v]<=min) 
			min=distance[v],min_index=v; 
	return min_index; 
}
int min(int a,int b){
	return a<b?a:b;
}
int main() 
{
	int V=4;
	int graph[V][V]={{0,3,0,7},{3,0,2,0},{0,2,0,1},{7,0,1,0}};
	cout<<"For the graph:"<<endl;
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	int sum=0;
	cout<<"using dijkstra's algorithm"<<endl;
	for(int a=0;a<V;a++)
	{
		int distance[V];
		bool visited[V]; 
		for(int i=0;i<V;i++) 
			distance[i]=INT_MAX,visited[i]=false; 
		distance[a]=0; 
		for(int count=0;count<V-1;count++)
		{ 
			int u=min(distance,visited,V);
			visited[u]=true;
			for(int v=0;v<V;v++)
				if(!visited[v]&&graph[u][v]&&distance[u]!=INT_MAX&&distance[u]+graph[u][v]<distance[v])
					distance[v]=distance[u]+graph[u][v];
		}
		for(int i=a+1;i<V;i++)
			sum+=distance[i];
	}
	cout<<"total distance = "<<sum<<endl;
	cout<<endl;
	
	
	cout<<"using floyd warshall algorithm"<<endl;
	sum=0;
	int g[][20]={{0,3,1000,7},{3,0,2,1000},{1000,2,0,1},{7,1000,1,0}};
	int n=sizeof(g)/sizeof(g[0]);
	int p[n][n][n+1];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			p[i][j][0]=g[i][j];
		}
	}
	for(int k=0;k<n+1;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				p[k][j][k+1]=p[k][j][k];
				p[j][k][k+1]=p[j][k][k];
				if(k!=i&&k!=j){
					p[i][j][k+1]=min(p[i][j][k],p[i][k][k]+p[k][j][k]);
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			sum+=p[i][j][n];
		}
	}
	cout<<"total distance = "<<sum<<endl;
}
