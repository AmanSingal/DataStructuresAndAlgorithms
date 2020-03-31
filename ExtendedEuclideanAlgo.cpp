#include<bits/stdc++.h>
using namespace std;
template <typename t>
void gcd(t a, t b,t *c ,t *d,t *e){
	t x = 0;
	t y = 1;
	t u = 1;
	t v = 0;
	if( a >=  b){
		while( b !=0){
			 t r = ( a)% ( b);
			t q = floor(a/b);
			t m = x-u*q;
			t n = y-v*q;
			 a =  b;
			 b =  r;
			 x=u;
			 y=v;
			 u=m;
			 v=n;
		}
		*c=a;
		*d=y;
		*e=x;		
		
		}

	
	else{
		while( a!=0){
			t r = ( b)% ( a);
			t q = floor(b/a);
			t m = x-u*q;
			t n = y-v*q;
			 b =  a;
			 a =  r;
			 x=u;
			 y=v;
			 u=m;
			 v=n;
		}
		*c=b;
		*d=x;
		*e=y;		
		}

}

int main(int argc, char* argv[]){
	auto a = atoi(argv[1]);
	auto b = atoi(argv[2]);
	int c,d,e;
	gcd(a,b,&c,&d,&e);
	cout<<*(&c)<<" "<<d<<" "<<e<<endl;

	return 0;
}