//Problem: 
//Given two strings, check if one is a permutation of the other. 


//Approach: 
//1. Sort the two strings, compare and check if they are equal - return true if equal 
//2. Use adiitional data structure to keep track of the counts of characters in each string - return true if counts are same 


//Complexity: 
//1. time = O( n log n), space = O(1) 
//2. time = O(n + m) , space = O(n + m) 

//test cases: 
//1. str1 = null, str2 == null - return true 
//2. str1 = null, str2 != null - return false
//3. str1 != null, str2 = null - return false
//4. str1 and str2 are permutation - return true 
//5. str1 and str2 are not permutation - return false 

//Assumptions: 
//1. strings are composed of ASCII characters 

#include <iostream> 
#include <string.h> 
#include <unordered_map> 
using namespace std; 

//Approach 1: Using sort 
bool isPermSort(string str1,string str2) 
{
	if(str1 == "" && str2 == "") 
		return true; 
	if(str1 == "" && str2 !=  "") 
		return false;
	if(str1 != "" && str2 == "") 
		return false; 
	sort(str1.begin(),str1.end()); 
	sort(str2.begin(),str2.end()); 
	if(str1 == str2) 
		return true; 
	return false; 
}

//Approach 2: Using additional datastructure 
bool isPerm(string str1,string str2)
{
	if(str1 == "" && str2 == "") 
		return true; 
	if(str1 == "" && str2 !=  "") 
		return false;
	if(str1 != "" && str2 == "") 
		return false; 
	unordered_map<char,int> hmap; 
	for(int i =0; i < str1.length(); i++)
	{
		hmap[str1[i]]++; 
	}
	for(int i =0; i < str2.length(); i++)
	{
		hmap[str2[i]]--; 
	}

	for(unordered_map<char,int>::iterator it = hmap.begin(); it != hmap.end(); it++)
	{
		if(it->second != 0) 
			return false; 
	}
	return true; 

}

int main()
{
	string str1 = "leet"; 
	string str2 = "leet"; 
	bool res_sort = isPermSort(str1,str2); 
	bool res = isPerm(str1,str2); 
	cout<<res_sort<<endl; 
	cout<<res<<endl; 
	return 0; 
}
