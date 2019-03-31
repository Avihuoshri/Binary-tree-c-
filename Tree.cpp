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
		_root = nullptr;
	}

	/*	Tree::~Tree()
		{
			destroy_tree(_root);
		}
	
	*/
		
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
			if(contains(key)){throw std::invalid_argument("insert exception(value already on the tree)");}
		else if(_root!=nullptr){insert_value(key,_root);}
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
				
				if (leaf->left != nullptr)
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
				if (leaf->right != nullptr)
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
			if (node == nullptr)
				return 0;
			else
				return Tree_size(node->left) + 1 + Tree_size(node->right);
		}



		 Node* ariel::Tree::minValueNode(Node* node)
		{
			 Node* current = node;

			/* Loop down to find the leftmost leaf */
			while (current->left != nullptr)
				current = current->left;

			return current;
		}

		bool ariel::Tree::contains(int key)
		{
			return contain_value( _root ,  key);
		}

		bool ariel::Tree::contain_value(Node* node , int key)
		{
			if (node == nullptr)
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


void ariel::Tree::remove(int word)
{
    if(!contains(word))
{
throw std::invalid_argument("no value to remove") ;
}
    if(_root == nullptr)
    {
        cout << "list is empty\n";
        return;
    }
    Node *curr = _root;
   Node *parent = nullptr;

    while(curr != nullptr)
    {
        if(curr->key == word)
            break;
        else
        {
            parent = curr;
            if(word > curr->key)
                curr = curr->right;
            else
                curr = curr->left;
        }
    }
    //LEAF node.
    if(curr->left == nullptr && curr->right == nullptr)
    {
        if (parent == nullptr) {
if(curr==_root){delete _root; _root=nullptr;}{
            delete curr; curr=nullptr;}
        } else {
            if(parent->left == curr) // Right here is an access violation. Which doesn't //make sense.
            {
                parent->left = nullptr;
            }
            else
            {
                parent->right = nullptr;
            }
            delete curr;
        }
    }

    /*
    * Node has a single child LEFT or RIGHT
    */  
    else if((curr->left == nullptr && curr->right != nullptr) || (curr->left != nullptr && curr->right == nullptr))
    {
        if(curr->left == nullptr && curr->right != nullptr)
        {
            if (parent == nullptr) {
                    _root = curr->right;
                    curr->right = nullptr;
                    delete curr;
            } else {
                if(parent->left == curr) //if(parent->left == curr) //says parent is //not intialized
                {
                    parent->left = curr->right;
                    delete curr;
                }
                else
                {
                    parent->right = curr->right;
                    delete curr;
                }
            }
        }

        else
        {
            if (parent == nullptr) {
                    _root = curr->left;
                    curr->left = nullptr;
                    delete curr;
            } else {
                if(parent->left == curr)
                {
                    parent->left = curr->left;
                    delete curr;
                }
                else
                {
                    parent->right = curr->left;
                    delete curr;
                }
            }
        }

    }
    else
    {
        Node* temp=nullptr; 
        if(parent == nullptr)
        {  
            temp = curr->right;
            while(temp->left!=nullptr)
                temp = temp->left;
            if(parent!=nullptr)
                parent->left = curr->right;
            else
                _root = curr->right;
            temp->left = curr->left;
            curr->left = curr->right=nullptr;
            delete curr;

        } else {
            if(parent->left==curr){
                temp = curr->right;
                while(temp->left!=nullptr)
                    temp = temp->left;
                if(parent!=nullptr)
                    parent->left = curr->right;
                else
                    _root = curr->right;
                temp->left = curr->left;
                curr->left = curr->right=nullptr;
                delete curr;
            }
            else if(parent->right==curr)
            {
                temp = curr->left;
                while(temp->right!=nullptr)
                    temp = temp->right;
                parent->right=curr->left;
                temp->right = curr->right;
                curr->left = curr->right=nullptr;
                delete curr;
            }
        }
    }
}
		int ariel::Tree::root()
		{
			if (_root == nullptr)
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
			if (node == nullptr)
			{
				throw std::invalid_argument("ERROE : Left child does not exist!");
				return -1;
			}
			if (key < node->key)
			{
				if (node->left != nullptr)
					getLeftChild(node->left, key);
			}

			else if (key > node->key)
			{
				if (node->right != nullptr)
					getLeftChild(node->right, key);
			}
			else
			{
				if (node->left != nullptr)
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
					return -1;
				}
				if (key < node->key)
				{
					if (node->left != nullptr)
						getRightChild(node->left, key);
				}

				else if (key > node->key)
				{
					if (node->right != nullptr)
						getRightChild(node->right, key);
				}
				else
				{
					if (node->right != nullptr)
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
		throw std::invalid_argument("no value to print");
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
			
		

			


