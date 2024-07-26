class Solution {
public:
void sd(vector<vector<int>>&matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == -1) {
					matrix[i][j] = 1e9;
				}
				if (i == j) matrix[i][j] = 0;
			}
		}

		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],
					                   matrix[i][k] + matrix[k][j]);
				}
			}
		}




		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == 1e9) {
					matrix[i][j] = -1;
				}
			}
		}
	}

    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
      vector<vector<int>> matrix(n, vector<int>(n, -1));
      for(int i=0;i<n;i++)
      {
        matrix[i][i]=0;
      }
      for(int i=0;i<edges.size();i++)
      {
        matrix[edges[i][0]][edges[i][1]]=edges[i][2];
        matrix[edges[i][1]][edges[i][0]]=edges[i][2];
        
      }
     sd(matrix);
     int ans=-1;
     int prev=INT_MAX;
     for(int i=0;i<n;i++)
     {  int count=0;
        for(int j=0;j<n;j++)
        {   
            if(matrix[i][j]<=dt)
            {
                ++count;
            }
        }
        if(count<=prev)
        {
            ans=i;
            prev=count;
        }
     }
     return ans;
    }
};