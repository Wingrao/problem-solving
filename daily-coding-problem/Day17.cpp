#include <bits/stdc++.h> 
using namespace std; 
  
string LongestCommonPath(const vector<string>& input_directory, 
                                                char separator) 
{ 
    vector<string>::const_iterator iter; 
  
    int CommonCharacters = input_directory[0].length(); 
  
    string CommonString = input_directory[0]; 
  
    for (iter = input_directory.begin() + 1; 
        iter != input_directory.end(); iter++) { 
  
        pair<string::const_iterator, string::const_iterator> p = 
                                mismatch(CommonString.begin(), 
                                    CommonString.end(), iter->begin()); 
  
        if ((p.first - CommonString.begin()) < CommonCharacters) { 
  
            CommonCharacters = p.first - CommonString.begin(); 
        } 
  
        if (*iter > CommonString) 
            CommonString = *iter; 
    } 
  
    int found; 
  
    for (int i = CommonCharacters; i >= 0; --i) { 
        if (CommonString[i] == '/') { 
            found = i; 
            break; 
        } 
    } 
  
    return CommonString.substr(0, found); 
} 
  
int main() 
{ 
    int n = 4; 
  
    string input_directory[2] = { 
        "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext", 
        "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext", 
    }; 
  
    vector<string> input(input_directory, 
                        input_directory + n); 
    cout << "Longest Common Path is "
        << LongestCommonPath(input, '/') << "!\n"; 
  
    return 0; 
} 