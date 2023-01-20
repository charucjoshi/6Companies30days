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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> seq;
        ListNode* curr = head;
        while(curr != NULL){
            seq.push_back(curr->val);
            curr = curr->next;
        }
        vector<pair<int,int>> pairs;
        for(int i = 0; i < seq.size(); ++i){
            bool flag = false;
            int j,sum = 0;
            for(j = i; j < seq.size(); ++j){
                sum += seq[j];
                if(sum == 0){
                    pairs.push_back({i,j});
                    flag = true;
                    break;
                }
            }
            if(flag){
                i = j;
            }
        }
        vector<int> lat;
        for(int i = 0; i < seq.size(); ++i){
            bool flag = true;
            for(auto j : pairs){
                if(i >= j.first && i <= j.second){flag=false;break;}
            }
            if(flag)
                lat.push_back(seq[i]);
        }
        for(auto i : lat) cout << i << " ";
        if(lat.size() == 0) return nullptr;
        ListNode *first = new ListNode();
        ListNode *newHead = new ListNode(lat[0]);
        for(int i = 0; i < lat.size()-1; ++i)
        {
            first->val = lat[i];
            if(i == 0) newHead = first;
    
            ListNode *sec = new ListNode(lat[i+1]);
    
            first->next = sec;
            sec->next = nullptr;
            first = sec;
        }
        return newHead;
    }
};