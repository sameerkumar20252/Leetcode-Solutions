class Solution {
public:
    int totalNumbers(vector<int>& digits) {

        int formed_number = 0;

        unordered_set<int>s;

        for(int i=0;i<digits.size();i++)
        {
            for(int j=0;j<digits.size();j++)
            {
                for(int k=0;k<digits.size();k++)
                {
                    if(i != j && i !=k && j != k && digits[i] != 0) {
                    formed_number = digits[i]*100 + digits[j]*10 + digits[k];

                    if(formed_number % 2 == 0)
                    s.insert(formed_number);
                    }
                }
            }
        }
        
        return s.size();
    }
};