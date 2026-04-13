class Solution {
    int help(int i,int n,string &s,unordered_map<string,char>&mp)
    {
        if(i==n) return 1;
           int ans=0;
        for(int idx=1;idx<(n-i+1);idx++)
        {
            string temp=s.substr(i,idx);
            if(mp.find(temp)!=mp.end())
            {
             ans+=help(i+idx,n,s,mp);    
            }
        }

        return ans;
    }
public:
    int numDecodings(string s) {
        
        unordered_map<string,char>mp;
        mp["1"]='A';  mp["2"]='B';
        mp["3"]='C';  mp["4"]='D';
        mp["5"]='E';  mp["6"]='F';
        mp["7"]='G';  mp["8"]='H';
        mp["9"]='I';  mp["10"]='J';
        mp["11"]='K';  mp["12"]='L';
        mp["13"]='M';  mp["14"]='N';
        mp["15"]='O';  mp["16"]='P';
        mp["17"]='Q';  mp["18"]='R';
        mp["19"]='S';  mp["20"]='T';
        mp["21"]='U';  mp["22"]='V';
        mp["23"]='W';  mp["24"]='X';
        mp["25"]='Y';
        mp["26"]='Z';
       int n=s.size();
        return help(0,n,s,mp);
    }
};
