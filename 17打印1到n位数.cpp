#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//鍓戞寚offer 17 鎵撳嵃浠� 1 鍒� 鏈€澶х殑n浣嶆暟
/*
杈撳叆鏁板瓧 n锛屾寜椤哄簭鎵撳嵃鍑轰粠 1 鍒版渶澶х殑 n 浣嶅崄杩涘埗鏁般€傛瘮濡傝緭鍏� 3锛屽垯鎵撳嵃鍑� 1銆�2銆�3 涓€鐩村埌鏈€澶х殑 3 浣嶆暟 999銆�

绀轰緥 1:

杈撳叆: n = 1
杈撳嚭: [1,2,3,4,5,6,7,8,9]
*/
class Solution{
public:
    vector<int> printNumbers(int n){
        long limit = pow(10, n);
        vector<int> res;
        for(int i = 1; i < limit; i++) res.push_back(i);
        return res;

        
    }
};