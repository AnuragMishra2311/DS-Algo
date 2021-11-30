/*

https://leetcode.com/problems/course-schedule/

Intuition : if there is cycle, then we can't complete all course

Approach : Cycle detection in directed graph. I have used kahn's Algorithm.

*/

class Solution {
public:


    // Function to generate indegree vector
    vector<int> getIndegree(vector<vector<int>> prerequisites, int numCourses)
    {
        vector<int>indegree(numCourses, 0);
        for(vector<int> prerequisite : prerequisites)
        {
            indegree[prerequisite[0]] += 1;
        }
        return indegree;
    }
    
    // Function to make graph using adjacency list
    void makeGraph(vector<vector<int>> prerequisites, vector<int> adj[])
    {
        for(vector<int> prerequisite : prerequisites)
        {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        queue<int>q;
        int count = 0;

        // calculate indegree for each node
        vector<int>indegree = getIndegree(prerequisites, numCourses);
        vector<int> adj[numCourses];
        makeGraph(prerequisites, adj);
        
        // push all the course in q whose indegree is 0.
        for(int course = 0; course < numCourses; course++)
        {
            if(indegree[course] == 0)
            {
                q.push(course);
                count += 1;
            }
        }
        
        while(!q.empty())
        {
            int currentCourse = q.front();
            q.pop();
            for(auto course : adj[currentCourse])
            {
                indegree[course] -= 1;
                if(indegree[course] == 0)
                {
                    q.push(course);
                    count += 1;
                }
            }
        }
        
        return numCourses == count;
        
    }
};