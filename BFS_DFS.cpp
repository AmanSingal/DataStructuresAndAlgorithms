#include<bits/stdc++.h>
 using namespace std;

ifstream fp; // defining the input and output file streams
ofstream gp, gp1;

//making an adjacency list
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v); 
} 

// Declaring functions to do BFS and Topological Sort
void BFS(vector<int> adj[], int h, vector<int> dis, vector<int> color,int);

void DFS_VISIT(vector<int> adj[],int t, vector<int> &disc, vector<int> &fin, int &time,vector<int> &color, vector< pair <int,int> > &vect);

void DFS(vector<int> adj[], int max_, vector<int>);


int main(int argc, char *argv[]){
fp.open(argv[1]);
 
gp.open("sd.txt");
gp1.open("ts.txt");

vector<int> color(10000);
vector<int> dis(10000);

int  k = 10000;
vector<int> adj[k];
//vector<int> uni; // To store the unique values of the root nodes
int in1,in2,max_=0;
while(fp>>in1){
fp>>in2;
//uni.emplace_back(in1);
//uni.emplace_back(in2);
addEdge(adj, in1, in2);
if (max_<max(in1,in2))
	max_=max(in1,in2);

}
/*cout<<uni.size()<<"\n";
sort(uni.begin(),uni.end());
cout<<uni.size()<<"\n";
vector<int>::iterator ip;

ip = std::unique(uni.begin(), uni.end());
uni.resize(std::distance(uni.begin(),ip));
cout<<uni.size()<<"\n";
*/
	int h = atoi(argv[2]);
    // Mark all the vertices as not visited 
   /* bool *visited = new bool[uni.size()]; 
    for(int i = 0; i < uni.size(); i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[h] = true; 
    queue.push_back(h); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
*/
/*int size1 = uni.size();
int o=1, l=0, count=0 , arr[size1], m=0,count1=0;
for(int g=0; g<uni.size(); ++g){
	if(uni[g]==h){
	//if( adj[uni[g]] != 0){
		arr[l]=uni[g];
		//cout<<"\n Adjacency  list of vertex " << uni[g] << "\nhead ";
			
			for(auto x : adj[arr[m]]){
				cout<<" -> " << x;
				count1++;
				++l;
				arr[l] = x;
				gp<<x << " " << o <<endl;
				m++;}
				for(auto x : adj[arr[l]]){count++;}
				if(count1==count){
					o++;
				}
				//o++;	
			

			printf("\n");
		break;
	}

}*/

//int maxElement = *max_element(uni.begin(),uni.end());
for(int u =0; u<=max_; u++){
	color[u] = 0;
	dis[u] = -1;
}/*
int o=0;
if(0<=h<=maxElement){
	for(auto x : adj[h]){
		//cout<<" -> " << x;
		gp<<x<<" " << o<<endl;	
	}
}
*/
BFS(adj, h, dis, color,max_);
DFS(adj, max_, color);

fp.close();
gp.close();
gp1.close();
return 0;
}



void BFS(vector<int> adj[],int h,vector<int> dis, vector<int> color,int max_){
	color[h] = 1;
	dis[h] = 0;
	int u;
	queue<int> Queue;
	Queue.push(h);
	while(!Queue.empty()){
		u=Queue.front();
		Queue.pop();
		for(auto v : adj[u]){
			if(color[v] == 0){
				color[v] = 1;
				dis[v] = dis[u] +1;
				Queue.push(v);
			}
			
		}
	}
	for(int k=0 ; k <=max_ ;k++){
		gp<<k << " " <<dis[k]<<endl;
	}
}

void DFS(vector<int> adj[], int max_, vector<int> color){
	vector<int> disc(10000);
	vector<int> fin(10000);
	vector< pair <int,int> > vect;
	for(int t=0 ; t <= max_ ; t++){
		color[t] = 0;
	}
	int time = 0;
	for(int t=0 ; t <= max_ ; t++){
		if(color[t] == 0)
			DFS_VISIT(adj, t, disc, fin, time, color, vect);
	}
	std::sort(vect.begin(),vect.end(),greater<>());
	for(auto p : vect){
		gp1<< p.second<<endl;
	}

}

void DFS_VISIT(vector<int> adj[],int t, vector<int> &disc, vector<int> &fin, int &time,vector<int> &color, vector< pair <int,int> > &vect){
	time++;
	disc[t] = time;
	color[t] = 1;
	for(auto x : adj[t]){
		if(color[x] == 0){
			DFS_VISIT(adj, x, disc, fin, time, color, vect);
		}
	}
	//color[t] =1;
	time = time + 1;
	fin[t] = time; 
	vect.push_back(make_pair(fin[t], t));
}

