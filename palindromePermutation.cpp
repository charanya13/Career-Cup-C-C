//Problem: 
//PalindromePermutation: Check if a string is a permutation of a palindrome. 

//Approach: 
//1. Use additional data structure to keep track of counts of characters in the string. The string can have atmost 1 character with an odd count. 
//2. Can use bit vector instead of additional data structure to keep track of counts of characters in the string 

//Complexity: 
//1. time = O(n) ,sapce = O(n) 
//2. time = O(n), space = O(1) 

//test cases: 
//1. str is NULL -> return false 
//2. str is permutation of palindrome - return true 
//3. str is not a permutation of palindrome - return false 

//Assumptions: 
//1. string is composed of ASCII characters 
//2. 'A' and 'a' are treated same 
//3. string can have whitesapces- which should not be considered/taken into account. 

#include <iostream> 
#include <string.h> 
#include <unordered_map> 
using namespace std; 

//Approach 1: Use additional data structures 
bool isPalinPerm1(string s)
{
	if(s=="")
		return false; 
	unordered_map<char,int> hmap;
	int count =0; 

	//convert everything to lower case 
	for(int i =0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]); 
	}

	
	for(int i=0; i < s.length(); i++)
	{
		if(s[i] != ' ')
		{
			hmap[s[i]]++;  //handle whitespaces 
		}
		
	}

	for(unordered_map<char,int>::iterator it = hmap.begin(); it != hmap.end(); it++)
	{
		if(it->second %2 != 0) 
		{
			count++; 
		}
	}
	if(count <= 1)
		return true; 
	return false;  
}


//Approach 2: Use bit vector 
int toggleBitvector(int bitvector,int index) 
{
	if(index < 0) 
		return bitvector; 

	int mask = 1 <<index; 
	if((bitvector & mask) == 0) 
		bitvector = bitvector | mask; 
	else
		bitvector =bitvector & (~mask); 

	return bitvector; 
}

bool checkIfOnlyOneBitSet(int bitvector)
{
	if((bitvector & (bitvector-1)) == 0)
		return true; 
	return false; 
}

bool isPalinPerm2(string s)
{
	if(s == "") 
		return false; 
	int bitvector = 0; 
	for(int i=0; i< s.length(); i++)
	{
		if(s[i] != ' ') 
		{
			int x = (int) s[i];   
			bitvector = toggleBitvector(bitvector,x); 
		}

	}
	if(bitvector == 0 || checkIfOnlyOneBitSet(bitvector))
		return true; 
	return false; 
}

int main()
{
	string str = "Aa"; 
	bool res_1 = isPalinPerm1(str); 
	bool res_2 = isPalinPerm2(str);
	cout<<res_1<<endl; 
	cout<<res_2<<endl; 
	return 0;
}
