class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        unordered_map<ListNode*,bool> visited;
        while(head!=NULL) 
        {
            if(visited.find(head)!=visited.end())
            {
                return head;
            } 
            visited[head]=true;
            head=head->next;
        }
        return NULL;
    }
};