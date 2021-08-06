C++ Solution:

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>result;
        if(root == nullptr)
            return result;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for(int i=0;i<n;i++){
                Node * tempNode = q.front();
                q.pop();
                level.push_back(tempNode->val);
                for(Node * next : tempNode->children)
                    q.push(next);
            }
            result.push_back(level);
        }
        return result;
    }
};
Python Solution:

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        result = []
        if(root == None):
            return result
        q = deque([root])
        while q:
            level = []
            n = len(q)
            for i in range(n):
                tempNode = q.popleft()
                level.append(tempNode.val)
                for nextNode in tempNode.children:
                    q.append(nextNode)    
            result.append(level)
        return result
            
                
        
