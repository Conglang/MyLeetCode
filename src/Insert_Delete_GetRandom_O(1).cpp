//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/08
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 1 is the only number in the set, getRandom always return 1.
randomSet.getRandom();
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class RandomizedSet {
private:
    unordered_set<int> numbers;
    unordered_map<int, int> number_index;
    unordered_map<int, int> index_number;
    unordered_set<int> missing_index;
    int index;
    
    int random(int min, int max) //range : [min, max)
    {
       static bool first = true;
       if ( first ) 
       {  
          srand(time(NULL)); //seeding for the first time only!
          first = false;
       }
       return min + rand() % (max - min);
    }
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        index = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (numbers.count(val))
            return false;
        number_index.insert(make_pair(val, index));
        index_number.insert(make_pair(index, val));
        numbers.insert(val);
        ++index;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!numbers.count(val))
            return false;
        missing_index.insert(number_index[val]);
        numbers.erase(val);
        index_number.erase(number_index[val]);
        number_index.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r(-1);
        do {
            r = random(0, index);
        }
        while (r == -1 || missing_index.count(r));
        return index_number[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Insert_Delete_GetRandom_O(1)", "[Arrays]"){
	SECTION("Normal Input"){
		RandomizedSet obj;
		bool a = obj.insert(1);
		bool b = obj.insert(1);
		bool c = obj.insert(2);
		bool d = obj.remove(3);
		bool e = obj.remove(1);
		int f = obj.getRandom();
		REQUIRE(a == true);
		REQUIRE(b == false);
		REQUIRE(c == true);
		REQUIRE(d == false);
		REQUIRE(e == true);
		REQUIRE(f == 2);
	}
}