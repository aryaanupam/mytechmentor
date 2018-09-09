#include<iostream>
#include<stack>
#include <algorithm>
using namespace std;


int main()
{
	int n;
	int villages_profit[n];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>villages_profit[i];
	}


	stack<int> row_stack;
	stack<int> col_stack;
	stack<int> profit_stack;

	int max_profit=0;
	for(int i=0;i<n;i++)
	{
//		cout<<"Starating with row "<<i<<endl;
		int row,col;
		row=col=i;
		int profit=villages_profit[i];
		while(col < n)
		{
			if(row==col)
			{
				col++;
				continue;
			}
			if(villages_profit[col]%villages_profit[row]==0)
			{
	//			cout<<"Push in stack "<<row<<","<<col<<","<<profit<<endl;
				row_stack.push(row);
				col_stack.push(col);
				profit_stack.push(profit);
				profit+=villages_profit[col];
				row=col;
			}
			col++;
			if(col == n)
			{
	//			cout<<"Path profit is "<<profit<<endl;
	//			cout<<"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"<<endl;
				max_profit = max (max_profit,profit);
				if(!row_stack.empty())
				{
	//				cout<<"Stack is not empty"<<endl;
					row=row_stack.top();
					col=col_stack.top();
					profit=profit_stack.top();
					row_stack.pop();
					col_stack.pop();
					profit_stack.pop();
					col++;
	//				cout<<"pop from stack "<<row<<","<<col<<","<<profit<<endl;
				}
			}
		}
	//	cout<<"---------------------------------------"<<endl;
	}
	cout<<"max profit is "<<max_profit<<endl;
	return 0;
}
