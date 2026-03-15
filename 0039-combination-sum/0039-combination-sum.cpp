class Solution {
public:
    vector<vector<int>> ans;

    void calculate_combination_recursive(int idx, vector<int>& candidates, int target, vector<int>& res){
        if(target == 0){
            ans.push_back(res);
            return;
        }

        if(target < 0) return;

        for(int i = idx; i < candidates.size(); i++){
            res.push_back(candidates[i]);

            calculate_combination_recursive(i, candidates, target - candidates[i], res);

            res.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> res;

        calculate_combination_recursive(0, candidates, target, res);

        return ans;
    }
};