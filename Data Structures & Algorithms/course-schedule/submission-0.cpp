class Solution {
    bool stuck = false; 
public:
    void dfs(vector<vector<int>>& courses, vector<int>& state, int course) {
        if (courses[course].size() == 0 || state[course] == 2) return;
        if (state[course] == 1) {
            cout << course << endl;
            stuck = true;
            return;
        }

        state[course] = 1;
        for (int i = 0; i < courses[course].size(); i++) {
            dfs(courses, state, courses[course][i]);
            if (stuck) break;
            state[i] = 2;
        }
        
        state[course] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);
        vector<vector<int>> courses(numCourses);

        for (auto course : prerequisites) 
            courses[course[0]].push_back(course[1]);

        for (int i = 0; i < prerequisites.size(); i++) {
            stuck = false;
            dfs(courses, state, prerequisites[i][1]);

            if (stuck) return false;
        }

        return true;
    }
};
