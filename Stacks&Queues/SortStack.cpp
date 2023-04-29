#include <bits/stdc++.h> 

void insertToStack(stack<int> &s,int x) {
     if(s.size() == 0 || s.top()<=x) {
		 s.push(x);
		 return;
	 }

	 int temp = s.top();
	 s.pop();

	 insertToStack(s,x);

	 s.push(temp);


}

void sortStack(stack<int> &stack)
{
	if (stack.size() == 1){
		return ;
	}

	int temp = stack.top();
	stack.pop();

	sortStack(stack);

	insertToStack(stack,temp);
}