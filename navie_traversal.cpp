#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

 int m,n,s;
bool **a=NULL;

stack <int> st;

int minn=0;
 
bool isCompleted(){
for(int i=0;i<m;i++){
for(int j=0;j<n;j++){
if(!a[i][j])
return false;
}
}
return true;
}

void solve(int x,int y){
if(a[x][y]==false){
//cout<<x<<y<<endl;
st.push((x*n)+y);
a[x][y]=true;
if(isCompleted())
{
cout<<"Completed"<<endl;

vector <int> path;

while(!st.empty()){
path.push_back(st.top());
st.pop();
}
vector<int>::reverse_iterator it=path.rbegin();
for(;it!=path.rend();++it)
cout<<(int)((*it)/n)<<((*it)%n)<<endl;
cout<<"W="<<minn<<endl;
exit(0);
}
if((x+1)<=(m-1)){
minn+=4;
solve(x+1,y);
minn-=4;
}
if(((x+1)<=(m-1)) && ((y-1)>=0)){
minn+=8;
solve(x+1,y-1);
minn-=8;
}
if(((x+1)<=(m-1)) && ((y+1)<=(n-1))){
minn+=8;
solve(x+1,y+1);
minn-=8;
}
if((y-1)>=0){
minn+=12;
solve(x,y-1);
minn-=12;
}
if((y+1)<=(n-1)){
minn+=12;
solve(x,y+1);
minn-=12;
}
if(((y-1)>=0)&&((x-1)>=0)){
minn+=16;
solve(x-1,y-1);
minn-=16;
}
if(((y+1)<=n-1)&&((x-1)>=0)){
minn+=16;
solve(x-1,y+1);
minn-=16;
}
if((y-1)>=0){
minn+=20;
solve(x,y-1);
minn-=20;
}
a[x][y]=false;
st.pop();
return;
}
return;
}

int main()
{
  /*int size;
  size=2;
  int matrix[2][2]={0, 12, 20, 16,
                    12, 0, 16, 20,
                    4, 8, 0, 12,
                    8, 4, 12, 0}
  vector<int>arr1;
  arr1.reserve(2)
  vector<int>arr2;
  arr2.reserve(2);
  */
 
  cin>>m>>n>>s;
  int x,y;
  x=(int)(s/n);
  y=s%n;
  a=(bool **) malloc(sizeof(bool *)*m);
  for(int i=0;i<m;i++)
  a[i]=(bool *)malloc(sizeof(bool)*n);
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
{a[i][j]=false;}
solve(x,y);
return 0; 
 }
  
  
 
