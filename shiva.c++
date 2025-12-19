class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &m : meetings) {
            adj[m[0]].push_back({m[1], m[2]});
            adj[m[1]].push_back({m[0], m[2]});
        }

        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

        dist[0] = 0;
        dist[firstPerson] = 0;

        pq.push({0, 0});
        pq.push({0, firstPerson});

        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();

            if (time > dist[person]) continue;

            for (auto &[next, meetTime] : adj[person]) {
                if (meetTime >= time && meetTime < dist[next]) {
                    dist[next] = meetTime;
                    pq.push({meetTime, next});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dist[i] != INT_MAX) ans.push_back(i);
        }
        return ans;
    }// using dijkrastra algorithm and union find

};
