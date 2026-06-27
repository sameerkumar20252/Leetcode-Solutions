class Solution {
public:
    int findFinishTime(vector<int>& first, vector<int>& second, vector<int>& firstDuration, vector<int>& secondDuration) {
        int n = first.size();
        int m = second.size();
        int firstFinish = INT_MAX;
        int finish = INT_MAX;

        for(int i = 0; i < n; i++) {
            firstFinish = min(firstFinish, first[i] + firstDuration[i]);
        }

        for(int i = 0; i < m; i++) {
            int time = max(firstFinish, second[i]) + secondDuration[i];
            finish = min(finish, time);
        }

        return finish;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        return min(findFinishTime(landStartTime, waterStartTime, landDuration, waterDuration), findFinishTime(waterStartTime, landStartTime, waterDuration, landDuration));
    }
};