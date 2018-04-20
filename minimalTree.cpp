Problem: 
Minimal Tree - Given a sorted array(increasing order) with unique integer elements, write an algorithm to create binary search tree with minimal height

Idea : 
A tree with minimal height can be formed when the number of nodes in the left subtree is equal to the number of nodes in the right subtree. 
To make the elements on both subtrees equal/more or less equal, the middle element in the array can be cosen as the root of the BST.The left half of the array is used to form the left subtree, while the right half of the array is used to form the right subtree of the BST. 

Complexity: 
1. Time - O(n) {All elements in the araay have to be visited once to form the BST.}
2. Space - O(n) + O(n) {n Recursive calls + n nodes for the Binary Search  Tree} 

Test cases: 
1. Empty array -> returns NULL { nums = {}} 
2. Non empty array (even and odd lengths) {nums = {1,2,3,4,5,6,7} , nums = {1,2,3,4,5,6}}
3. Array with negative numbers {nums={-3,-2,-1,1,2,3}}

#include <iostream> 
#include <vector> 
using namespace std; 

struct node
{
  int data; 
  node* left; 
  node* right; 
}; 

node* getNewNode(int val) 
{
  node* root = new node; //allocate memory for a new node(dynamic memory) 
  root->data = val; 
  root->left = NULL; 
  root->right = NULL; 
  return root; 
}

node* minTree(vector<int>& nums,int start,int end) 
{ 
  if(nums.size() == 0) 
    return NULL;
  if(start > end) 
    return NULL; 
  else
  {
    int mid = start + (end-start)/2; 
    node* root = getNewNode(nums[mid]); 
    root->left = minTree(nums,start,mid-1); 
    root->right = minTree(nums,mid+1,end); 
    return root; 
  } 
}
  
void printTree(node* root) 
{
  if(root == NULL) 
    return; 
  //inorder traversal 
  printTree(root->left); 
  cout<<root->data<<endl;
  printTree(root->right); 

}

int main()
{
  vector<int> nums = {1,2,3,4,5,6,7};    //input arr in sorted order 
  node* root = minTree(nums,0,nums.size()-1); 
  printTree(root); 
  return 0; 
}
  

