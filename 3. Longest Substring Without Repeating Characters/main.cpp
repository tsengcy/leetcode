class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lenString = s.length();
        std::vector<char> tmp;
        int max = 0;
        std::vector<char>::iterator it;
        for(int i=0; i<lenString; i++)
        {
            it = std::find(tmp.begin(), tmp.end(), s[i]);

            if(it!=tmp.end())
            {
                tmp.erase(tmp.begin(), it+1);
            }
            tmp.push_back(s[i]);
            if(max < tmp.size()){max = tmp.size();}
        }
        return max;
    }
};