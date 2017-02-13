//我的方法
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int iter1 = 0;
        int iter2 = 0;
        vector<int> result(m + n);
        int t = 0;
        if(m == 0){
                nums1 = nums2;
                return;
        }
        for(int i = 0; i < m+n; i++)
        {
            if(iter1 == m){
                t = nums2[iter2++];
            }
            else if(iter2 == n){
                t = nums1[iter1++];
            }
            else
                nums1[iter1] < nums2[iter2]?t = nums1[iter1++]:t = nums2[iter2++];
            result[i] = t;
        }
        nums1 = result;
        return;
    }
};
//更好的方法
//当有值从nums2移动到nums1时，nums1的其他部分已经在正确的位置了
//因为nums1在m之后的部分是空的，所以不需要多余的vector
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, tar = m + n - 1;
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
    }
};
