//我的方法
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x^y;
        int count = 0;
        do
        {
            count += temp%2;
        }while(temp = temp >>1);
        return count;
    }
};
//更好的方法
//
class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x^y;
        int count = 0;
        while(temp)
        {
          count++;
          temp &= temp-1;
        }
        return count;
    }
};
