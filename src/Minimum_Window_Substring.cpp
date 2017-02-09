//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string S and a string T,
* find the minimum window in S which will contain all the characters in T in complexity O(n).
* 
* For example,
* S = "ADOBECODEBANC"
* T = "ABC"
* Minimum window is "BANC".
* 
* Note:
* If there is no such window in S that covers all characters in T, return the empty string "".
* 
* If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
// Ref: https://discuss.leetcode.com/topic/30941/here-is-a-10-line-template-that-can-solve-most-substring-problems/2
// For most substring problem, we are given a string and need to find a substring of it which satisfy some restrictions.
// A general way is to use a hashmap assisted with two pointers.
// The template is given below.
// 
// int findSubstring(string s){
//         vector<int> map(128,0);
//         int counter; // check whether the substring is valid
//         int begin=0, end=0; //two pointers, one point to tail and one  head
//         int d; //the length of substring
// 
//         for() { /* initialize the hash map here */ }
// 
//         while(end<s.size()){
// 
//             if(map[s[end++]]-- ?){  /* modify counter here */ }
// 
//             while(/* counter condition */){ 
//                  
//                  /* update d here if finding minimum*/
// 
//                 //increase begin to make it invalid/valid again
//                 
//                 if(map[s[begin++]]++ ?){ /*modify counter here*/ }
//             }  
// 
//             /* update d here if finding maximum*/
//         }
//         return d;
//   }
// 
// One thing needs to be mentioned is that when asked to find maximum substring,
// we should update maximum after the inner while loop to guarantee that the substring is valid.
// On the other hand, when asked to find minimum substring, we should update minimum inside the inner while loop.

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
		for(int i = 0; i < t.size(); ++i)
		{
			char c = t[i];
			map[c]++;
		}
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while(end < s.size())
		{
            if(map[s[end++]]-- > 0)
				counter--; //in t
            while(counter == 0)
			{ //valid
                if(end - begin < d)
					d = end - (head=begin);
                if(map[s[begin++]]++ == 0)	// ��ȥbegin��Ӱ��
					counter++;  //make it invalid
            }  
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Minimum_Window_Substring", "[Strings]"){
	Solution s;
	SECTION("Invalid Input"){
		REQUIRE(s.minWindow("","") == "");
		REQUIRE(s.minWindow("a","abc") == "");
	}
	SECTION("Normal Input"){
		REQUIRE(s.minWindow("a","a") == "a");
		REQUIRE(s.minWindow("aa","aa") == "aa");
		REQUIRE(s.minWindow("ADOBECODEBANC","ABC") == "BANC");
	}
}
