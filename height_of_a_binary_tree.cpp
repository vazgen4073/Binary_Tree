#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    void height_helper(Node* root, int& max_height, int counter)
    {
        if (root->left == nullptr && root->right == nullptr) {
            max_height = counter;
        }
        counter++;
        if (root->left != nullptr) {
            height_helper(root->left, max_height, counter);
        }
        if (root->right != nullptr) {
            height_helper(root->right, max_height, counter);
        }
    }
    int height(Node* root)
    {
        int max_height = 0, counter = 0;
        height_helper(root, max_height, counter);
        return max_height;
        // Write your code here.
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    
  	std::cout << height;

    return 0;
}

