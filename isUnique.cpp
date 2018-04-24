//Problem: Algorithm to determine if a string has all unique characters. What if you cannot use additional datastructures? 

//Idea: 
//Tackle this problem in two steps. First step using additional datastrutcure and later by not using additional space 
//1. Use a set, to store the characters in a string - return false if you detect a duplicate character 
//2. Compare each character with every other character in the string. 

//Complexity: 
//1. time = O(n), space = O(n)
//2. time = O(n^2), space = O(1) 

//test cases: 
//1. Null string - return false 
//2. string with duplicates - return false
//3. string without duplicates - return true


//Assumptions:
//1. String has only ASCII characters 
//2. A and a are treated same 

//Note: 
//set treats 'A' and 'a' differently 

#include <iostream> 
#include <unordered_set> 
#include <string.h> 
using namespace std; 


//Approach 2: Without additional datastructure 
bool isUniqueBrute(string s) 
{
	if(s.length() ==0) 
		return false; 
	for(int i =0; i < s.length()-1;i++)
	{
		for(int j = i+1; j < s.length(); j++)
		{
			if(s[i] == s[j]) 
				return false; 
		}
	}
	return true; 
}


//Approach 1: Using Additional data structure - set 
bool isUnique(string s) 
{
	if(s.length() ==0) 
		return false; 
	unordered_set<char> seen; 
	for(int i =0; i < s.length(); i++)
	{
		if(seen.find(s[i]) == seen.end())
		{
			seen.insert(s[i]); 
		}
		else
		{
			return false; 
		}
	}
	return true; 
}


int main()
{
	string s = "Aa"; 
	bool res = isUnique(s); 
	bool res_brute = isUniqueBrute(s); 
	cout<<res<<endl; 
	cout<<res_brute<<endl; 
	return 0; 
}
