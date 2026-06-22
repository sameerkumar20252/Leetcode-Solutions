class Solution {
public:
    string ans;
    void A(string& str, int& n, int& k) {
        if(k < 1) return;
        str += "a";
        if(str.length() == n){
            k--;
            if(k == 0) ans = str;
        } else {
            B(str, n, k);
            C(str, n, k);
        }
        str.pop_back();
    }
    void B(string& str, int& n, int& k) {
        if(k < 1) return;
        str += "b";
        if(str.length() == n){
            k--;
            if(k == 0) ans = str;
        } else {
            A(str, n, k);
            C(str, n, k);
        }
        str.pop_back();
    }

    void C(string& str, int& n, int& k) {
        if(k < 1) return;
        str += "c";
        if(str.length() == n){
            k--;
            if(k == 0) ans = str;
        } else {
            A(str, n, k);
            B(str, n, k);
        }
        str.pop_back();
    }

    string getHappyString(int n, int k) {
        int pos = 3 * pow(2, n-1);
        if(k > pos) return "";

        string str = "";
        if(k > 0){
            A(str, n, k);
        }
        if(k > 0) {
            B(str, n, k);
        }
        if(k > 0) {
            C(str, n, k);
        }

        return ans;
    }
};