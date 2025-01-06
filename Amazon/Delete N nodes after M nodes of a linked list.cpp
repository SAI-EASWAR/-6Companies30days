// } Driver Code Ends
/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        Node* current = head;
        
        while(current){
            
            for(int i=1;i<m && current != nullptr; i++){
                current = current -> next;
            }
            
            if(current == nullptr)
            break;
            
            Node* temp = current -> next;
            
            for(int i = 0;i<n && temp != nullptr; i++){
                Node* nodeToDelete = temp;
                temp = temp->next;
                delete nodeToDelete;
            }
            
            current -> next = temp;
            
            current = temp;
        }
        return head;
    }
};