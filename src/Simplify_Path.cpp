//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/22
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an absolute path for a file (Unix-style), simplify it.
* 
* For example,
* path = "/home/", => "/home"
* path = "/a/./b/../../c/", => "/c"
* click to show corner cases.
* 
* Corner Cases:
* Did you consider the case where path = "/../"?
* In this case, you should return "/".
* Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
* In this case, you should ignore redundant slashes and return "/home/foo".
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
// ���·���Ļ���ע��.��..�����塣һ��Ҫע�����Ľ�׳�ԡ�
// ����Ϊһ��ջ��ÿ�ΰ�//֮��ķ�.�Ϳ�����ѹ��ջ���������..�͵�����
class Solution {
public:
	string simplifyPath(string path) {
		if (path.empty()) {return "";}
		vector<string> dirs;

		for (auto i = path.begin(); i != path.end();)
		{
			++i;
			auto j = find(i, path.end(), '/');
			auto dir = string(i, j);

			if (!dir.empty() && dir != ".")
			{
				if (dir == "..")
				{
					if (!dirs.empty())
					{
						dirs.pop_back();
					}
				}else
				{
					dirs.push_back(dir);
				}
			}
			i = j;
		}

		stringstream out;
		if (dirs.empty())
		{
			out << "/";
		}else
		{
#if __cplusplus < 201103L
		for(auto it = dirs.begin(); it != dirs.end(); ++it)
		{
			string dir = *it;
#else
			for (auto dir : dirs)
			{
#endif
				out << '/' << dir;
			}
		}
		return out.str();
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Simplify_Path", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.simplifyPath("") == "");
	}
	SECTION("Normal Input"){
		REQUIRE(s.simplifyPath("/home/") == "/home");
		REQUIRE(s.simplifyPath("/a/./b/../../c/") == "/c");
		REQUIRE(s.simplifyPath("/../") == "/");
		REQUIRE(s.simplifyPath("/home//foo/") == "/home/foo");
	}
}