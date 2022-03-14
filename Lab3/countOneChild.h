#include"d_tnode.h"

template <typename T>
int countOneChild(tnode<T>* root){
	int val=0;
	if(root->left&&root->right)
		return countOneChild(root->left)+countOneChild(root->right);
	if(root->left)
		return 1+countOneChild(root->left);
	if(root->right)
		return 1+countOneChild(root->right);
	return 0;
}
