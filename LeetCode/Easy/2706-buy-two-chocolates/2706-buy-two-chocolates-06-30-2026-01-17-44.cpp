class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = 101, min2 = 101;
        for(int i: prices){
            if(i < min1){
                min2 = min1;
                min1 = i;
            }else if(i < min2){
                min2 = i;
            }
        }

        return (min1 + min2 <= money)? money - min1 - min2: money;
    }
};