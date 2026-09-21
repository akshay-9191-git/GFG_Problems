class Solution {
public:
    bool areAnagrams(Node* root1, Node* root2) {
        if (root1 == NULL && root2 == NULL)
            return true;

        if (root1 == NULL || root2 == NULL)
            return false;

        queue<Node*> q1, q2;

        q1.push(root1);
        q2.push(root2);

        while (!q1.empty() && !q2.empty()) {
            int n1 = q1.size();
            int n2 = q2.size();

            if (n1 != n2)
                return false;

            vector<int> a, b;

            for (int i = 0; i < n1; i++) {
                Node* curr = q1.front();
                q1.pop();

                a.push_back(curr->data);

                if (curr->left)
                    q1.push(curr->left);

                if (curr->right)
                    q1.push(curr->right);
            }

            for (int i = 0; i < n2; i++) {
                Node* curr = q2.front();
                q2.pop();

                b.push_back(curr->data);

                if (curr->left)
                    q2.push(curr->left);

                if (curr->right)
                    q2.push(curr->right);
            }

            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            if (a != b)
                return false;
        }

        return q1.empty() && q2.empty();
    }
};