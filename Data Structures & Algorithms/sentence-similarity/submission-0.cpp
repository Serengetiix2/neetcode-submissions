


class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1,
                             vector<string>& sentence2,
                             vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;

        unordered_map<string, unordered_set<string>> sim;
        for (auto& p : similarPairs) {
            sim[p[0]].insert(p[1]);
            sim[p[1]].insert(p[0]);   // relation is symmetric
        }

        for (size_t i = 0; i < sentence1.size(); ++i) {
            const string& a = sentence1[i];
            const string& b = sentence2[i];
            if (a == b) continue;                 // word similar to itself
            auto it = sim.find(a);
            if (it == sim.end() || !it->second.count(b)) return false;
        }
        return true;
    }
};