class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> temp;

        for(int x : arr) {
            temp.push_back(x);

            if(x == 0)
                temp.push_back(0);
        }

        for(int i = 0; i < arr.size(); i++) {
            arr[i] = temp[i];
        } 
    }
};