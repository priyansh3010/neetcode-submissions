class Solution {
    vector<int> result;
    unordered_set<int> allCourses;
    bool loop;
public:
    void dfs(vector<vector<int>>& prerequisites, vector<int>& state, vector<vector<int>>& courses, int course) {
        if (state[course] == 2) return;
        if (state[course] == 1) {
            loop = true;
            return;
        }

        state[course] = 1;
        for (int c : courses[course]) {
            dfs(prerequisites, state, courses, c);

            if (loop) return;
        }
        result.push_back(course);
        allCourses.erase(course);
        state[course] = 2;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);
        vector<vector<int>> courses(numCourses);

        for (vector prereq : prerequisites) 
            courses[prereq[0]].push_back(prereq[1]);
        
        for (int i = 0; i < numCourses; i++) 
            allCourses.insert(i);
        
        for (int i = 0; i < prerequisites.size(); i++) {
            loop = false;
            dfs(prerequisites, state, courses, prerequisites[i][1]);

            if (loop) return {};
        }

        for (int course : allCourses) result.push_back(course);

        return result;
    }
};
