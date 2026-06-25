class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for(int ast : asteroids) {
            if(ans.empty() || (ans.back() < 0 && ast < 0)
                || (ans.back() > 0 && ast > 0)
                || (ans.back() < 0 && ast > 0)) {
                ans.push_back(ast);
            }
            else {
                //collision 
                // ans.back() > 0 & ast < 0
                int curr = abs(ast);
                while(!ans.empty() && ans.back() > 0){
                    if(curr > ans.back()) {
                        ans.pop_back();
                    }
                    else if(curr < ans.back()) {
                        break;
                    }
                    else {
                        ast = 10001;
                        ans.pop_back();
                        break;
                    }
                }

                if(ast == 10001) continue;

                if(ans.empty() || ans.back() < 0) {
                    ans.push_back(ast);
                }
            }
        }

        return ans;
    }
};