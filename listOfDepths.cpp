Problem: 
List of Depths - Given a binary tree, create a linked list of all nodes at each level/depth ( eg. if you have D levels, you will need D linked lists) 

Idea: 
Use depth first tree traversal. Use separate linked list for each level 

Complexity: 
Time - O(n) {Need to traverse all nodes in the tree} 
Space - O(n) {For thelinked list + Queue} 

Test Cases: 
1. Root is NULL - return empty list of lists 
2. Non empty tree - prints the list in level order 

#include <iostream> 
#include <queue> 
#include <vector> 
using namespace std; 

struct node
{
	int data; 
	node* left; 
	node* right; 
}; 

node* getNewNode(int data) 
{
	node* root = new node; 
	root->data = data; 
	root->left = NULL; 
	root->right = NULL; 
	return root; 
}


node* helper(vector<int> & nums, int start, int end) 
{
	if(start > end) 
		return NULL; 
	else 
	{
		int mid = start + (end -start)/2; 
		node* root = getNewNode(nums[mid]); 
		root->left = helper(nums,start,mid-1); 
		root->right = helper(nums,mid+1,end); 
		return root; 
	}
}
node* arrToBST(vector<int> & nums) 
{
	if(nums.size() == 0) 
		return NULL; 
	return helper(nums,0,nums.size()-1);
}

vector<vector<int>> listOfDepth(node* root) 
{
	vector<vector<int>> res; 
	if(root == NULL) 
		return res; 

	queue<node*> q;
    

	if(root != NULL) 
	{
		q.push(root);  	
	}
	

	while(!q.empty())
	{
		
		int size = q.size();  
		vector<int> inter; 
		
		for(int i =0; i <size; i++)
		{
			node* temp = q.front();
			
			inter.push_back(temp->data);
			
			
			q.pop(); 

			if(temp->left != NULL)
				q.push(temp->left); 
			if(temp->right != NULL) 
				q.push(temp->right); 

		}

		res.push_back(inter);	
	}
	return res; 
}

void printList(vector<vector<int>>& ll) 
{
	if(ll.size() ==0) 
		cout<<"empty list"<<endl; 
	for(int i = 0; i < ll.size(); i++)
	{
		for(int j = 0; j < ll[0].size(); j++)
		{
			cout<<ll[i][j]<<","; 
		}
		cout<<endl; 
	}
}

int main()
{
	vector<int> nums = { 1,2,3,4,5,6,7}; 
	node* root = arrToBST(nums); 
	vector<vector<int>> ll = listOfDepth(root); 
	printList(ll);
	return 0; 
}
