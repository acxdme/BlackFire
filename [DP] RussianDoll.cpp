class Solution {
public:
    static bool cmp(vector<int> &a , vector<int> &b){
        if(a[0] < b[0]) return true;
        else if(a[0] == b[0]) {
            if(a[1] > b[1]) return true;
            return false;
        }

        return false;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int> res;
        res.push_back(envelopes[0][1]);
        for(int i = 1; i < envelopes.size();i++){
            if(envelopes[i][1] > res[res.size()-1])
            {
                res.push_back(envelopes[i][1]);
            }
            else{
                auto it = lower_bound(res.begin(),res.end(),envelopes[i][1]);
                auto index = it - res.begin();
                res[index] = envelopes[i][1];
            }
        }
        return res.size();
    }
}; 
