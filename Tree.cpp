#include<iostream>
#include<stdexcept>
#include<exception>
#include"Tree.hpp"


using namespace std;

using  ariel::Tree;
using ariel::Node;

/*ariel::Node::~Node(){
	if(left!=nullptr){delete left; left=nullptr;}
	if(right!=nullptr){delete right; right=nullptr;}
}*/

	ariel::Node::Node():Node(0) {}
	ariel::Node::Node(int num) :key(num),left(NULL),right(NULL) {}
	ariel::Tree::Tree()
	{
		_root = nullptr;
	}

		/* Tree::~Tree()
		{
			destroy_tree(_root);
		}*/
	
	
		
		void ariel::Tree::destroy_tree(Node* leaf)
			{
				if (leaf != nullptr)
				{
					destroy_tree(leaf->left);
					destroy_tree(leaf->right);
					delete leaf;
				}
			}
	
		void ariel::Tree::insert(int key)
		{
		if(contains(key))
		{
		  throw std::invalid_argument("insert exception(value already on the 				tree)");
		}
		else if(_root!=nullptr)		
		{
			insert_value(key,_root);
		}
		else{_root=new Node(key);}
		}


		void Tree::insert_value(int key, Node* leaf)
		{
			if(leaf==nullptr)
			{
				
				 leaf=new Node(key);
				 leaf->left = leaf->right = nullptr ;
			
			}
			else if (key < leaf->key)
			{						
				
				if (leaf->left != nullptr)
				{
					
					insert_value(key, leaf->left);
				}
				else
				{
					
					leaf->left = new Node(key);
					      //Sets the right child of the node to NULL
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
			int treeSize = 0 ;

			if (node == NULL)
				return 0;
			else
			{
				return Tree_size(node->left) + 1 + Tree_size(node->right);
				
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

		 void ariel::Tree::remove( int key )
		{
			cout<<"SSTAAAM"<<endl ;
			if(!contains(key))
			{
				cout<<"in if(!contains(key) )"<<endl;
												cout<<"AFTER THROW"<<endl;
				try
				{
					{throw std::invalid_argument("The value does not exist!");}
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}

					

				
			}
			else	
			{
				cout<<"in remove.else"<<endl ;
				remove_value(_root, key);
			}	
		}

//		 Function to delete node from a BST. Note that root is passed by
 //      reference to the function
void ariel::Tree::remove_value(Node* &root, int key)
{
	// base case: key not found in tree
	if (root == nullptr)
	{
		cout<<"tree is empty/n" ;
		return;
	}
	

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
			remove_value(root->right, predecessor->key);

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
				throw std::invalid_argument("ERROR : Left child does not exist!"); 					return -1;
			}
			else if (key < node->key)
			{
				if (node->left != NULL)
					return getLeftChild(node->left, key);
				else
					throw std::invalid_argument("ERROR : Could not find the key in left son");
			}

			else if (key > node->key)
			{
				if (node->right != NULL)
					return getLeftChild(node->right, key);
				else
					throw std::invalid_argument("ERROR : Could not find the key in right son");
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
				if (node == nullptr)
				{
					throw std::invalid_argument("ERROR : Right child does not exist!");	
					
				}
				else if (key < node->key)
				{
					if (node->left != nullptr)
						return getRightChild(node->left, key);
					
					else
					{
					throw std::invalid_argument("ERROR : Could not find the key in left son");

					}
			
				}

				else if (key > node->key)
				{
					if (node->right != nullptr)
						return getRightChild(node->right, key);

					else
					{
					throw std::invalid_argument("ERROR : Could not find the key in right son");

					}				
				}
				else 
				{
					if (node->right != NULL)
						return node->right->key;

					else 
					{
						throw std::invalid_argument("ERROE : Right child does not exist!");

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
	/*		
		
int main()
{
ariel::Tree t ;
	int treeSize =  t.size();
cout<<"tree size is : "<<treeSize<<endl ;
	t.insert(10);
	t.insert(4);
	t.insert(20);
	t.insert(30);
	t.insert(25);
	t.insert(2);
	t.insert(5);
	t.print() ;
	cout<<"TESTING SIZE()"<<endl ;
	treeSize =  t.size();
	cout<<"tree size is : "<<treeSize<<endl<<endl ;

	cout<<"TESTING CONTAINS() - TRUE "<<endl ;
	treeSize =  t.contains(5);
	cout<<"contains answer is : "<<treeSize<<endl<<endl ;

	cout<<"TESTING CONTAINS() - FALSE "<<endl ;
	treeSize =  t.contains(100);
	cout<<"contains answer is : "<<treeSize<<endl<<endl ;

	cout<<"TESTING REMOVE()  "<<endl ;
	t.remove(100);
	treeSize =  t.contains(100);
	cout<<"contains answer is : "<<treeSize<<endl<<endl ;

	cout<<"CONTINUE  "<<endl ;
	


}

*/		
