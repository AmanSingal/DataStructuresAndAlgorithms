 #include<bits/stdc++.h>
 using namespace std;

ifstream fp; // defining the input and output file streams
ofstream gp;
 
template<typename T>
class Graph{
    //Defining a class having each node associated with pair of directed node 
    //along with the distance
    // (node, weight)
   unordered_map<T, list<pair<T,long long int> > > m;  
   long long int mxVertex = 0;
public:
//Adding an edge
   void addEdge(T u,T v,long long int dist){
       m[u].push_back(make_pair(v,dist));
       //cout << "mx bulbul " << mxVertex << '\n';
       mxVertex = max({mxVertex, u, v});
      
   }

   void dijkstra(T src){
      
       unordered_map<T,long long int> dist;
      //Initializing distances of every other vertex from source
       // for(auto j:m){
       for(int i=0;i<=mxVertex;i++){ 
            //dist[j.first].first = j.first;
        // j.first = node, dist[node] = inf
           // dist[j.first] = INT_MAX;
            dist[i] = INT_MAX;

       }
      
       //Make a set to find a out node with the minimum distance
       //set<pair<long long int, T> > s;
      //Setting distance of source node to 0
       // priority queue using min heap containing pair of (weight, node)
       priority_queue <pair<long long int, T>, vector<pair<long long int, T>>, greater<pair<long long int, T>> > s;
       dist[src] = 0;
       s.push(make_pair(0,src));
      //Insert Source Node to set s whose first element is distance and second 
       //element is node key
       while(!s.empty()){
           //Find the pair at the front.
           auto p = (s.top());
           T node = p.second;
          //node now has key value of the first node in the set
           T nodeDist = p.first; //---------------------------------------------------------------------------
           //cout << "node " << nodeDist << '\n';
           //nodeDist is the distance of any node from source
           s.pop();
          //erase the front node
          
           //Iterate over neighbours/children of the current node
           // pair of (node, weight)
           for(auto childPair: m[node]){
              //Search for its adjacent nodes
               if(nodeDist + childPair.second < dist[childPair.first]){
                 //If the current source node distance is + distance from node
                 //adjacent node is less than the distance from source to adjacent node

                 //In the set updation of a particular is not possible
                 // we have to remove the old pair, and insert the new pair to simulation updation
                   T dest = childPair.first;
                   //auto f = s.find(make_pair(dist[dest],dest));
                   //if(f!=s.end()){
                    //   s.erase(f);
                   //}
                  
                   //Insert the new pair
                   dist[dest] = nodeDist + childPair.second;
                   s.push(make_pair(dist[dest],dest));
                  
               }
              
           }
       }
       //Printing the distance to a file
       for(auto d:dist){
          if(d.first==src){
            gp<<d.first<<" "<<"0"<<endl;
          }
          else if(d.second != INT_MAX ){
           gp<<d.first<<" "<<d.second<<endl;}
           else
                gp<<d.first<<" "<<"-1"<<endl;
       }
      
      
   }
 
};
 
int main(int argc, char *argv[]){
    fp.open(argv[1]);
    int h=atoi(argv[2]);
    gp.open("dijkstra.txt");
    Graph<long long int> g;
    int in1,in2,in3;
    while(fp>>in1){
        fp>>in2;
        fp>>in3;
        g.addEdge(in1,in2,in3);
        // //cout << in1 <<
    }
  
    g.dijkstra(h);
  
  
    fp.close();
    gp.close();
return 0;
}
