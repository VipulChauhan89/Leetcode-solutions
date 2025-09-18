class TaskManager {
public:
    priority_queue<pair<int,int>> tasks;
    unordered_map<int,int> taskPriority;
    unordered_map<int,int> taskOwner;
    TaskManager(vector<vector<int>> &tasks)
    {
        for(auto &i:tasks)
        {
            add(i[0],i[1],i[2]);
        }
    }
    
    void add(int userId,int taskId,int priority)
    {
        tasks.push({priority,taskId});
        taskPriority[taskId]=priority;
        taskOwner[taskId]=userId;
    }
    
    void edit(int taskId,int newPriority)
    {
        tasks.push({newPriority,taskId});
        taskPriority[taskId]=newPriority;
    }
    
    void rmv(int taskId)
    {
        taskPriority[taskId]=-1;
    }
    
    int execTop()
    {
        while(!tasks.empty())
        {
            auto task=tasks.top();
            tasks.pop();
            if(task.first==taskPriority[task.second])
            {
                taskPriority[task.second]=-1;
                return taskOwner[task.second];
            }
        }
        return -1;
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
