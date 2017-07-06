/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

   bool checkBST(Node* root, int* n)
   {
       if(root->left){
           if(root->left->data < root->data){
               if(!checkBST(root->left, n))
                    return false;
           }
           else
               return false;
       }
       
       if(root->data > *n){
           *n = root->data;
       }
       else {
           return false;
       }
       
       if(root->right)
       {
           if(root->right->data > root->data)
           {
               if(!checkBST(root->right, n))
                    return false;
           }
           else
               return false;
       }
       
       return true;
   }

   bool checkBST(Node* root) {
       int number = -1;
       return checkBST(root,&number);     
   }
