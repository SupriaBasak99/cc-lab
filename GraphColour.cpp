#include<bits/stdc++.h>
using namespace std;
class Graph{
	public:
	int V;
	list<int> *adj;
	Graph(int V);
	void addEdge(int v,int w);
	void graphColour();
};
Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}
void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
void Graph::graphColour()
{
	int colour[V];  
    colour[0]  = 0;  
    for (int j=1;j< V;j++) 
        colour[j] = -1;  
    bool available[V]; 
    for (int j=0;j<V;j++) 
        available[j] = false; 
    int k;
    for (int j=1;j<V;j++) 
    { 
        list<int>::iterator i; 
        for (i = adj[j].begin(); i != adj[j].end(); ++i) 
            if (colour[*i] != -1) 
                available[colour[*i]] = true;  
        for (k=0;k<V;k++) 
            if (available[k] == false) 
                break;
        colour[j]=k;
        for (i = adj[j].begin(); i != adj[j].end(); ++i) 
            if (colour[*i] != -1) 
                available[colour[*i]] = false; 
    } 
    cout<<"Vertex Colour"<<endl;
    for(int j=0;j<V;j++)
    	cout<<"  "<<j<<"      "<<colour[j]<<endl;
}
main()
{
	int v,e,q,w;
	cout<<"Ente r the number of vertices and edges : ";
	cin>>v>>e;
	Graph g = Graph(v);
	for(int i=0;i<e;i++)
	{
		cout<<"Enter edge "<<i+1<<" : ";
		cin>>q>>w;
		g.addEdge(q,w);
	}
	g.graphColour();
}
