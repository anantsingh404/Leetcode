class TaskManager {
public:
 using TaskTuple = tuple<int, int, int>;
   struct TaskComparator {
        bool operator()(const TaskTuple& a, const TaskTuple& b) const {
            if (get<0>(a) == get<0>(b))
                return get<1>(a) > get<1>(b); // taskId descending
            return get<0>(a) > get<0>(b);     // priority descending
        }
    };
    set<TaskTuple, TaskComparator> taskSet;
       unordered_map<int,TaskTuple>taskMap; 
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            TaskTuple newTask = make_tuple(priority, taskId, userId);
            taskSet.insert(newTask);
            taskMap[taskId] = newTask;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        TaskTuple newTask = make_tuple(priority, taskId, userId);
        taskSet.insert(newTask);
        taskMap[taskId] = newTask; 
    }
    
    void edit(int taskId, int newPriority) {
          auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            TaskTuple oldTask = it->second;
            taskSet.erase(oldTask);
            TaskTuple updatedTask = make_tuple(newPriority, taskId, get<2>(oldTask));
            taskSet.insert(updatedTask);
            taskMap[taskId] = updatedTask;
        }
    }
    
    void rmv(int taskId) {
        auto it = taskMap.find(taskId);
        if (it != taskMap.end()) {
            taskSet.erase(it->second);
            taskMap.erase(it);
        } 
    }
    
    int execTop() {
         if (taskSet.empty()) return -1;
        auto topTask = *taskSet.begin();
        taskSet.erase(topTask);
        taskMap.erase(get<1>(topTask)); // taskId
        return get<2>(topTask);  
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