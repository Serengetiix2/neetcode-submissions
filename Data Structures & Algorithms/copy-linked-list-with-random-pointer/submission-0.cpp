/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head){
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> copies;
        Node dummy(0);
        Node* dum = &dummy;

        Node* curr = head;
        while(curr != nullptr){
            Node* copy = new Node(curr->val);
            copies[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        dum->next = copies[curr];
        Node* dCur = dum->next;

        while(curr != nullptr){
            if(!(curr->next == nullptr)){
                dCur->next = copies[curr->next];
            }
            if(!(curr->random == nullptr)){
                dCur->random = copies[curr->random];
            }
            curr = curr->next;
            dCur = dCur->next;
        }
        return dum->next;
        
    }
};
