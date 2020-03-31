//GeeksforGeeks and techiedelight are used as reference

#include<bits/stdc++.h>
using namespace std;
ifstream fp;
ofstream gp;

struct bstNode {
	int data; 
	bstNode* left;
	bstNode* right;
};
//Minimum value finding function
bstNode * minValueNode(bstNode* node) 
{ 
    bstNode* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 
//Deleting node in a BST
struct bstNode* deleteNode(struct bstNode* root, int key) 
{ 

    if (root == NULL) return root; 

    if (key < root->data){
        root->left = deleteNode(root->left, key); }

    else if (key > root->data) {
        root->right = deleteNode(root->right, key); }

    else
    { 
        if (root->left == NULL) 
        { 
            struct bstNode *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct bstNode *temp = root->left; 
            free(root); 
            return temp; 
        } 

        struct bstNode* temp = minValueNode(root->right); 
  
        root->data = temp->data; 
        root->right = deleteNode(root->right, temp->data); 
    } 
    return root; 
} 

//Function to print the postorder of BST in a file
void postorder(bstNode* root){
	if(root==NULL){	
	return;}
	postorder(root->left);
	postorder(root->right);
	gp<<root->data<<" ";
}

//Function to print the preorder of BST in a file
void preorder(bstNode* root){
	if(root==NULL){	
	return;}
	gp<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

//Function to print the inorder of BST in a file
void inorder(bstNode* root){
	if(root==NULL){	
	return;}
	inorder(root->left);
	gp<<root->data<<" ";
	inorder(root->right);
}

//Function to find minimum in a bst
bstNode* minimum(bstNode *val){
	while((val->right)!=NULL){
		val=val->right;
	}
	return val;
}
//Function to find the maximum value in a BST
bstNode* maximum(bstNode *val){
	while((val->right)!=NULL){
		val=val->right;
	}
	return val;
}

 //Finding the successor of a node
bstNode * successor(bstNode *root, bstNode *n)
{ 
    if( n->right != NULL ) 
        return minimum(n->right); 
    bstNode *succ = NULL; 
    while (root != NULL) 
    { 
        if (n->data < root->data) 
        { 
            succ = root; 
            root = root->left; 
        } 
        else if (n->data > root->data) 
            root = root->right; 
        else
           break; 
    } 
    return succ; 
} 

//Finding the predecessor of a node
void predecessor(bstNode *root, bstNode *&x,int key)
{ 
    if( root->data==key){
	if(root->left)
		x=maximum(root->left);	
	} 
       
    else if(key<root->data){
	predecessor(root->left,x,key);
    }
    else{
    	x=root;
	predecessor(root->right,x,key);
    }

    
} 

// Creating a new node in a heap
bstNode* GetNewNode(int data) {
	bstNode* newNode = new bstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// Inserting data in BST 
bstNode* Insert(bstNode* root,int data) {
	if(root == NULL) { // empty tree
		root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if(data <= root->data) {
		root->left = Insert(root->left,data);
	}
	// else, insert in right subtree. 
	else {
		root->right = Insert(root->right,data);
	}
	return root;
}
//Searching an element in the BST
bstNode* Search(bstNode* root,int data) {
	if(root == NULL) {
		return root;
	}
	else if(root->data == data) {
		return root;
	}
	else if(data <= root->data) {
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
}
int main(int argc, char *argv[]) {
	fp.open(argv[1]);
	gp.open("bst.txt");
	bstNode* root = NULL;  // Creating an empty tree
	bstNode* x = NULL;
	string str;
	int a,b,position;//to store values of instructions
	bool c;//to store values of search command
while(fp>>str){//comparing values to see which command to execute first


	if(str=="insert"){
		fp>>a;
		if(root==NULL){
			root=Insert(root,a);
			gp<<a<<" inserted"<<endl;}
		else{
			Insert(root,a);
			gp<<a<<" inserted"<<endl;	
		}
			
	}
	
	
	else if(str=="inorder"){
		if(root==NULL){
		gp<<endl;}
		else{
		inorder(root);
		position = gp.tellp(); 
	        gp.seekp(position - 1); 
		gp<<endl;}
	}
	
	
	else if(str=="preorder"){
		if(root==NULL){
		gp<<endl;}
		else{
		preorder(root);
		position = gp.tellp(); 
	        gp.seekp(position - 1); 
		gp<<endl;}
	}
	
	
	else if(str=="postorder"){
		if(root==NULL){
		gp<<endl;}
		else{
		postorder(root);
		position = gp.tellp(); 
	        gp.seekp(position - 1); 
		gp<<endl;}
	}
	
	
	else if(str=="search"){
		fp>>a;
		c=Search(root,a);
		if(c){
			gp<<a<<" found"<<endl;
		}
		else{
			gp<<a<<" not found"<<endl;
		}		
	}
	
	
	else if(str=="minimum"){//finding minumum value in a bst
		if (root==NULL){
			gp<<endl;
		}
		else{	x=root;
			while(x->left!=NULL){
				x=x->left;
			}
			gp<<x->data<<endl;
		}
			
	}
	
	
	else if(str=="maximum"){//finding maximum value in a bst
		if (root==NULL){
			gp<<endl;
		}
		else{	x=root;
			while(x->right!=NULL){
				x=x->right;
			}
			gp<<x->data<<endl;
		}
			
	}
	
	
	else if(str=="successor"){
		fp>>a;
		bstNode* n;
		n=Search(root,a);
		if(n!=NULL){
		x=successor(root,n);
		if(x!=NULL){
			gp<<x->data<<endl;
		}
		else{
			gp<<"successor of "<<a<<" does not exist"<<endl;
		}
		}
		else{
			gp<<a<<" does not exist"<<endl;
		}
			
	}
	
	
	else if(str=="predecessor"){
		fp>>a;
		bstNode* n;
		bstNode* ab=NULL;
		n=Search(root,a);
		if(n!=NULL){
		predecessor(root,ab,n->data);
		if(ab!=NULL){
			gp<<ab->data<<endl;
		}
		else{
			gp<<"predecessor of "<<a<<" does not exist"<<endl;
		}
		}
		else{
			gp<<a<<" does not exist"<<endl;
		}
	}
	
	
	else if(str=="delete"){
		fp>>a;
		c=Search(root,a);
		if(!c){
		gp<<a<<" does not exist"<<endl;	}
		else{root=deleteNode(root,a);
		gp<<a<<" deleted"<<endl;
		}
			
	}
}
	fp.close();
	gp.close();
	return 0;
}







