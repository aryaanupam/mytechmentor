#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int palindromearr[1000000]= {0};

long int queryPalindrome(long int n)
{
    return palindromearr[n];
}

void createInitDB()
{
    std::set<long int> palindromeSet; 
    
    
    for(int i=0;i<10;i++)
    {
        for(int j=0; j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(i==0 && j==0 && k!=0)
                {
                   // cout<<k<<k<<endl;
                     palindromeSet.insert(k);
                    palindromeSet.insert(k*10+k);
                }
                if(i==0 && j!=0)
                {
                 //   cout<<j<<k<<j<<endl;
                    palindromeSet.insert(j*100+k*10+j);
                  //  cout<<j<<k<<k<<j<<endl;
                    palindromeSet.insert(j*1000+k*100+k*10+j);
                }
                if(i!=0)
                {
                   // cout<<i<<j<<k<<j<<i<<endl;
                    palindromeSet.insert(i*10000+j*1000+k*100+j*10+i);
                   // cout<<i<<j<<k<<k<<j<<i<<endl;
                    palindromeSet.insert(i*100000+j*10000+k*1000+k*100+j*10+i);
                }
            }
        }
    }
    
    set<long int>::iterator iter;
   // cout<<palindromeSet.size()<<endl;
    for(iter=palindromeSet.begin(); iter!=palindromeSet.end();)
    {
     //   cout<<(*iter)<<endl;
        int start = *iter;
            ++iter;
        int end = *iter;
        for(long int i=start+1;i<=end;i++)
        {
            palindromearr[i]=end-i;
        }
        
    }
}
int main() {
    createInitDB();
    long int t;
    cin>>t;
    for(long int i=0;i<t;i++)
    {
        long int n;
        cin>>n;
       cout<<queryPalindrome(n)<<endl;
    }
    
    
    return 0;
}
