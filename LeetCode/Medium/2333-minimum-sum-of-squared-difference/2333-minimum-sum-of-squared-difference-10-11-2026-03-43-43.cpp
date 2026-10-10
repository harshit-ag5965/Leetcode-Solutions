using ll=long long;
constexpr int N=1e5+1;
int freq[N];

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        const int n=nums1.size();
        int k=k1+k2;
        int dMax=0;
        ll dSum=0, d2Sum=0;

        for (int i=0; i<n; i++) {
            const int d=abs(nums1[i]-nums2[i]);
            freq[d]++;
            dMax=max(d, dMax);
            dSum+=d;
            d2Sum+=(ll)d*d;
        }

        if (k==0) { memset(freq, 0, sizeof(int)*(dMax+1)); return d2Sum; }
        if (k>=dSum) { memset(freq, 0, sizeof(int)*(dMax+1)); return 0; }

        int cnt=freq[dMax];
        int prvD=dMax;

        for (int d=dMax-1; d>=0 && k>0; d--) {
            if (d>0 && freq[d]==0) continue;

            ll diff=prvD-d, need=cnt*diff;
            freq[prvD]=0;
            if (k>=need) {
                k-=need;
                freq[d]+=cnt;
                cnt=freq[d]; 
                prvD=d;
            }
            else {
                auto [q, r]=div(k, cnt);
                freq[prvD-q]+=(cnt-r);
                freq[prvD-q-1]+=r;
                k=0;
            }
        }

        ll ans=0;
        for (int d=1; d<=dMax; d++) 
            ans+=(ll)freq[d]*d*d;

        memset(freq, 0, sizeof(int)*(prvD+1));
        return ans;
    }
};