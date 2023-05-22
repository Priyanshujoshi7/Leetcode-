class Solution {
public:
   
    int solve(int index,int pre,vector<vector<int>>&v,vector<vector<int>>&dp,int n,string& s)
    {
       
        if(pre<n && s[pre]=='0')
        {
            return 0;
        }
        if(index==n)
        {
            return 1;
        }

        if(dp[index][pre]!=-1)
        {
            return dp[index][pre];
        }
        long long ans=solve(index+1,pre,v,dp,n,s);
        long long mod=1e9+7;
        int len=index-pre+1;
        int nextSt=index+1;
        int nextEd=index+len;
        if(nextEd<n)
        {
            int x=v[pre][nextSt-pre];
            if(x>=len || s[nextSt+x]>s[pre+x] )
            {
                ans+=solve(nextEd,nextSt,v,dp,n,s);
                ans%=mod;
            }
            else if(++nextEd<n)
            {
               ans+=solve(nextEd,nextSt,v,dp,n,s); 
               ans%=mod;
            }
        }

        return dp[index][pre]=ans;
    }
    vector<int> z_function(string p) {
    int m =  p.size();
    vector<int> z(m);
    z[0]=m;
    for (int i = 1, l = 0, r = 0; i < m; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < m && p[z[i]] == p[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
    }

    int numberOfCombinations(string num) {
      
       vector<vector<int>>v;
        int n=num.size();
        string s=num;
      
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        for(int i=0; i<n; i++)
        {
            string p="";
            for(int j=i; j<n; j++)
            {
                p+=s[j];
            }
            v.push_back(z_function(p));
        }
       return solve(0,0,v,dp,n,s);
    }
};
