#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int> > rg,int s,int t,int parent[]){
	vector<bool> v(rg.size(),false);
	queue<int> q;
	v[s]=true;
	q.push(s);
	int k,i;
	while(!q.empty()){
		k=q.front();
		q.pop();
		for(i=0;i<rg.size();i++){
			if(!v[i] && rg[k][i]>0){
				v[i]=true;
				parent[i]=k;
				q.push(i);
			}
		}
	}
	return v[t];
}

void dfs(vector<vector<int> > rg,bool vis[],int s){
	vis[s]=true;
	for(int i=0;i<rg.size();i++){
		if(!vis[i] && rg[s][i]>0)
		dfs(rg,vis,i);
	}
	
}



int main(){
	int n,i,j,k,x,s,t;
	cout<<"enter the no of vertices\n";
	cin>>n;
	cout<<"enter the source vertex\n";
	cin>>s;
	cout<<"enter the sink vertex\n";
	cin>>t;
	vector<vector<int> > g,rg;
	g.resize(n);
	rg.resize(n);
	cout<<"enter the flow network in the form of adjacency matrix\n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>x;
			g[i].push_back(x);
			rg[i].push_back(x);
		}
	}
	
	int max_flow=0;
	int parent[n];
	parent[s]=-1;
	
	
	while(bfs(rg,s,t,parent)){
		int pathflow=INT_MAX;
		for(i=t;i!=s;i=parent[i]){
			k=parent[i];
			if(rg[k][i]<pathflow)
			pathflow=rg[k][i];
		}
		
		for(i=t;i!=s;i=parent[i]){
			k=parent[i];
			rg[k][i] -=pathflow;
			rg[i][k] +=pathflow;
		}
		
		max_flow+=pathflow;
	}
	
	bool vis[n];
	for(i=0;i<n;i++)
	vis[i]=false;
	
	dfs(rg,vis,s);
	
	cout<<"minimum capacity cut is "<<max_flow<<endl;
	cout<<"cut set edges are\n";
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(vis[i] && !vis[j] && g[i][j]>0)
			cout<<i<<" --- "<<j<<endl;
		}
	}
	
	
}
