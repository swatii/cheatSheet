class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string str;
        if(n==0)
            return str;
        
        int mat[n][n], mlen = 1, ind = 0;
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                mat[i][j] = 0;
                if(i==j)
                    mat[i][j] = 1;
            }
        }
        
        for(int i=0; i<n-1; ++i)
        {
            if(s[i]==s[i+1])
            {
                mat[i][i+1] = 2;
                
                if(2>mlen)
                    {
                        mlen = 2;
                        ind = i;
                    }
            }
        }
        
        for(int k=3; k<=n; ++k)
        {
            for(int i=0; i<n-k+1; ++i)
            {
                int j=i+k-1;
                
                if(mat[i+1][j-1] && s[i]==s[j])
                {
                    mat[i][j] = k;
                    if(k>mlen)
                    {
                        mlen = k;
                        ind = i;
                    }
              
                }
            }
        }
        
        string ans;
        
        for(int i=ind; i<ind+mlen; ++i)
            ans += s[i];
        
        return ans;
    }
};