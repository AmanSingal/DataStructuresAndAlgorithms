 #include<bits/stdc++.h>
 using namespace std;

ifstream fp; // defining the input and output file streams
ofstream gp;
ifstream fp1;
string sortString(string str) 
{ 
   sort(str.begin(), str.end()); 
   return str; 
} 
int hash_func(string s, int l){
    int ascii=0;
    for(int i=0;i<s.length();i++){
        ascii+=s[i];
    }
    return ascii%l;
}
int main(int argc, char *argv[]){
    fp.open(argv[1]);
    fp1.open(argv[3]);
    int h=atoi(argv[2]);
    vector <list<string>> hashed(h);

    string abc;//temporary storing a string 
    gp.open("ana.txt");
    string in1;
    while(fp>>in1){
     int val=hash_func(in1,h);
     hashed[val].push_front(in1);
    }
  while(fp1>>in1){
     int val=hash_func(in1,h);
     for(auto i:hashed[val]){
        /*if(in1.length()==i.length()){
            abc=in1;*/
            abc=in1;
            if(sortString(in1)==sortString(i)){
                gp<<i<<" ";
/*            }*/

     }

    }
         gp<<endl;
}

  
  
    fp.close();
    fp1.close();
    gp.close();
return 0;
}
