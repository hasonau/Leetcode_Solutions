class Solution {
public:

    bool checkCirclesOverlap(int x1, int y1, int r1,
                             int x2, int y2, int r2) {

        long long distanceSquared =
            1LL * (x1 - x2) * (x1 - x2) +
            1LL * (y1 - y2) * (y1 - y2);

        // long long radiusSumSquared =
        //     1LL * (r1 + r2) * (r1 + r2);

        return distanceSquared <= (1LL*r1*r1);
    }

    int dfs(int bombIndex,
            vector<vector<int>>& bombs,
            unordered_map<int, vector<int>>& adj,
            unordered_set<int>& visited) {

        int currentMax = 1;

        visited.insert(bombIndex);

        for (auto overlapBomb : adj[bombIndex]) {

            if (!visited.contains(overlapBomb))
                currentMax += dfs(overlapBomb, bombs, adj, visited);
        }

        return currentMax;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < bombs.size(); i++) {

            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];

            for (int j = 0; j < bombs.size(); j++) {

                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                int r2 = bombs[j][2];

                if (checkCirclesOverlap(x1, y1, r1, x2, y2, r2))
                    adj[i].push_back(j);
            }
        }


        int result = 0;

        for (int i = 0; i < bombs.size(); i++) {
            unordered_set<int> visited;
            if (!visited.contains(i))
                result = max(result, dfs(i, bombs, adj, visited));
        }

        return result;
    }
};