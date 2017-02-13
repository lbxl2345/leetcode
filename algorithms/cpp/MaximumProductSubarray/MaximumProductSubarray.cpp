#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
class Solution{
public:
  int maxProduct(vector<int>& nums){
  int maxProduct = 0;
  int max = 0, min = 0;
  int premax = 1, premin = 1;
  if(nums.size() == 1) return nums[0];
  for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++){
    max = MAX(*iter, MAX(*iter * premax, *iter * premin));
    min = MIN(*iter, MIN(*iter * premin, *iter * premax));
    cout<<max<<min<<endl;
    maxProduct = MAX(maxProduct, max);
    if(*iter == 0){
        premax = 0;
        premin = 0;
    }
    else{
        premax = max;
        premin = min;
    }
  }
  return maxProduct;
  }
};
