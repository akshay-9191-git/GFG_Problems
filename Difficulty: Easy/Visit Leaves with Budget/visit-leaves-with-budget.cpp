/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  void dfs(Node* root , int level , vector<int>& cost){
      if(!root) return ;
      if(!root->left && !root->right){
          cost.push_back(level);
          return;
      }
      dfs(root->left , level+1 , cost);
      dfs(root->right , level+1 , cost);
  }
    int getCount(Node *root, int k) {
        // code here
        int ans = 0;
         vector<int> cost;
         dfs(root , 1 , cost);
         sort(cost.begin() , cost.end());
         for(int x:cost){
             if( k < x) break;
             k -= x;
             ans++;
         }
         return ans;
    }
};