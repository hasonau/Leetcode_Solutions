// slower than the set version
class Solution {
public:
    int c;
    int r_c;

    int bfs(string s, int startIndex, int keyCount) {
        int directions[4] = {1, -1, c, -c};

        // visited[cell] holds a vector of every key-set (as sorted strings) seen there
        vector<vector<string>> visited(r_c);

        queue<pair<int, set<char>>> q;
        q.emplace(startIndex, set<char>{});

        // mark start as visited (empty key set = "")
        visited[startIndex].push_back("");

        int level = 0;

        while (!q.empty()) {
            int q_size = q.size();
            for (int counter = 0; counter < q_size; counter++) {
                auto [index, keys] = q.front();
                q.pop();

                if ((int)keys.size() == keyCount) return level;

                for (int d = 0; d < 4; d++) {
                    int new_index = index + directions[d];

                    if (new_index < 0 || new_index >= r_c) continue;

                    if ((index % c == (c - 1) && d == 0) ||
                        (index % c == 0 && d == 1))
                        continue;

                    char new_char = s[new_index];
                    if (new_char == '#') continue;

                    set<char> newKeys = keys;  // copy first, mutate the copy

                    if (islower(new_char))
                        newKeys.insert(new_char);

                    if (isupper(new_char) &&
                        newKeys.find(tolower(new_char)) == newKeys.end())
                        continue;

                    // turn the set into a string key for comparison
                    string keyString(newKeys.begin(), newKeys.end());

                    // check if this exact key-combo was already seen at this cell
                    auto &seenHere = visited[new_index];
                    if (find(seenHere.begin(), seenHere.end(), keyString) != seenHere.end())
                        continue;

                    seenHere.push_back(keyString);
                    q.push({new_index, newKeys});
                }
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
            for (char ch : row) {
                if (ch == '@') startIndex = s.size();
                if (islower(ch)) keyCount++;
                s += ch;
            }
        }

        return bfs(s, startIndex, keyCount);
    }
};