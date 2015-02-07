//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
//--------------------------------------------------------------------------------------------------------------*/
// My way
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > results;
		if (!numRows)
		{
			return results;
		}
		vector<int> first(1, 1);
		results.push_back(first);

		int current_row(1);
		while(numRows - current_row)
		{
			vector<int> this_row;
			this_row.push_back(1);
			for(vector<int>::iterator it = results[current_row - 1].begin() + 1; it != results[current_row - 1].end(); ++it)
			{
				int this_num = *it + *(it - 1);
				this_row.push_back(this_num);
			}
			this_row.push_back(1);
			results.push_back(this_row);
			++current_row;
		}
		return results;
	}
};