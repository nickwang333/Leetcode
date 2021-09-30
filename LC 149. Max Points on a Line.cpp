class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int N = (int) points.size();
        vector<vector<int>> allLineSegments;
  //      sort(points.begin(), points.end());
        if(N<=2)
           return points.size();
        
        for(int i = 0; i<N-1; i++)
        {
            vector<int> seg;
            for(int j = i+1; j<N; j++)
            {
                
                seg.clear();
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                
                seg.push_back(x1); //index: 0
                seg.push_back(y1); //index: 1
                seg.push_back(x2); //index: 2
                seg.push_back(y2); //index: 3
                
                allLineSegments.push_back(seg);
            }
          
            
        }
        
         int maxPoints = 0;
         int curr ;
       
            for(auto l : allLineSegments)
            {
               curr = 0;
                for(auto p : points)
                {
                //For (x,y) to lie on a line passing trough point P1(x1,y1) and P2(x2,y2) : 
                //(y-y1) * (y2-y1) = (x-x1) * (x2-x1).
                //cout<<(p[1]-l[1])*(l[3]-l[1]) <<"\t"<<(p[0]-l[0])*(l[2]-l[0])<<endl;   
            
                 
                 if ((p[1]-l[1])*(l[2]-l[0]) == (p[0]-l[0])*(l[3]-l[1]))
                        {
                           curr++;
                        }
                }
                maxPoints = max(maxPoints, curr);
            }
    return maxPoints;
    }
};
