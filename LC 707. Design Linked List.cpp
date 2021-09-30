struct Node{
    int val;
    Node* next;
};

class MyLinkedList {
public:
    int n;
    Node* l;
    
    MyLinkedList() {
        n = 0;
        l = NULL;
    }
    
    int get(int index) {
        if(index>=n){
            return -1;
        }
        Node* tmp = l;
        for(int i=0; i<index; i++){
            tmp = tmp->next;
        }
        return tmp->val;
    }
    
    void addAtHead(int val) {
        Node* tmp = new Node();
        tmp->val = val;
        tmp->next = l;
        l = tmp;
        n++;
    }
    
    void addAtTail(int val) {
        Node* tmp = l, *tmp2 = new Node();;
        if(!tmp){
            tmp2->val = val;
            tmp2->next = NULL;
            l = tmp2;
        }
        else{
            while(tmp->next){
                tmp = tmp->next;
            }
            tmp2->val = val;
            tmp2->next = NULL;
            tmp->next = tmp2;
        }
        n++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>n){
            return;
        }
        else if(index==n){
            this->addAtTail(val);
        }
        else if(index==0){
            this->addAtHead(val);
        }
        else{
            n++;
            Node* tmp = l, *tmp2 = new Node();
            for(int i=0; i<index-1; i++){
                tmp = tmp->next;
            }
            tmp2->val = val;
            tmp2->next = tmp->next;
            tmp->next = tmp2;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=n){
            return;
        }
        n--;
        Node* tmp = l;
        if(index==0){
            l = l->next;
            return;
        }
        for(int i=0; i<index-1; i++){
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
