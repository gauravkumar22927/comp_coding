/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* ptr;
        ListNode* temp;
        vector<int> vec;
        while(list1) {
            vec.push_back(list1->val);
            list1=list1->next;
        }
        while(list2) {
            vec.push_back(list2->val);
            list2=list2->next;
        }
        sort(vec.begin(),vec.end());
        for(int i=0; i<vec.size(); i++) {
            temp = new ListNode();
            temp -> val = vec[i];
            if(i == 0){
                head = temp;
                ptr = head;
            }
            else{
                ptr -> next = temp;
                ptr = ptr->next;
            }
        }
        return head;
    }
};