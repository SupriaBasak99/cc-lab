#include<bits/stdc++.h>
using namespace std;
int ans[50];
int c=0;

struct node{
	int key;
	node* left;
	node* sib;
};

node* newnode(int data){
	node* temp=(node*)malloc(sizeof(node));
	temp->key=data;
	temp->left=NULL;
	temp->sib=NULL;
}

void insert(node* root,node* child){
	if(root==NULL)
	return;
	
	if(root->left==NULL)
	root->left=child;
	else{
		node* temp=root->left;
		while(temp->sib!=NULL)
		temp=temp->sib;
		
		temp->sib=child;
	}
}

void preorder(node* root){
	while(root!=NULL){
		ans[c++]=root->key;
		preorder(root->left);
		root=root->sib;
	}
}
int minindex(vector<int> d,vector<bool> v){
	int in,min,i;
	min=10000;
	for(i=0;i<d.size();i++){
		if(!v[i] && min>d[i]){
			in=i;
			min=d[i];
		}
	}
	return in;
}

int main(){
	int n,i,j,x;
	cout<<"enter the no of cities\n";
	cin>>n;
	vector<vector<int> >g ;
	g.resize(n);
	cout<<"enter distances in the form of adjacency matrix\n";
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>x;
			if(x==0 && i!=j)
			g[i].push_back(10000);
			else
			g[i].push_back(x);
		}
	}
	vector<int> d(n,10000);
	vector<bool> v(n,false);
	vector<int> p(n,0);
	int k;
	cout<<"enter starting city\n";
	cin>>k;
	int s=k;
	d[k]=0;
	v[k]=true;
	p[k]=-1; //first city is root
	int count=1;
	
	node* a[n];
	a[k]=newnode(k);
	node* root=a[k];
	while(count<n){
		for(i=0;i<n;i++){
			if(i!=k && !v[i] && g[i][k]<d[i]){
			d[i]=g[i][k];
			p[i]=k;
		    }
		}
		k=minindex(d,v);
		a[k]=newnode(k);
		insert(a[p[k]],a[k]);
		v[k]=true;
		count++;
	}
	
	cout<<"approximate shortest path is\n";
	preorder(root);	
	ans[c]=s;
	int sum=0;
	for(i=0;i<=c;i++){
		if(i==c){
			cout<<ans[i]<<endl;
		}
		else{
		cout<<ans[i]<<" ----"<<g[ans[i]][ans[i+1]]<<"---- ";
		sum=sum+g[ans[i]][ans[i+1]];
	    }
	}
	cout<<"total distance is\n";
	cout<<sum<<endl;
	
}
