class Solution {
public:
    int calcCS(vector<vector<int>> &students, vector<vector<int>> &mentors, int si, int mi){
        int score = 0;
        for(int i = 0; i < students[si].size(); ++i){
            if(students[si][i] == mentors[mi][i])
                score++;
        }
        return score;
    }

    void helper(vector<vector<int>> &students, vector<vector<int>> &mentors, vector<bool> takenMentor, int &res, int index, int score){
        int m = students.size();
        if(index >= m){
            res = max(res, score);
            return;
        }
        int compScore = 0;
        for(int i = 0; i < m; ++i){
            if(takenMentor[i] == false){
                takenMentor[i] = true;
                compScore = calcCS(students,mentors,index,i);
                helper(students, mentors, takenMentor, res, index+1, score + compScore);
                takenMentor[i] = false;
            }
        }
    }
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();
        vector<bool> takenMentor(m,false);
        int res = 0, index = 0, score = 0;
        helper(students, mentors, takenMentor, res, index, score);
        return res;
    }
};