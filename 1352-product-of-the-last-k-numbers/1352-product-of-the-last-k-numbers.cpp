class ProductOfNumbers {
public:
    vector<int> stream;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        stream.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1;
        int i = stream.size() - 1;

        while(k--) {
            if(stream[i] == 0) {
                return 0;
            }
            ans *= stream[i];
            i--;
        }

        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */