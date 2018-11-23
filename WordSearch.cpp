#define vc vector< char >
#define vcc vector< vc >
#define pb push_back
#define vi vector<int>
#define vvi vector< vi >

bool backtrack(vcc board, string word, int indi, int indj, int n, int m, int ind, vvi vis)
{
    if(indi>=n || indj >=m || indi <0 || indj <0)
        return false;
    int ns = word.length();
    
    if(ind>=ns)
        return true;
    if(word[ind]!=board[indi][indj])
        return false;
    
        else if(word[ind]==board[indi][indj] && vis[indi][indj]==0)
        {
            bool a, b, c, d;
            a = false;
            vis[indi][indj] = true;

            a = backtrack(board, word, indi, indj-1, n, m, ind+1, vis);
            if(!a)
            a = backtrack(board, word, indi, indj+1, n, m, ind+1, vis );
            if(!a)
            a = backtrack(board, word, indi-1, indj, n, m, ind+1, vis);
            if(!a)
            a = backtrack(board, word, indi+1, indj, n, m, ind+1, vis);
            vis[indi][indj] = false;
            return a;
        }
    
 return false;   
}



class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
     
        int n = board.size();
        if(n==0)
            return false;
        int m = board[0].size();
        if(n==1 && m==1)
        {
            if(word.size()!=1 )
                return false;
            
            else if(word[0]==board[0][0])
                return true;
        }
        vvi vis;
        vi v;
        
       for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                v.pb(0);
            }
           vis.pb(v);
           v.clear();
        }
        
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(board[i][j]==word[0])
                {
                    bool val = backtrack(board, word, i, j, n, m, 0, vis);
                    if(val)
                        return true;
                }
            }
        }
        
        return false;
    }
};