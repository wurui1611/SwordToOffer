#include <iostream>
#include <string>
#include <vector>

using namespace std;

//鍓戞寚offer 19 姝ｅ垯琛ㄨ揪寮忓尮閰� 鍥伴毦  鍔ㄦ€佽鍒� 鍥炴函 
/*
璇峰疄鐜颁竴涓嚱鏁扮敤鏉ュ尮閰嶅寘鍚�'. '鍜�'*'鐨勬鍒欒〃杈惧紡銆�
妯″紡涓殑瀛楃'.'琛ㄧず浠绘剰涓€涓瓧绗︼紝鑰�'*'琛ㄧず瀹冨墠闈㈢殑瀛楃鍙互鍑虹幇浠绘剰娆★紙鍚�0娆★級銆�
鍦ㄦ湰棰樹腑锛屽尮閰嶆槸鎸囧瓧绗︿覆鐨勬墍鏈夊瓧绗﹀尮閰嶆暣涓ā寮忋€�
渚嬪锛屽瓧绗︿覆"aaa"涓庢ā寮�"a.a"鍜�"ab*ac*a"鍖归厤锛屼絾涓�"aa.a"鍜�"ab*a"鍧囦笉鍖归厤銆�

绀轰緥 1:

杈撳叆:
s = "aa"
p = "a"
杈撳嚭: false
瑙ｉ噴: "a" 鏃犳硶鍖归厤 "aa" 鏁翠釜瀛楃涓层€�
绀轰緥 2:

杈撳叆:
s = "aa"
p = "a*"
杈撳嚭: true
瑙ｉ噴:聽鍥犱负 '*' 浠ｈ〃鍙互鍖归厤闆朵釜鎴栧涓墠闈㈢殑閭ｄ竴涓厓绱�, 鍦ㄨ繖閲屽墠闈㈢殑鍏冪礌灏辨槸 'a'銆傚洜姝わ紝瀛楃涓� "aa" 鍙瑙嗕负 'a' 閲嶅浜嗕竴娆°€�
绀轰緥聽3:

杈撳叆:
s = "ab"
p = ".*"
杈撳嚭: true
瑙ｉ噴:聽".*" 琛ㄧず鍙尮閰嶉浂涓垨澶氫釜锛�'*'锛変换鎰忓瓧绗︼紙'.'锛夈€�
绀轰緥 4:

杈撳叆:
s = "aab"
p = "c*a*b"
杈撳嚭: true
瑙ｉ噴:聽鍥犱负 '*' 琛ㄧず闆朵釜鎴栧涓紝杩欓噷 'c' 涓� 0 涓�, 'a' 琚噸澶嶄竴娆°€傚洜姝ゅ彲浠ュ尮閰嶅瓧绗︿覆 "aab"銆�
绀轰緥 5:

杈撳叆:
s = "mississippi"
p = "mis*is*p*."
杈撳嚭: false
s聽鍙兘涓虹┖锛屼笖鍙寘鍚粠聽a-z聽鐨勫皬鍐欏瓧姣嶃€�
p聽鍙兘涓虹┖锛屼笖鍙寘鍚粠聽a-z聽鐨勫皬鍐欏瓧姣嶄互鍙婂瓧绗β�.聽鍜屄�*锛屾棤杩炵画鐨� '*'銆�

鐘舵€�
寰堝鏄撴兂鍒帮紝dp[i][j] 琛ㄧず鐨勭姸鎬佹槸 s 鐨勫墠 i 椤瑰拰 p 鐨勫墠 j 椤规槸鍚﹀尮閰嶃€�

杞Щ鏂圭▼
鐜板湪濡傛灉宸茬煡浜� dp[i-1][j-1] 鐨勭姸鎬侊紝鎴戜滑璇ュ浣曠‘瀹� dp[i][j] 鐨勭姸鎬佸憿锛�
鎴戜滑鍙互鍒嗕笁绉嶆儏鍐佃璁猴紝鍏朵腑锛屽墠涓ょ鎯呭喌鑰冭檻浜嗘墍鏈夎兘鍖归厤鐨勬儏鍐碉紝鍓╀笅鐨勫氨鏄笉鑳藉尮閰嶇殑鎯呭喌浜嗭細

s[i] == p[j] or p[j] == '.'锛氭瘮濡� abb 鍜� abb锛屾垨鑰� abb 鍜� ab. 锛屽緢瀹规槗寰楀埌 dp[i][j] = dp[i-1][j-1] = True銆傚洜涓� ab 鍜� ab 鏄尮閰嶇殑锛屽鏋滃悗闈㈠垎鍒姞涓€涓� b锛屾垨鑰� s 鍔犱竴涓� b 鑰� p 鍔犱竴涓� . 锛屼粛鐒舵槸鍖归厤鐨勩€�

p[j] == '*'锛氬綋 p[j] 涓烘槦鍙锋椂锛岀敱浜庢槦鍙蜂笌鍓嶉潰鐨勫瓧绗︾浉鍏筹紝鍥犳鎴戜滑姣旇緝鏄熷彿鍓嶉潰鐨勫瓧绗� p[j-1] 鍜� s[i] 鐨勫叧绯汇€傛牴鎹槦鍙峰墠闈㈢殑瀛楃涓� s[i] 鏄惁鐩哥瓑锛屽張鍙垎涓轰互涓嬩袱绉嶆儏鍐碉細

p[j-1] != s[i]锛氬鏋滄槦鍙峰墠涓€涓瓧绗﹀尮閰嶄笉涓婏紝鏄熷彿鍖归厤浜� 0 娆★紝搴斿拷鐣ヨ繖涓や釜瀛楃锛岀湅 p[j-2] 鍜� s[i] 鏄惁鍖归厤銆� 杩欐椂 dp[i][j] = dp[i][j-2]銆�

p[j-1] == s[i] or p[j-1] == '.':鏄熷彿鍓嶉潰鐨勫瓧绗﹀彲浠ヤ笌 s[i] 鍖归厤锛岃繖绉嶆儏鍐典笅锛屾槦鍙峰彲鑳藉尮閰嶄簡鍓嶉潰鐨勫瓧绗︾殑 0 涓紝涔熷彲鑳藉尮閰嶄簡鍓嶉潰瀛楃鐨勫涓紝褰撳尮閰� 0 涓椂锛屽 ab 鍜� abb*锛屾垨鑰� ab 鍜� ab.* 锛岃繖鏃舵垜浠渶瑕佸幓鎺� p 涓殑 b* 鎴� .* 鍚庤繘琛屾瘮杈冿紝鍗� dp[i][j] = dp[i][j-2]锛涘綋鍖归厤澶氫釜鏃讹紝濡� abbb 鍜� ab*锛屾垨鑰� abbb 鍜� a.*锛屾垜浠渶瑕佸皢 s[i] 鍓嶉潰鐨勪笌 p 閲嶆柊姣旇緝锛屽嵆 dp[i][j] = dp[i-1][j]

鍏朵粬鎯呭喌锛氫互涓婁袱绉嶆儏鍐垫妸鑳藉尮閰嶇殑閮借€冭檻鍏ㄩ潰浜嗭紝鎵€浠ュ叾浠栨儏鍐典负涓嶅尮閰嶏紝鍗� dp[i][j] = False

灏嗕互涓婅繘琛屽綊绾冲緱鍒扮姸鎬佽浆绉绘柟绋�

*/
class Solution{
public:
    bool isMatch(string s, string t){
        int sl = s.length(), tl = t.length();
        vector<vector<bool>> dp(sl + 1, vector<bool>(tl + 1, false));
        dp[0][0] = true;
        dp[0][1] = false;

        int i = 0, j = 0;
        //t[i] == '*'
        for (int c = 2; c <= tl; c++){
            i = c -1;
            if (t[i] == '*') dp[i][c] = dp[i][c - 2];
        }

        //
        for (int r = 1; r <= sl; r++){
            i = r - 1;
            for (int c = 1; c <= tl; c++){
                j = c - 1;
                if (s[i] == t[j] || t[j] == '*') dp[r][c] = dp[r - 1][c - 1];
                else if (t[j] == '.'){
                    if (s[i] == t[j - 1] || t[j - 1] == '*') dp[r][c] = dp[r - 1][c] || dp[r][c - 2];
                    else  dp[r][c] = dp[r][c - 2];
                }
            }
        }

        return dp[sl][tl];
    }
};

class Solution {
public:
    bool isMatch (string s, string p) {
        int m = s.length() + 1, n = p.length() + 1;

        vector<vector<bool>> dp(m, vector<bool>(n, false));

        dp[0][0] = true;
        for (int j = 2; j < n; j += 2) {
            dp[0][j] = dp[0][j - 2] && p[j - 1] == '*';

        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (p[j - 1] == '*') {
                    if (dp[i][j - 2]) dp[i][j] = true;
                    else if (dp[i - 1][j] && s[i - 1] == p[j - 2]) dp[i][j] = true;
                    else if (dp[i - 1][j] && p[j - 2] == '.') dp[i][j] = true;

                }
                else {
                    if (dp[i - 1][j - 1] && s[i - 1] == p[j - 1]) dp[i][j] == true;
                    else if (dp[i - 1][j - 1] && p[j - 1] == '.') dp[i][j] = true;

                }
            }
        }

        return dp[m - 1][n - 1];
    }
};