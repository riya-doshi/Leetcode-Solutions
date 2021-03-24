class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> m;
        
        Node* temp = head;
        
        while(temp){
            Node* copy = new Node(temp->val);
            copy->next = copy->random = NULL;
            
            m[temp] = copy;
            temp=temp->next;
            
        }
        temp = head;
        
        for(auto x=m.begin(); x!=m.end(); x++){
            if(x->first->next){
                x->second->next = m[x->first->next];
            }
            else {
                x->second->next = NULL;
            }
            if(x->first->random){
                x->second->random = m[x->first->random];
            }
            else {
                x->second->random = NULL;
            }
        }
        
        return m[head];
    }
};
