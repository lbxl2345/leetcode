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
//temp是x、y异或的结果，其中包含多少个1，就说明有多少位是不同的
//temp &= temp-1；相当于每次从temp中拿走了一个1，因此最后能够拿走几次 就能够统计出1的个数
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
