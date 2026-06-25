class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int a = 0, b = plants.size() - 1;
        int capA = capacityA, capB = capacityB;
        int ans = 0;

        while(a < b) {
            if(plants[a] > capA) {
                ans++;
                capA = capacityA - plants[a];
            } else {
                capA -= plants[a];
            }

            if(plants[b] > capB) {
                ans++;
                capB = capacityB - plants[b];
            } else {
                capB -= plants[b];
            }
            a++;
            b--;
        }

        if(a == b) {
            if(capA >= capB) {
                if(plants[a] > capA) ans++;
            }
            else {
                if(plants[b] > capB) ans++;
            }
        }

        return ans;
    }
};