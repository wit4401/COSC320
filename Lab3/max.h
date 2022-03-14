#include"d_tnode.h"

template<typename T>
T max(tnode<T>* root){
	if(root){
		T rootData=root->nodeValue;
		T left=max(root->left);
		T right=max(root->right);
		if(left>rootData)
			rootData=left;
		if(right>rootData)
			rootData=right;
		return rootData;
	}
	else
		return NULL;
}
