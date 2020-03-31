#include<bits/stdc++.h>
using namespace std;
ifstream fp;
ofstream gp;
ofstream gp1;
int amerge[20000],qmerge[20000];

void mergesort(int *,int,int);
void merging(int*,int,int,int);

void quicksort(int*,int,int);
int Partition(int*,int ,int);

int main(int argc, char* argv[]){
       fp.open(argv[1]);
        int k,g=0;
        gp.open("mergesort.txt");
        gp1.open("quicksort.txt");
        if(!fp){
              cout<<"File is not there."<<endl;
        }
        else{
                while(fp>>k){
                        amerge[g]=k;
                        qmerge[g]=k;
                        g++;
                }
               mergesort(amerge,0,g-1);
               
               for(int i=0;i<g;i++){
               if(i==g-1){
                gp<<amerge[i];}
               else{
               gp<<amerge[i]<<endl;}
               }
               
               quicksort(qmerge,0,g-1);
               
               for(int i=0;i<g;i++){
               if(i==g-1){
                gp1<<qmerge[i];}
               else{
               gp1<<qmerge[i]<<endl;}
               }
               
        }
        fp.close();
        gp.close();
        gp1.close();
return 0;
}

void quicksort(int arr[],int lb,int ub){
        if(lb<ub){
              int  loc = Partition(arr,lb,ub);
                quicksort(arr,lb,loc-1);
                quicksort(arr,loc+1,ub);
        }
}

int Partition(int barr[],int lb,int ub){
        int pivot = barr[lb];
        int start = lb;
        int end = ub;
        while(start<end){
                while(barr[start]<=pivot && start<=ub){
                 start++;
                }
                while(barr[end]>pivot && end>=lb){
                 end--;
                }
                if(start<end){
                        swap(barr[start],barr[end]);
                }         
        }
        swap(barr[lb],barr[end]);
        return end;
}

void mergesort(int abmerge[],int lb,int ub){
        if (lb<ub){
        int mid = (lb+ub)/2;
        mergesort(abmerge,lb,mid);
        mergesort(abmerge,mid+1,ub);
        merging(abmerge,lb,mid,ub);
        }
}

void merging(int acmerge[],int lb,int mid,int ub){
        int j=lb,k=0,l=mid+1;
        int bmerge[ub-lb+1];
        while(j<=mid && l<=ub){
                if(acmerge[j]<=acmerge[l]){
                        bmerge[k]=acmerge[j];
                        j++;
                }
                else{
                        bmerge[k]=acmerge[l];
                        l++;
                }
                k++;
        }    
        while(j>mid && l<=ub){
                bmerge[k]=acmerge[l];
                k++;
                l++;
        }      
        while(l>ub && j<=mid){
                bmerge[k]=acmerge[j];
                k++;
                j++;
        }
        for(int y= lb;y<=ub;y++){
                acmerge[y]=bmerge[y-lb];
        } 
}

