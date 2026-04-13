class Solution {
    int help(int i,int j,int n,int m,string word1,string word2)
    {
        if(i==n) return (m-j);
        if(j==m) return (n-i);

        if(word1[i]==word2[j])
        {
            return help(i+1,j+1,n,m,word1,word2);
        }
        return 1+min(help(i+1,j,n,m,word1,word2),min(help(i,j+1,n,m,word1,word2),help(i+1,j+1,n,m,word1,word2)));
    }
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();

        return help(0,0,n,m,word1,word2);
    }
};
