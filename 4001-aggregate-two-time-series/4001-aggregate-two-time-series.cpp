class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int m = series1.size(), n = series2.size();
        int i = 0; int j = 0;

        vector<vector<int>> result;

        while(i < m && j < n) {
            if(series1[i][0] == series2[j][0]) {
                int a = series1[i][0];
                int b = series1[i][1] + series2[j][1];
                result.push_back({a, b});
                i++, j++;
            }
            else if(series1[i][0] < series2[j][0]) {
                int a = series1[i][0];
                int b = series1[i][1] + series2[j][1];
                result.push_back({a, b});
                i++;
            }
            else {
                int a = series2[j][0];
                int b = series1[i][1] + series2[j][1];
                result.push_back({a, b});
                j++;
            }
        }

        while(i < m) {
            int a = series1[i][0];
            int b = series1[i][1];
            result.push_back({a, b});
            i++;
        }

        while(j < n) {
            int a = series2[j][0];
            int b = series2[j][1];
            result.push_back({a, b});
            j++;
        }

        return result;
    }
};