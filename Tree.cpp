#include<iostream>
#include<stdexcept>
#include"Tree.hpp"


using namespace std;

using  ariel::Tree;
using ariel::Node;

/*ariel::Node::~Node(){
	if(left!=nullptr){delete left; left=nullptr;}
	if(right!=nullptr){delete right; right=nullptr;}
}
*/
	ariel::Node::Node():Node(0) {}
	ariel::Node::Node(int num) :key(num),left(NULL),right(NULL) {}
	ariel::Tree::Tree()
	{
		_root = NULL;
	}

	/*	Tree::~Tree()
		{
			destroy_tree(_root);
		}
	
	*/
		
		void ariel::Tree::destroy_tree(Node* leaf)
			{
				if (leaf != NULL)
				{
					destroy_tree(leaf->left);
					destroy_tree(leaf->right);
					delete leaf;
				}
			}
	
		void ariel::Tree::insert(int key)
		{
			if(contains(key)){throw std::invalid_argument("insert exception(value already on the tree)");}
		else if(_root!=NULL){insert_value(key,_root);}
		else{_root=new Node(key);}
		}


		void Tree::insert_value(int key, Node* leaf)
		{
			if(leaf->key==NULL)
			{
				
				 leaf=new Node(key);
			
		 }
			else if (key < leaf->key)
			{						
				
				if (leaf->left != NULL)
				{
					
					insert_value(key, leaf->left);
				}
				else
				{
					
					leaf->left = new Node(key);
					      //Sets the right child of the child node to NULL
				}
			}

			else if (key > leaf->key)
			{
				if (leaf->right != NULL)
				{
					insert_value(key, leaf->right);
				}
				
				else
				{
					leaf->right = new Node(key);
					   //Sets the right child of the child node to NULL
				}

			}

		}
/*Node Btree::search(int key)
		{
			return search__key(key, _root)
		}

		Node* btree::search__key(int key, Node* leaf)
		{
			if (leaf != NULL)
			{
				if (key == leaf->key_value)
					return leaf;

				if (key < leaf->key_value)
					return search(key, leaf->left);

				else
					return search(key, leaff->right);
			}

			else
				return NULL;
		}*/
		


		int ariel::Tree::size()
		{
			return Tree_size(_root);
		}

		int ariel::Tree::Tree_size(Node* node)
		{
			if (node == NULL)
				return 0;
			else
				return Tree_size(node->left) + 1 + Tree_size(node->right);
		}

		 void ariel::Tree::remove( int key )
		{
			if(!contains(key))
				throw std::invalid_argument("The vakue does not exist!");
			else	
			{
				remove_value(_root, key);
			}	
		}

//		 Function to delete node from a BST. Note that root is passed by
 //      reference to the function
void ariel::Tree::remove_value(Node* &root, int key)
{
	// base case: key not found in tree
	if (root == nullptr)
		return;

	// if given key is smaller than the root node, recurse for left subtree
	if (key < root->key)
		remove_value(root->left, key);

	// if given key is bigger than the root node, recurse for right subtree
	else if (key > root->key)
		remove_value(root->right, key);

	// key found
	else
	{
		// Case 1: node to be removed has no children 
		if (root->left == nullptr && root->right == nullptr)
		{
			// deallocate the memory and update root to null
			delete root;
			root = nullptr;
		}

		// Case 2: node to be removed has two children
		else if (root->left && root->right)
		{
			// find its in-order predecessor node
			Node *predecessor = minValueNode(root->right);

			// Copy the value of predecessor to current node
			root->key = predecessor->key;

			// recursively delete the predecessor. Note that the
			// predecessor will have at-most one child (left child)
			remove_value(root->left, predecessor->key);
		}

		// Case 3: node to be deleted has only one child
		else
		{
			// find child node
			Node* child = (root->left)? root->left: root->right;
			Node* curr = root;

			root = child;

			// deallocate the memory
			delete curr;
		}
	}
}


		 Node* ariel::Tree::minValueNode(Node* node)
		{
			 Node* current = node;

			/* Loop down to find the leftmost leaf */
			while (current->left != NULL)
				current = current->left;

			return current;
		}

		bool ariel::Tree::contains(int key)
		{
			return contain_value( _root ,  key);
		}

		bool ariel::Tree::contain_value(Node* node , int key)
		{
			if (node == NULL)
				return false;

			else
			{
				if (key == node->key)
					return true;

				else if (key < node->key)
					return contain_value(node->left, key);

				else
					return contain_value(node->right, key);

			}
		}

		int ariel::Tree::root()
		{
			if (_root == NULL)
			{
				throw std::invalid_argument("ERROE : value NOT found!");
				return  0;
			}

			return _root->key;
		}

		int Tree::left(int key)
		{
			if(!contains(key))
				throw std::invalid_argument("ERROR : Left child does not exist!");

			int ans = getLeftChild(_root, key);
			return ans;
		}

		int  ariel::Tree::getLeftChild(Node* node , int key)
		{
			if (node == NULL)
			{
				throw std::invalid_argument("ERROE : Left child does not exist!");
				return -1;
			}
			if (key < node->key)
			{
				if (node->left != NULL)
					getLeftChild(node->left, key);
			}

			else if (key > node->key)
			{
				if (node->right != NULL)
					getLeftChild(node->right, key);
			}
			else
			{
				if (node->left != NULL)
					return node->left->key;

				else
				{
					throw std::invalid_argument("ERROR : Left child does not exist!");
						return -1;
				}
			}
		}
			int Tree:: right(int key)
			{
				
				int ans = getRightChild(_root, key);
				return ans;
			}

			int ariel::Tree:: getRightChild(Node * node , int key)
			{
				if (node == NULL)
				{
					throw std::invalid_argument("ERROR : Right child does not exist!");	
					return -1;
				}
				if (key < node->key)
				{
					if (node->left != NULL)
						getRightChild(node->left, key);
				}

				else if (key > node->key)
				{
					if (node->right != NULL)
						getRightChild(node->right, key);
				}
				else
				{
					if (node->right != NULL)
						return node->right->key;

					else
					{
						throw std::invalid_argument("ERROE : Right child does not exist!");
						return -1;
					}
				}
			}

			int Tree:: parent(int key)
			{
				return getParent(_root, key);
			}

			int Tree:: getParent(Node * node, int key)
			{
				if(key == node->key)
				{
					throw std::invalid_argument("ERROE : The given number is the root itself that is whY it don't have any parent");
					return -1;
				}	
				else
				{
					if (key == node->left->key)
						return node->key;

					else if (key == node->right->key)
						return node->key;

					else if (key < node->key)
						return getParent(node->left, key);

					else
						return getParent(node->right, key);
				}
				
			}

void ariel::Tree:: print()
{
	if(_root == nullptr)
		throw std::invalid_argument("harta");
	else
		return print(_root);

}
			void ariel::Tree:: print(Node* node)
			{
				
				if (node == nullptr)
					return;
					
			
				print(node->left);

				cout << node->key  << endl ;

				print(node->right);
			}
			
		

			

