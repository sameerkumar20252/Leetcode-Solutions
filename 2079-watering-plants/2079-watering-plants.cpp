class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int steps = 0, cap = capacity;

        for(int i = 0; i < plants.size(); i++) {
            if(cap >= plants[i]) {
                cap -= plants[i];
                steps++;
            }
            else {
                steps += (2*i + 1);
                cap = capacity - plants[i];
            }
        }

        return steps;
    }
};