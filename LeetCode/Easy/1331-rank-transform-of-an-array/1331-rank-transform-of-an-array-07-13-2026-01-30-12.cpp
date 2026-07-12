class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> uniqueArr;
        unordered_map<int, int> numRankMap;

        for (int num : arr) {
            if (!numRankMap.count(num)) {
                uniqueArr.push_back(num);
                numRankMap[num] = 0;
            }
        }

        sort(uniqueArr.begin(), uniqueArr.end());

        for (int i = 0; i < uniqueArr.size(); i++) {
            numRankMap[uniqueArr[i]] = i + 1;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = numRankMap[arr[i]];
        }

        return arr;
    }
};