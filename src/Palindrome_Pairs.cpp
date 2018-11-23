//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
* 
* Example 1:
* 
* Input: ["abcd","dcba","lls","s","sssll"]
* Output: [[0,1],[1,0],[3,2],[2,4]] 
* Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
* Example 2:
* 
* Input: ["bat","tab","cat"]
* Output: [[0,1],[1,0]] 
* Explanation: The palindromes are ["battab","tabbat"]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        // 特殊情况
        vector<vector<int>> result;
        if (words.size() < 2) return result;
        // 所有的词反转，存到一个map里，记录反转的词和其index
        unordered_map<string, int> duplicate_parts;
        for (int i = 0; i < words.size(); ++i) {
            string word(words[i]);
            reverse(word.begin(), word.end());
            duplicate_parts.insert(make_pair(word, i));
        }
        // 单独处理有空词的情况，其他词如果本身回文就可以和他成组
        if (duplicate_parts.count("")) {
            for (int i = 0; i < words.size(); ++i) {
                if (words[i] == "") continue;
                if (is_palindrome(words[i])) {
                    result.push_back(vector<int>({duplicate_parts[""], i}));
                    result.push_back(vector<int>({i, duplicate_parts[""]}));
                }
            }
        }
        // 对于所有词，对于每个词，拆分成左右两半。
        // 排除前文已经处理的为空串的情况，如果左或者右等于之前map里的值了，那只要剩余的那一半是回文的就可以。再者就是注意不能和自己结组
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);
                if (left != "" && duplicate_parts.count(left) && is_palindrome(right) && i != duplicate_parts[left]) {
                    result.push_back(vector<int>({i, duplicate_parts[left]}));
                }
                if (right != "" && duplicate_parts.count(right) && is_palindrome(left) && i != duplicate_parts[right]) {
                    result.push_back(vector<int>({duplicate_parts[right], i}));
                }
            }
        }
        return result;
    }
private:
    // 判断一个string是否回文。
    bool is_palindrome(string str) {
        int i(0), j(str.size() - 1);
        while (i <= j) {
            if (str[i++] != str[j--]) {
                return false;
            }
        }
        return true;
    }
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Palindrome_Pairs", "[Detail]"){
	Solution s;
	SECTION("Normal Input"){
        vector<string> input1 = {"abcd","dcba","lls","s","sssll"};
        vector<vector<int>> result1 = {{1,0},{0,1},{3,2},{2,4}};
        auto output1 = s.palindromePairs(input1);
        sort(output1.begin(), output1.end());
        sort(result1.begin(), result1.end());
		REQUIRE(output1 == result1);
	}
}