//https://www.geeksforgeeks.org/dynamic-programming-subset-sum-problem/
#include <iostream>
using namespace std;
int subsetSum(int S[],int n,int sum)
{
    bool X[n+1][sum+1];
    for(int i=0;i<=n;i++)
        X[i][0]=true;
    for(int i=1;i<=sum;i++)
        X[0][i]=false;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j<S[i-1])
            {
                X[i][j]=X[i-1][j];
            }
            else
            {
                X[i][j]=X[i-1][j]||X[i-1][j-S[i-1]];
            }
        }
    }
    int d;
    for(int j=sum/2;j>=0;j--)
    {
        if(X[n][j])
        {
            d=sum-j*2;
            break;
        }
    }
    return d;
}
int main() {
	//code
	int t,n,sum;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    int S[n],sum=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>S[i];
	        sum+=S[i];
	    }
	    cout<<subsetSum(S,n,sum)<<endl;
	}
	return 0;
}