#include<bits/stdc++.h>
 using namespace std;

ifstream fp; // defining the input and output file streams
ofstream gp;

//making a class containing edge parameters
class Edgelist
{
public:
	int srs;
	int dest;
	int weight;
};

bool comp(Edgelist e1, Edgelist e2){
	return e1.weight < e2.weight;
}

int findpar(int &v , int *par){
	if(par[v] == v){
		return v;
	}
	return findpar(par[v], par);
}

void kruskal(Edgelist *inputData, int n, int e){
	sort(inputData, inputData + e, comp);

	Edgelist *outputData = new Edgelist[n-1];
	int *par = new int[n];
	for(int  i=0; i<n ; i++){
		par[i] = i; 
	}
	int count = 0;
	int  i = 0;
	while(count != n-1){
		Edgelist currEdge = inputData[i];

		int srsparent = findpar(currEdge.srs, par);
		int destparent = findpar(currEdge.dest, par);

		if(srsparent != destparent){
			outputData[count] = currEdge;
			count++;
			par[srsparent] = destparent;
		}
		i++;
	}

	for(int  i =0 ; i< n-1 ; i++){
		gp<<outputData[i].srs<< " "<<outputData[i].dest<<" "<<outputData[i].weight<<endl;
	}
}

int main(int argc, char *argv[]){

	fp.open(argv[1]);
	gp.open("mst.txt");
	int count =0;
	int in1,in2,in3, cont=0,max_=0;
	//vector<int> forSort;
	while(fp>>in1){
		fp>>in2;
		fp>>in3;
	//	forSort.emplace_back(in1);
	//	forSort.emplace_back(in2);
		count++;
	}
	Edgelist *inputData = new Edgelist[count]; //this may be wrong
	
	fp.close();
	fp.open(argv[1]);
	while(fp>>in1){
		fp>>in2;
		fp>>in3;
		inputData[cont].srs = in1;
		inputData[cont].dest = in2;
		inputData[cont].weight = in3;
		if (max_<max(in1,in2))
			max_=max(in1,in2);
		cont++;

	}
	int n = max_;
	//sort(forSort.begin(), forSort.end());
	//vector<int>::iterator ip;
	//ip = std::unique(forSort.begin(), forSort.end());
	//forSort.resize(std::distance(forSort.begin(),ip));
	//int n = forSort.size();
	kruskal(inputData, n , count);

fp.close();
gp.close();
return 0;
}
