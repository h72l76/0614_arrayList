// linked list implementation 
// huabo lu 

#include <iostream>

struct Node {
    int data; 
    Node* next; 
    Node() = delete; 
    Node(int data) : data{ data }, next{ nullptr } {} 

};

struct LinkedList {
private: 
    Node* head{};
    Node* tail{};
public: 
    LinkedList() = default; 

    bool empty() const { return head == nullptr; }

    void add_at_head(int n) {
        // create a new node 
        Node* temp = new Node(n); 

        // link temp's next to existing head
        temp->next = head;      // empty-proof 
        
        // update tail if currently empty 
        if (empty()) { tail = temp; }

        // update head
        head = temp; 
    }

    void add_at_tail(int n) {
        // step 1: create new node 
        Node* temp = new Node(n);

        // step 2: if linked list is emtpy, update head
        if (empty()) { head = temp; }

        // step 3: link new node to tail 
        if (tail) { tail->next = temp; }
        
        // step 3 with nullptr bug: 
        //tail->next = temp; 

        // step 4: update tail 
        tail = temp; 
    }

    void traverse() const {
        auto temp = head; 
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;      // V.I.S.
        }
    }

    Node* front() const { return head;  }
    Node* back() const { return tail;  }

    Node* find(int target) const {
        auto temp = head; 
        while (temp) {
            if (temp->data == target) {
                return temp; 
            }
            temp = temp->next;      // V.I.S.
        }

        // after while loop, temp should be nullptr
        return temp; 
    }

    void remove(int target) {
        // case 1: LL is empty 
        if (empty()) return; 

        // case 2: head node to be removed
        if (head && head->data == target) {
            if (tail == head) { tail = nullptr; }
            //delete head; 
            //head = nullptr; 
            auto temp = head; 
            head = head->next; 
            delete temp; 
            return; 
        }

        // case 3: 
        if (tail && tail->data == target) {
            // find the node before tail
            auto temp = tail;
            delete tail; 
            
            // update tail 
            tail = head; 
            while (tail && tail->next != temp) {
                tail = tail->next; 
            }

            if (tail) { tail->next = nullptr; }

            return; 
        }

        // case 4: try to find node in the middle
        // case 5: 


    }

};


int main()
{
    std::cout << "Hello World!\n";

    LinkedList ll; 
    for (auto i : { 30, 20, 10 })
        ll.add_at_head(i); 

    //ll.traverse(); 

    for (auto i : { 100, 200, 300 })
        ll.add_at_tail(i); 

    //ll.traverse();


    std::cout << ll.find(20) << std::endl;
    std::cout << ll.find(21) << std::endl;

    ll.remove(10); 
    ll.remove(300);
    ll.traverse();
    std::cout << std::endl;
    ll.add_at_head(-10);
    ll.add_at_tail(-300);
    ll.traverse();
    std::cout << std::endl;

}

