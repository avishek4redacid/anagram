#include <iostream>
using namespace std;
 
	bool isAnagram(string str1,string str2){ //str1 will be the every substring of bigger string and str2 is rthe smaller string
 
		int matched=0;						
		string copyStr2=str2;
		int hashArray[10000]={0};
		for(int i=0;i<str1.length();i++){ 	//use hash to store the count of every char in string1
			if(hashArray[str1[i]] == 0){	
				hashArray[str1[i]]=1;
 
			}
			else
				hashArray[str1[i]]++;
		}
 
		for(int j=0;j<str2.length();j++){ //if the same char present in string2 as well, decrement the count of hash
 
			if(hashArray[str2[j]] == 0){
				return false;
			}
			else if(hashArray[str2[j]] != 0){
				hashArray[str2[j]]--;
			}
 
 
		}
 
		for(int i=0;i<str1.length();i++){	//Now iterate through the hash for every char in string1
			if(hashArray[str1[i]] != 0)		//if the every char in string 1 has count 0 in hash then 
				return false;				//string1 and string2 are anagrams
		}
		return true;
	}
 
int ifAnagramPresent(string big, string small){ //It generates all the substrings of bigger string and call function 'isAnagram' for comparison with smaller string
 
	int count=0;
	for(int i=0;i<big.length()-small.length()+1;i++){
		if(isAnagram(big.substr(i,small.length()),small)==true){ //checking if the substring is angram of the smaller string
			return true;
		}
	}
 
	return false;
}
 
 
int main() {
	// your code goes here
	string big,small;
	cout<<"Enter bigger string \n";
	cin>>big;
	cout<<"Enter smaller string \n";
	cin>>small;
 
	if(ifAnagramPresent(big,small)){
		cout<<"true";
	}
	else cout <<"false";
	return 0;
}