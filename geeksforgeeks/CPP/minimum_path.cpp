//Recursion:
#include<iostream>
using namespace std;
int fun(int **a,int m,int n,int i,int j){
if(i==m-1 && j==n-1)
return a[m-1][n-1];
if(i<0 || j<0 || i>=m || j>=n)
return 9999;
return a[i][j]+min(fun(a,m,n,i+1,j),fun(a,m,n,i,j+1));
}
int main(){
int i,j,m,n;
cin>>m>>n;
int **a;
a=new int*[m];
for(i=0;i<m;i++)
a[i]=new int[n];
for(i=0;i<m;i++)
for(j=0;j<n;j++)
cin>>a[i][j];
cout<<fun(a,m,n,0,0)<<endl;
return 0;
}



//DP:
#include<iostream>
using namespace std;
int fun(int **a,int m,int n){
int i,j;
int cost[m][n];
for(int i=0;i<m;i++)
{
for(j=0;j<n;j++){
if(i==0 && j==0)
cost[i][j]=a[i][j];
else if(i-1 <0 && j-1 >=0)
{
cost[i][j]=a[i][j]+cost[i][j-1];
}
else if(i-1>=0 && j-1 <0)
{
cost[i][j]=a[i][j]+cost[i-1][j];
}
else if(i-1 >=0 && j-1>=0)
cost[i][j]=a[i][j]+min(cost[i-1][j],cost[i][j-1]);
}
}
return cost[m-1][n-1];
}
int main(){
int i,j,m,n;
cin>>m>>n;
int **a;
a=new int*[m];
for(i=0;i<m;i++)
a[i]=new int[n];
for(i=0;i<m;i++)
for(j=0;j<n;j++)
cin>>a[i][j];
cout<<fun(a,m,n)<<endl;
return 0;
}
