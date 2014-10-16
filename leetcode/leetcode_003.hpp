class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int lastLength = 0;
        int curLength = 0;
        int i = 0;
        while(s[i] != '\0')
        {
            if (s[i] !=' ')
            {
                if (!curLength)
                    lastLength = 0;
                ++curLength;
                ++lastLength;
                ++i;
                continue;
            }
            curLength = 0;
            ++i;
        }
        return lastLength; 
    }
};