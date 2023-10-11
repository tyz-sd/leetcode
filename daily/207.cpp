#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<vector<int> > r_graph(numCourses);
        vector<int> visited(numCourses);
        vector<int> course_prereqs(numCourses);
        int length = prerequisites.size();
        int course_count = 0;
        queue<int> safe_courses;
        if(length == 0)return true;
        for(int i = 0 ; i < length ; i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            r_graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i = 0 ; i < numCourses ; i ++){
            course_prereqs[i] = graph[i].size();
            if(course_prereqs[i] == 0){
                safe_courses.push(i);
                course_count ++;
            }
        }
        while(!safe_courses.empty()){
            int safe_course = safe_courses.front();
            safe_courses.pop();
            for(int i : r_graph[safe_course]){
                course_prereqs[i] --;
                if(course_prereqs[i] == 0) {
                    safe_courses.push(i);
                    course_count ++;
                }   
            }
        }
        if(course_count != numCourses){
            return false;
        }
        return true;
    }
};