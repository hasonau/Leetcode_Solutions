class Solution {
public:
    int c;
    int r_c;

    int bfs(string s, int startIndex, int keyCount) {
        int s_size = s.size();

        int directions[4] = {1, -1, c, -c};

        set<pair<int, set<char>>> visited;

        queue<pair<int, unordered_set<char>>> q;
        q.emplace(startIndex, unordered_set<char>{});

        int level = 0;

        while (!q.empty()) {
            int counter = 0;
            int q_size = q.size();

            while (counter < q_size) {
                auto [index, setState] = q.front();
                q.pop();

                // all keys found
                if (setState.size() == keyCount) return level;

                for (int d=0 ;d < 4 ;d++){
                    int new_index = index + directions[d];


                    //  out of bound check
                    if (new_index < 0 || new_index >= r_c) continue;

                    // Right edge or left edge of the grid
                    if ((index % c == (c - 1) && d == 0) ||
                        (index % c == 0 && d == 1))
                        continue;


                    char new_char = s[new_index];

                    if (new_char == '#')
                        continue;

                    
                    // If it's a key, insert that key to set
                    // if (islower(new_char)) setState.insert(new_char);
                    auto newState = setState;

                    if (islower(new_char)) newState.insert(new_char);
                    
                    // do we have the key for that lock,if not,continue
                    if(isupper(new_char) && newState.find(tolower(new_char)) == newState.end()) continue;

                    // New state, already visited, skip it
                    set<char> orderedState(newState.begin(), newState.end());

                    if (visited.find({new_index, orderedState}) != visited.end())
                        continue;

                    // Now process it
                    visited.insert({new_index, orderedState});
                    q.push({new_index, newState});
                }

                counter++;
            }

            level++;
        }

        return -1;
    }

    int shortestPathAllKeys(vector<string>& grid) {
        int r = grid.size();
        c = grid[0].size();
        r_c = r * c;

        string s = "";
        int startIndex = -1;
        int keyCount = 0;

        for (auto &row : grid) {
            for (char c : row) {
                if (c == '@')
                    startIndex = s.size();

                if (islower(c))
                    keyCount++;

                s += c;
            }
        }

        return bfs(s, startIndex, keyCount);
    }
};
