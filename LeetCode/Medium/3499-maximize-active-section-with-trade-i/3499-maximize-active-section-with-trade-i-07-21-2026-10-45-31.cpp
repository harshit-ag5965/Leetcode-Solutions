class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
      int prevzeros=0,currzeros=0,totalones=0,maxzeros=0;
      int n=s.size();
      int i=0;

      while(i<n && s[i]=='1')
      {
        totalones++;
        i++;
      } 

      while(i<n && s[i]=='0')
      {
        prevzeros++;
        i++;
      }


      while(i<n)
      {
        while(i<n && s[i]=='1')
        {
            totalones++;
            i++;
        }

        while(i<n && s[i]=='0')
        {
            currzeros++;
            i++;
        }
        if(prevzeros>0 && currzeros>0)
        {
            maxzeros = max(maxzeros,prevzeros+currzeros);
        }
        
        prevzeros=currzeros;
        currzeros=0;
      } 

      return totalones+maxzeros; 
    }
};