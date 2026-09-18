/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
  void inorder(Node* root , vector<int>& ans){
      if(root != NULL){
          inorder(root->left , ans);
          ans.push_back(root->data);
          inorder(root->right , ans);
      }
  }
    int absDiff(Node *root) {
        // code here
        vector<int> ans;
        inorder(root , ans);
        int mini = INT_MAX;
        for(int i=1;i<ans.size();i++){
            int a = ans[i] - ans[i-1];
            mini = min(mini , a);
        }
        return mini;
        
    }
};