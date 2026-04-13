class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string,int>mp;
        int n=beginWord.size();
        for(auto x:wordList)
        {
            mp[x]++;
        }
        
       queue<pair<int,string>>q;
       q.push({1,beginWord});
       mp.erase(beginWord);
       while(!q.empty())
       {
              auto it=q.front();
              q.pop();
              int count=it.first;
              string word=it.second;
              if(word==endWord) return count;
              for(int i=0;i<word.size();i++)
              {
                char original=word[i];
                for(char c='a';c<='z';c++)
                {
                    word[i]=c;
                    if(mp.find(word)!=mp.end())
                    {
                        mp.erase(word);
                        q.push({count+1,word});
                    }
                }
                word[i]=original;
              }
       }
       return 0;
    }
};
