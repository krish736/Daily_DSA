// 11-05-2024
// Leetcode
// There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

// We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

//     Every worker in the paid group must be paid at least their minimum wage expectation.
//     In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.

// Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n= quality.size();
        vector<array<double, 2>>  worker(n); 
        for(int i= 0; i < n; i++) {
            worker[i]={(double)wage[i]/quality[i], (double)quality[i]}; 
        }

        sort(worker.begin(), worker.end());

        int quality_sum = 0;

        priority_queue<int> pq; 
        for(int i = 0; i < k; i++) {
            quality_sum += worker[i][1];
            pq.push(worker[i][1]);
        }

        double pay = quality_sum*worker[k-1][0];

        for(int i = k; i < n; i++) {
            pq.push(worker[i][1]);
            quality_sum+=worker[i][1]-pq.top();
            pq.pop();

            pay = min(pay, quality_sum*worker[i][0]);
        }
        return pay;
    }
};