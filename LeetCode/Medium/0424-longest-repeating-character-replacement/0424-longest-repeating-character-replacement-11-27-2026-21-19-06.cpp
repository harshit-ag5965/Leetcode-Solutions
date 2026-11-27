class Solution {
public:
    int characterReplacement(string s, int k) {
        int count[26] = {0}; 
        int left=0;
        int n=s.size();
        int right;
        int maxfrequency=0;


        for(right=0;right<n;right++)
        {
            int idx=s[right]-'A';
            count[idx]++;

            maxfrequency=max(maxfrequency,count[idx]);

            if(right-left+1-maxfrequency>k)
            {
                count[s[left]-'A']--;
                left++;
            }
        }

        return right-left;
    }
};