class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

    vector<int> result;
        if(s.length()<p.length()) return result;
        unordered_map<char,int> target,windows;

        for(char c:p)
        {
            target[c]++;
        }

        int k=p.length();

        for(int i=0;i<k;i++)
        {
            windows[s[i]]++;
        }

        if(windows==target) result.push_back(0);

        for(int i=k;i<s.length();i++)
        {
            windows[s[i]]++;

            windows[s[i-k]]--;

            if(windows[s[i-k]]==0) windows.erase(s[i-k]);

            if(windows==target) result.push_back(i-k+1);


        }

        return result;
    }
};