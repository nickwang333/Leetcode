class TaskManager {
    int total = 0;
    map<int, map<int, int>> tasks;
    unordered_map<int, int> m, m2;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i:tasks){
            add(i[0], i[1], i[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasks[priority][taskId] = 1;
        m[taskId] = priority;
        m2[taskId] = userId;
        total++;
    }
    
    void edit(int taskId, int newPriority) {
        int prev = m[taskId];
        tasks[prev].erase(taskId);
        if(tasks[prev].size() == 0){
            tasks.erase(prev);
        }
        m[taskId] = newPriority;
        tasks[newPriority][taskId] = 1;
    }
    
    void rmv(int taskId) {
        int pri = m[taskId];
        tasks[pri].erase(taskId);
        if(tasks[pri].size() == 0){
            tasks.erase(pri);
        }
        m.erase(taskId);
        m2.erase(taskId);
        total--;
    }
    
    int execTop() {
        if(total == 0){
            return -1;
        }
        auto it = prev(tasks.end());
        auto it2 = prev(it->second.end());
        int ret = m2[it2->first];
        tasks[it->first].erase(it2);
        if(tasks[it->first].size() == 0){
            tasks.erase(it->first);
        }
        total--;
        return ret;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
