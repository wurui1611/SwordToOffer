#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//鍓戞寚offer 48 鏈€闀夸笉鍚噸澶嶅瓧绗︾殑瀛愬瓧绗︿覆
/*
璇蜂粠瀛楃涓蹭腑鎵惧嚭涓€涓渶闀跨殑涓嶅寘鍚噸澶嶅瓧绗︾殑瀛愬瓧绗︿覆锛岃绠楄鏈€闀垮瓙瀛楃涓茬殑闀垮害銆�

杈撳叆: "abcabcbb"
杈撳嚭: 3 
瑙ｉ噴: 鍥犱负鏃犻噸澶嶅瓧绗︾殑鏈€闀垮瓙涓叉槸 "abc"锛屾墍浠ュ叾闀垮害涓� 3銆�

杈撳叆: "bbbbb"
杈撳嚭: 1
瑙ｉ噴: 鍥犱负鏃犻噸澶嶅瓧绗︾殑鏈€闀垮瓙涓叉槸 "b"锛屾墍浠ュ叾闀垮害涓� 1銆�

杈撳叆: "pwwkew"
杈撳嚭: 3
瑙ｉ噴: 鍥犱负鏃犻噸澶嶅瓧绗︾殑鏈€闀垮瓙涓叉槸聽"wke"锛屾墍浠ュ叾闀垮害涓� 3銆�
聽    璇锋敞鎰忥紝浣犵殑绛旀蹇呴』鏄� 瀛愪覆 鐨勯暱搴︼紝"pwke"聽鏄竴涓瓙搴忓垪锛屼笉鏄瓙涓层€�

*/
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int res = 0, head = 0, tail = 0;

        unordered_map<int, int> nMap;
        while (tail < s.length()){
            if (nMap.find(s[tail]) != nMap.end()) head = max(nMap[s[tail]] + 1, head);

            nMap[s[tail]] = tail;
            tail++;

            res = max(res, tail - head);
        }

        return res;




        int start(0), end(0), len(0), res(0);

        while (end < s.length()) {
            char tmp = s[end];

            for (int i = start; i < end; ++i) {
                if (tmp == s[i]) {
                    start = i + 1;
                    len = end - start;
                    break;

                }
            }

            end++;
            len++;

            res = max(res, len);

        }

        return res;
    }

};