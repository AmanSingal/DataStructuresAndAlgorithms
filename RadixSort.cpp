#include<bits/stdc++.h>
using namespace std;

ifstream fp;
ofstream gp;
int aray[30000];

int raiseToPow(int x, int power)
{
    int result;
    int i;
    result =1;
    for (i=1; i<=power;i++)
    {
        result = result*x;
    }
    return(result);
}
//Function for counting sort the numbers
void countsort(int ar[],int g, int k){//"k" is the last index of the input array,"g" is the digit

//Initializing count array as hemp, output array as temp
	int temp[30000];
	int hemp[10]={0};
	
	for(int i=0;i<=k;i++){
		hemp[(ar[i]/(raiseToPow(10,g-1)))%10]++;//check for expo operator
	}
	for(int i=1;i<=9;i++){
		hemp[i]=hemp[i-1]+hemp[i];
	}
	for (int i = k; i >= 0; i--) 
    	{ 
        temp[hemp[(ar[i]/(raiseToPow(10,g-1)))%10] - 1] = ar[i]; 
        hemp[(ar[i]/(raiseToPow(10,g-1)))%10]--; 
    	} 
        for (int i = 0; i <=k; i++) 
       		 ar[i] = temp[i]; 
}

//Function for radix sorting the array
void radixsort(int ar[],int a, int b){//"a" is the last index of array,"b" is the max digit of numbers in array
	for(int i=1;i<=b;i++)
		countsort(ar,i,a);
}

int main(int argc, char *argv[]){
	fp.open(argv[1]);
	gp.open("radix.txt");
	int a,i=0;
	while(fp>>a){//Storing values in an array
		aray[i]=a;
		i++;
	}
	int j = atoi(argv[2]);//Converting char to int data type
	radixsort(aray,i-1,j);//"i" is the size of the input array,"j" is the max digit of the number
	for(int k=0;k<i;k++){
		if(k<i-1){
		gp<<aray[k]<<endl;}
		else{gp<<aray[k];
		}
	}
fp.close();
gp.close();
return 0;
}
