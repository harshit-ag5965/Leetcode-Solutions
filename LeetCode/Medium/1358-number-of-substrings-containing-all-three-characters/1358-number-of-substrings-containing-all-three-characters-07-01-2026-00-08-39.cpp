class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int counta=0,countb=0,countc=0;
        int left=0 , res=0;
        for(int right=0;right<n;right++)
        {
            counta+=(s[right]=='a');
            countb+=(s[right]=='b');
            countc+=(s[right]=='c');

            while(counta>0 && countb>0 && countc>0)
            {
                res+=(n-right);
                counta-=(s[left]=='a');
                countb-=(s[left]=='b');
                countc-=(s[left]=='c');
                left++;

            }
        }
        return res;
    }
};