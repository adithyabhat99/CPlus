//https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0/?ref=self
#include <iostream>
using namespace std;
int isSubsetSum(int S[],int n,int sum)
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
    return X[n][sum];
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
	    for(int i=sum/2;i<=sum;i++)
	    {
	        if(isSubsetSum(S,n,i) && isSubsetSum(S,n,sum-i))
	        {
	            int x=(i-(sum-i))>=0?i-(sum-i):(sum-i)-i;
	            cout<<x<<endl;
	            break;
	        }
	    }
	}
	return 0;
}