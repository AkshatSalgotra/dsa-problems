class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> foods;
        map<int, map<string, int>> tables;

        for (auto &order : orders) {
            string table = order[1];
            string food = order[2];

            int tableNum = stoi(table);

            foods.insert(food);
            tables[tableNum][food]++;
        }

        vector<vector<string>> ans;
        vector<string> header;
        header.push_back("Table");

        for (string food : foods) {
            header.push_back(food);
        }

        ans.push_back(header);

        for (auto &[tableNum, foodMap] : tables) {
            vector<string> row;

            row.push_back(to_string(tableNum));

            for (string food : foods) {
                row.push_back(to_string(foodMap[food]));
            }

            ans.push_back(row);
        }

        return ans;
    }
};