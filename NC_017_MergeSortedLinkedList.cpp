#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


 // Definition for singly-linked list.
 class Solution {
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(list1==nullptr && list2 == nullptr){return nullptr;}
        if(list1==nullptr ){return list2;}
        if(list2==nullptr){return list1;}
        ListNode* newHead = nullptr ;
        ListNode* prev = nullptr;
        while(list1!=nullptr && list2!=nullptr){
            ListNode* newNode = new ListNode();
            if(list1->val < list2->val){
                newNode->val = list1->val;
                list1 = list1->next;
            }
            else if(list1->val >= list2->val){
                newNode->val = list2->val;
                list2 = list2->next;
            }

            if(newHead == nullptr){
                newHead = newNode;
                prev = newNode;
            }
            else{
                prev->next = newNode;
                prev = newNode;
            }
            cout << newNode->val;
        }
        if(list1 == nullptr){
            prev->next = list2;
        }
        else{
            prev->next = list1;
        }
        return newHead;
    }
};