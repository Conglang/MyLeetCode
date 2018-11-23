//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a nested list of integers represented as a string, implement a parser to deserialize it.
* 
* Each element is either an integer, or a list -- whose elements may also be integers or other lists.
* 
* Note: You may assume that the string is well-formed:
* 
* String is non-empty.
* String does not contain white spaces.
* String contains only digits 0-9, [, - ,, ].
* Example 1:
* 
* Given s = "324",
* 
* You should return a NestedInteger object which contains a single integer 324.
* Example 2:
* 
* Given s = "[123,[456,[789]]]",
* 
* Return a NestedInteger object containing a nested list with 2 elements:
* 
* 1. An integer containing value 123.
* 2. A nested list containing two elements:
*     i.  An integer containing value 456.
*     ii. A nested list with one element:
*          a. An integer containing value 789.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


// 先插入一个[]，防止后续结构内存被释放。所以最后要取列表中的第一个，因为外面多一层[]。
// 遇到[就新增一个区间
// 遇到数字就把整个数字添加到上一个区间里
// 遇到]就说明当前操作的区间完成，拿出来塞到下一层列表里。


/*
class Solution {
public:
    NestedInteger deserialize(string s) {
        auto isnumber = [](char c){ return (c == '-') || isdigit(c); };
        
        stack<NestedInteger> stk;
        stk.push(NestedInteger());
        
        for (auto it = s.begin(); it != s.end();) {
            const char & c = (*it);
            if (isnumber(c)) {
                auto it2 = find_if_not(it, s.end(), isnumber);
                int val = stoi(string(it, it2));
                stk.top().add(NestedInteger(val));
                it = it2;
            }
            else {
                if (c == '[') {
                    stk.push(NestedInteger());
                }
                else if (c == ']') {
                    NestedInteger ni = stk.top();
                    stk.pop();
                    stk.top().add(ni);
                }
                ++it;
            }
        }
        
        NestedInteger result = stk.top().getList().front();
        return result;
    }
};
*/