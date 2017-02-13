//我的方法
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        vector<int>::iterator iter = timeSeries.begin();
        int prev = *iter++;
        int time = 0;

        while(iter!=timeSeries.end())
        {
            if(*iter - prev > duration){
                time += duration;
                prev = *iter;
            }
            else
                time += *iter - prev;
            prev = *iter++;
        }
        return time + duration;
    }
};
//更好的方法
//如果ts[i]比pe要小，那么就增加ts[i]-ts[i-1]，有效减少了代码行数
class Solution {
public:
    int findPosisonedDuration(vector<int>& ts, int duration) {
        int tp = 0, pe = 0;
        for(int i=0; i<ts.size(); ++i){
            tp += duration - (ts[i] < pe) *(pe - ts[i]);
            pe = ts[i] + duration;
        }
        return tp;
    }
};
