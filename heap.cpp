#include <bits/stdc++.h>
using namespace std;

int heap[1000],copyHeap[1000];
int heap_size=0;
ifstream fp;
ofstream gp;
void increase_key(int*, int ,int);
void max_heapify(int*, int , int);
int main(int argc, char *argv[]){
	fp.open(argv[1]);
	string str;
	int key,index;
	gp.open("heap.txt");
	if(!fp){
		cout<<"File is not there."<<endl;
	}
	else{
             while(fp>>str){
                if(str=="insert"){
                fp>>key;
                        if(heap_size==0){
                                heap[0]=key;
                                gp<<key<<" inserted"<<endl;
                        }
                        else{
                                
                                heap[heap_size]=-1;
                                increase_key(heap,heap_size,key);
                                gp<<key<<" inserted"<<endl;
                        }
                        heap_size++;
                }
                else if(str=="sort"){
                        for(int j=0;j<heap_size;j++){
                                copyHeap[j]=heap[j];
                        }
                        int x = heap_size;
                        for (int i = x / 2 - 1; i >= 0; i--) {
                                 max_heapify(copyHeap, i, x); }
                        for(int j=x-1;j>=0;j--){
                               int hash = copyHeap[0];
                                copyHeap[0]=copyHeap[j];
                                copyHeap[j]=hash; 
                                max_heapify(copyHeap,0,j);
                        }
                       
                        for(int i=0;i<=heap_size-1;i++){
                                if(i==heap_size-1)
                                 gp<<copyHeap[i];
                                else
                                 gp<<copyHeap[i]<<" ";
                        }gp<<endl;

                }
                else if(str=="extract-max"){
                        if(heap_size==0){
                                gp<<endl;
                        }
                        else{
                                gp<<heap[0]<<endl;
                                heap[0]=heap[heap_size-1];
                                heap_size--;
                                max_heapify(heap,0,heap_size);
                        }
                }
                else if(str=="increase-key"){
                        fp>>index;
                        if(index>=0 && index<heap_size){
                                fp>>key;
                                increase_key(heap,index,key);
                                if(heap[index]>key){
                gp<<key<<" is less than the current key at "<<index<<endl;
        }                       else{
                 gp<<"Key at "<<index<<" changed to "<<key<<endl;
                 
                
        }
                        }
                        else{
                                gp<<index<<" is not within limits of 0 to heap_size-1"<<endl;
                        }
                        
                }
                else if(str=="maximum"){
                        if(heap_size==0){
                        gp<<endl;}
                        else{
                        gp<<heap[0]<<endl;
                        }
                }
             }

	fp.close();
	gp.close();
	}
return 0;
}

void increase_key(int heap[],int index, int key){
        int temp;
        if(heap[index]>key){
                
        }
        else{
                heap[index]=key;
                if(index>0){
                        int x= floor((index-1)/2);
                        if(heap[x]>heap[index]){
                               
                        }
                        else{
                             temp=heap[index];
                             heap[index]=heap[x];
                             heap[x]=temp;
                             index=x;
                             increase_key(heap,index,heap[index]); 
                        }
                }
                else if(index==0){
                        
                }
        }
}

void max_heapify(int arr[], int index, int size){
        int largest = index;
        int heap_size1=size;
       // if(largest>heap_size1-1){
         //       return;
       // }
        if(arr[2*index+2]>arr[largest] && 2*index+2<=heap_size1-1){
                largest=2*index+2;
        }
        if(arr[2*index+1]>arr[largest] && 2*index+1<=heap_size1-1){
                largest = 2*index+1;}
        
        if (largest!=index){
                int temp = arr[index];
                arr[index]=arr[largest];
                arr[largest]=temp;
               
                max_heapify(arr,largest,heap_size1);
        }
}





