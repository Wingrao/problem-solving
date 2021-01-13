#include <bits/stdc++.h>
using namespace std;
  
 
int lcs( string X, string Y, int m, int n ) 
{ 
    int L[m+1][n+1]; 
    int i, j; 
     
    for (i = 0; i <= m; i++) 
    { 
        for (j = 0; j <= n; j++) 
        { 
        if (i == 0 || j == 0) 
            L[i][j] = 0; 
     
        else if (X[i - 1] == Y[j - 1]) 
            L[i][j] = L[i - 1][j - 1] + 1; 
     
        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]); 
        } 
    } 
     
    return L[m][n]; 
} 
 
void reverseStr(string& str) 
{ 
    int n = str.length(); 
 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
 
int findMinInsertionsLCS(string str, int n) 
{ 
    string rev = ""; 
    rev = str; 
    reverseStr(rev); 
     
    return (n - lcs(str, rev, n, n)); 
} 
 
int main() 
{ 
    string str = "race"; 
    cout << findMinInsertionsLCS(str, str.length()); 
    return 0; 
}