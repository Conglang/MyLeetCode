//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement an iterator to flatten a 2d vector.
* 
* For example,
* Given 2d vector =
* 
* [
*   [1,2],
*   [3],
*   [4,5,6]
* ]
*  
* 
* By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6].
* 
* Hint:
* 
* How many variables do you need to keep track?
* Two variables is all you need. Try with x and y.
* Beware of empty rows. It could be the first few rows.
* To write correct code, think about the invariant to maintain. What is it?
* The invariant is x and y must always point to a valid point in the 2d vector. Should you maintain your invariant ahead of time or right when you need it?
* Not sure? Think about how you would implement hasNext(). Which is more complex?
* Common logic in two different places should be refactored into a common method.
* Follow up:
* As an added challenge, try to code it using only iterators in C++ or iterators in Java.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

/*
Ref: http://www.cnblogs.com/grandyang/p/5209621.html
x是指向行的迭代器，y是该行第几个。判断是否有后续就是看当y走到该行尽头，x还有没有可以的新行能走。
*/
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        x = vec2d.begin();
        end = vec2d.end();
        y = 0;
    }

    int next() {
        return (*x)[y++];
    }

    bool hasNext() {
        while (x != end && y == (*x).size()) {
            ++x;
            y = 0;
        }
        return x != end;
    }

    void remove() {
        (*x).erase((*x).begin() + y);
    }

private:
    vector<vector<int>>::iterator x, end;
    int y;
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Flatten_2D_Vector", "[Array]]"){
	SECTION("Normal Input"){
        vector<vector<int>> input1 = {{1,2},{},{},{3},{4,5,6},{}};
        vector<int> result = {1,2,3,4,5,6};
        vector<int> output1;
        Vector2D vec(input1);
        while (vec.hasNext()) {
            output1.push_back(vec.next());
        }
		REQUIRE(output1 == result);
	}
}