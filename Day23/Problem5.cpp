// Flood fill
class Solution {
public:
    int r,c,col;
    
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    
    bool vis[55][55];
    
    bool is_valid(int x,int y)
    {
        if(x<0 or x>=r or y<0 or y>=c or vis[x][y])
            return false;
        return true;
            
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        memset(vis,0,sizeof vis);
                
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        r=image.size();
        c=image[0].size();
        col=image[sr][sc];
        while(!q.empty())
        {
            pair<int,int> curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            image[x][y]=newColor;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(is_valid(nx,ny) and image[nx][ny]==col)
                {
                    q.push({x+dx[i],y+dy[i]});
                    vis[x+dx[i]][y+dy[i]]=1;
                }
            }
        }
        return image;
    }
};