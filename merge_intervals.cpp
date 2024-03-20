// 20-03-2024
// Leetcode
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end()); 

        vector<int> merged={intervals[0][0],intervals[0][1]}; 
        
        for(int i=1;i<intervals.size();i++){
          if(intervals[i][0]>merged[1]){ 
            ans.push_back(merged);
            merged={intervals[i][0],intervals[i][1]};
          }else{ 
            merged[0]=min(merged[0],intervals[i][0]);
            merged[1]=max(merged[1],intervals[i][1]);
          }
        }

        ans.push_back(merged); 
        return ans;