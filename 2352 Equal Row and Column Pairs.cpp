// T: O(n squared)
// S: O(n squared)

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {

        // if grid is 1 x 1 there is 1 equal pair of row and column
        if (grid.size() == 1){
            return 1;
        }

        // make a hash map for grid rows 
        unordered_map<string, int> rowMap;
        for (const auto& row : grid){

            // make a key string for each row and insert row in the map
            string rowKey = "";
            for (int i = 0; i < row.size(); i++){
                rowKey += to_string(row[i]) + ",";
            }
            rowMap[rowKey]++;
        }

        // make columns and count equal pairs
        int pairCount = 0;
        for (int j = 0; j < grid.size(); j++){

            // make key string for a column
            string colKey = "";
            for (int i = 0; i < grid.size(); i++){
                colKey += to_string(grid[i][j]) + ",";
            }

            // count number of rows the column has matched
            pairCount += rowMap[colKey];
        }  

        // return number of equal pairs of rows and columns in grid
        return pairCount;  
    }
};
