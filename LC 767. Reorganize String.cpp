class Solution {
public:
    string reorganizeString(string S) {
        vector<int> mp(26,0);
        int n = S.size();
        for (char c: S) ++mp[c-'a'];
        vector<pair<int, char>> charCounts;
        for (int i = 0; i < 26; ++i) {
            if (mp[i] > (n+1)/2) return "";
            if (mp[i]) charCounts.push_back({mp[i], i+'a'});
        }
        sort(charCounts.rbegin(), charCounts.rend());
        string strSorted;
        for (auto& p: charCounts)
            strSorted += string(p.first, p.second);
        string ans;
        int j = 0;
        int k = n-1;
        for (int i = 0, j = (n-1)/2+1; i <= (n-1)/2; ++i, ++j) {
            ans += strSorted[i];
            if (j < n) ans += strSorted[j];
        }
        return ans;
    }
};
