#include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std; 

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int startInd = 0;
        int len = words[0].length();
        vector<string> ans;
        int i=1;
        while(i<n){
            if(len+(1+words[i].length())>maxWidth){
                string cur="";
                cur.append(words[startInd]);
                int spaces = i-startInd-1;
                if(spaces>0){
                    int remWidth = maxWidth - len + spaces;
                    int eachSpace = remWidth/spaces;
                    const string eachSp(eachSpace, ' ');
                    int extras = remWidth%spaces;
                    for(int j=startInd+1; j<i; ++j){
                        cur.append(eachSp);
                        if(extras>0){
                            cur.push_back(' ');
                            extras--;
                        }
                        cur.append(words[j]);
                    }
                }
                else{
                    const string eachSp(maxWidth-len, ' ');
                    cur.append(eachSp);
                }
                ans.push_back(cur);
                startInd = i;
                len = words[i].length();
            }
            else{
                len+=(1+words[i].length());
            }
            ++i;
        }
        
        string cur="";
        cur.append(words[startInd]);
        for(int j=startInd+1; j<i; ++j){
            cur.push_back(' ');
            cur.append(words[j]);
        }
        const string eachSp(maxWidth-len, ' ');
        cur.append(eachSp);
        ans.push_back(cur);

        
        
        return ans;
    }
int main() {
	
	vector<string> Words = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"};
	
	cout << fullJustify(Words) << endl;
	
}