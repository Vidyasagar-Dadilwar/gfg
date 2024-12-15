class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>> pq;
        long double avg = 0;
        for(auto &c: classes){
            avg += 1.0*c[0]/c[1];
            if(c[0] != c[1])
            pq.push({(1.0*c[0]+1) / (1.0*c[1]+1) - (1.0*c[0]) / (1.0*c[1]) , {c[0]+1, c[1]+1}});
        }
        while(!pq.empty() && extraStudents--){
            auto c = pq.top();
            pq.pop();
            double x = c.second.first, y = c.second.second;
            avg += c.first;
            pq.push({(x+1)/(y+1) - x/y, {x+1, y+1}});
        }
        return avg/classes.size();
    }
};