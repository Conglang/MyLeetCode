//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/09
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class RandomizedCollection {
private:
    unordered_multiset<int> numbers;
    unordered_multimap<int, int> number_index;
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
    RandomizedCollection() {
        index = 0;
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool contained(numbers.count(val));
        number_index.insert(make_pair(val, index));
        index_number.insert(make_pair(index, val));
        numbers.insert(val);
        ++index;
        return !contained;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!numbers.count(val))
            return false;
        auto pos = number_index.find(val);
        missing_index.insert(pos->second);
        numbers.erase(numbers.find(val));
        index_number.erase(pos->second);
        number_index.erase(pos);
        return true;
    }
    
    /** Get a random element from the collection. */
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
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Insert_Delete_GetRandom_O(1)_Duplicates_allowed", "[Arrays]"){
	SECTION("Normal Input"){
		RandomizedCollection obj;
		bool a = obj.insert(1);
		bool b = obj.remove(2);
		bool c = obj.insert(2);
		bool d = obj.remove(3);
		bool e = obj.remove(1);
		bool f = obj.insert(2);
		int g = obj.getRandom();
		REQUIRE(a == true);
		REQUIRE(b == false);
		REQUIRE(c == true);
		REQUIRE(d == false);
		REQUIRE(e == true);
		REQUIRE(f == false);
		REQUIRE(g == 2);
	}
}