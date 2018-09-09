#include<iostream>
#include<stack>
#include <algorithm>
using namespace std;

int getMaxProfit(int *profit,int n);
int getMaxProfitInternal(int *villages_profit,int n,int row,int col, int profit, int max_profit=0);

int main()
{
	int n;
	cin>>n;
	int villages_profit[n];
	for(int i=0;i<n;i++)
	{
		cin>>villages_profit[i];
	}
	cout<<"Max profit is : "<<getMaxProfit(villages_profit,n)<<endl;
	return 0;
}

int getMaxProfit(int *villages_profit,int n)
{
	int max_profit=0;
	int max_profit_path=0;
	for(int i=0;i<n;i++)
        {
	//	getMaxProfitInternal(villages_profit,n,i,i,villages_profit[i]);
                max_profit= max(max_profit,getMaxProfitInternal(villages_profit,n,i,i,villages_profit[i]));
        }
	return max_profit;
}

int getMaxProfitInternal(int *villages_profit,int n,int row,int col, int profit, int max_profit)
{
	if(col==n)
	{
		max_profit=max(max_profit,profit);
		return max_profit; 
	}
	if(row==col || (villages_profit[col]%villages_profit[row]!=0))
	{
		return getMaxProfitInternal(villages_profit,n,row,col+1,profit,max_profit);
	}
	else
	{
		profit+=villages_profit[col];
		return getMaxProfitInternal(villages_profit,n,col,col+1,profit,max_profit);	
	}
	return max_profit;
}
