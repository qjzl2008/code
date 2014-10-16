// Reverse Integer
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0)
        {
            int lastX = x;
            x = x / 10;
            result = 10 * result + lastX - x * 10;
        }
        return result;
    }
};