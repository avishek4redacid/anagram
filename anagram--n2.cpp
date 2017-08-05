#include <iostream>
using namespace std;
 
	bool isAnagram(string str1,string str2){ //str1 will be the every substring of bigger string and str2 is rthe smaller string
		int matched=0;						 //we will run double loop to find if they both are anagrams.
		string copyStr2=str2;
		for(int i=0;i<str1.length();i++){
 
			for(int j=0;j<str2.length();j++){
				if(str1[i]==str2[j]){
					str2[j]=' '; //replacing matched characher with empty char ' ' for handling duplicate.
					matched++;
					if(matched==str1.length()){ //when all the char in 1st string has been found in 2nd string
						cout <<"the anagrams are "<<str1<<"::"<< copyStr2 <<"\n";
						return true;
					}
 
					break;
				}	
			}
		}
		return false;
	}
 
int ifAnagramPresent(string big, string small){ //It generates all the substrings of bigger string and call function 'isAnagram' for comparison with smaller string
 
	int count=0;
	for(int i=0;i<big.length()-small.length();i++){
		if(isAnagram(big.substr(i,small.length()),small)){
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
 