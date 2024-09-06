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
    ListNode* merge(ListNode* l1,ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* res;
        if(l1->val<=l2->val){
            res=l1;
            res->next=merge(l1->next,l2);
        }
        else{
            res=l2;
            res->next=merge(l1,l2->next);
        }
        return res;
    }
    ListNode* partition(int start,int end,vector<ListNode*>& list){
        if(start>end) return nullptr;
        if(start==end){
            return list[start];
        }
        int mid=(start+end)/2;
        ListNode* left=partition(start,mid,list);
        ListNode* right=partition(mid+1,end,list);

        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int start=0;
        int n=lists.size();
        int end=n-1;
        return partition(start,end,lists);
    }
};