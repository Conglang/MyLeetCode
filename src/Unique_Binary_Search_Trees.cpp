﻿//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
* 
* For example,
* Given n = 3, there are a total of 5 unique BST's.
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
*     /     /       \                 \
*    2     1         2                 3
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
/*
*	如果把上例的顺序改一下，就可以看出规律了。
*	1     1         2         3     3
*	 \     \       / \       /     /
*	  3     2     1   3     2     1
*	 /       \             /       \
*	2         3           1         2
*	比如，以1为根的树的个数，等于左子树的个数乘以右子树的个数，左子树是0个元素的树，右子树是2个元素的树。
*	以2为根的树的个数，等于左子树的个数乘以右子树的个数，左子树是1个元素的树，右子树也是1个元素的树。
*	依此类推。
*	当数组为1 , 2 , 3 , ..., n 时，基于以下原则的构建的BST树具有唯一性：
*	以i为根节点的树，其左子树由[1, i-1]构成，其右子树由[i+1, n]构成。
*	定义f(i)为以[1 , i]能产生的Unique Binary Search Tree的数目，则
*	如果数组为空，毫无疑问，只有一种BST，即空树，f(0) = 1。
*	如果数组仅有一个元素1，只有一种BST，单个节点，f(1) = 1。
*	如果数组有两个元素1,2，那么有如下两种可能
*	1      2
*	 \    /
*	  2  1
*	f(2)	= f(0) * f(1),		1 is root;
*			+ f(1) * f(0),		2 is root.
*	再看一看3个元素的数组，可以发现BST的取值方式如下：
*	f(3)	= f(0) * f(2),	1 is root;
*			+ f(1) * f(1),	2 is root;
*			+ f(2) * f(0),	3 is root;
*	所以，由此观察，可以得出f的递推公式为：
*	f(i) = sum(f(k-1) * f(i-k)); k = 1 ~ i
*	至此，问题划归为一维动态规划。
*/
class Solution {
public:
	int numTrees(int n) {
		vector<int> f(n+2, 0);
		f[0] = 1;
		f[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			for (int k = 1; k <= i; ++k)
			{
				f[i] += f[k-1] * f[i-k];
			}
		}
		return f[n];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Unique_Binary_Search_Trees", "[Binary Search Tree]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.numTrees(0) == 1);
		REQUIRE(sln.numTrees(1) == 1);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.numTrees(3) == 5);
	}
}