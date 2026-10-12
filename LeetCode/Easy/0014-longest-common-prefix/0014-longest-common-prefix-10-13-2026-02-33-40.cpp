class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix=strs[0];
        int prefixlen=prefix.length();

        for(int i=1;i<strs.size();i++)
        {
            int j=0;
            while(j<prefixlen && prefix[j]==strs[i][j] && j<strs[i].length())
            {
                j++;
            }

            prefixlen=j;
            if(prefixlen==0) return "";
        }

        return prefix.substr(0,prefixlen);
    }
};