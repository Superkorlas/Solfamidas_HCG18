#include "slice.h"
#include <vector>

using namespace std;


class Solution {

	int rows;

	vector<Slice> slices;

	public:

		Solution( int rows, vector<Slice> slices ) {

			this->rows = rows;
			this->slices = slices;
		}
};