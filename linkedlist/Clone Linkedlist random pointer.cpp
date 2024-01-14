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
    void insertNode(Node *head)
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            Node *copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = temp->next->next;
        }
    }

    void connectRandom(Node *head)
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            Node *copyNode = temp->next;
            if(temp->random!=NULL)
            {
                copyNode->random = temp->random->next;
            }
            else
            {
                copyNode->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node *connectNext(Node *head)
    {
        Node *dummy = new Node(-1);
        Node *res = dummy;

        Node *temp = head;
        while(temp!=NULL)
        {
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head)
    {
    //     map<Node*,Node*> mp;
    //     Node *temp = head;
    //     while(temp!=NULL)
    //     {
    //         Node *newNode = new Node(temp->val);
    //         mp[temp] = newNode;
    //         temp = temp->next;
    //     }

    //     temp = head;
    //     while(temp!=NULL)
    //     {
    //         Node *copy = mp[temp];
    //         copy->next = mp[temp->next];
    //         copy->random = mp[temp->random];
    //         temp = temp->next;

    //     }

    //    return mp[head];

        insertNode(head);
	    connectRandom(head);
	    Node *ans = connectNext(head);
	    return ans;
    }
};