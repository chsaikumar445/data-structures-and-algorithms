#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	Node(int val) {
		data = val;
		right = left = NULL;
	}
};

void preorder(Node *node) {
	if (node == NULL) {
		return;
	}
	cout << node -> data << endl;
	preorder(node->left);
	preorder(node->right);
}

void inorder(Node *node) {
	if (node == NULL) {
		return;
	}
	inorder(node->left);
	cout << node->data << endl;
	inorder(node->right);
}

void postorder(Node *node) {
	if (node == NULL) {
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout << node->data << endl;
}

void levelorder(Node *root) {
	vector<vector<int>> ans;
	if (root == NULL) {
		return;
	}
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		// cout << size;
		vector<int> level;
		for (int i = 0; i < size; i++) {
			Node *node = q.front();
			q.pop();
			if (node->left != NULL)q.push(node->left);
			if (node->right != NULL)q.push(node->right);
			level.push_back(node->data);
		}
		ans.push_back(level);
	}
	int k = ans.size();
	for (int i = 0; i < k; i++) {
		int m = ans[i].size();
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << endl;
		}
	}
}

void iterativePreOrder(Node *root) {
	stack<Node*> s;
	s.push(root);
	while (!s.empty()) {
		Node *node = s.top();
		s.pop();
		if (node->right != NULL)s.push(node->right);
		if (node->left != NULL) s.push(node->left);
		cout << node->data << endl;
	}
}

vector<int> iterativeInOrder(Node *root) {
	vector<int> inorder;
	stack<Node*> st;
	Node *node = root;
	while (true) {
		if (node != NULL) {
			st.push(node);
			node = node->left;
		}
		else {
			if (st.empty()) break;
			node = st.top();
			st.pop();
			inorder.push_back(node->data);
			node = node->right;
		}
	}
	return inorder;
}


void preInPost(Node *root) {

	stack<pair<Node*, int>> st;
	st.push({root, 1});
	if (root == NULL) return;
	vector<int> pre;
	vector<int> in;
	vector<int> post;
	while (!st.empty()) {
		auto it = st.top();
		st.pop();

		//part of preorder
		//increment 1 to 2
		//push left node if exists
		if (it.second == 1) {
			pre.push_back(it.first->data);
			it.second++;
			st.push(it);
			if (it.first->left != NULL) {
				st.push({it.first->left, 1});
			}
		}


		//part of Inorder
		//increment 2 to 3
		//push right node if exists
		else if (it.second == 2) {
			in.push_back(it.first->data);
			it.second++;
			st.push(it);
			if (it.first->right != NULL) {
				st.push({it.first->right, 1});
			}
		}

		//dont push
		//part of post order
		else {
			post.push_back(it.first->data);
		}

	}

	cout << "pre order" << endl;
	for (auto it : pre) {
		cout << it << " ";
	}
	cout << endl;
	cout << "in order" << endl;
	for (auto it : in) {
		cout << it << " ";
	}
	cout << endl;

	cout << "post order" << endl;
	for (auto it : post) {
		cout << it << " ";
	}
}

//maxDeapth of a binary tree using level order
int maxDepthLevel(Node *root) {
	if (root == NULL) return 0;
	queue<Node*> q;
	q.push(root);
	int depth = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node *node = q.front();
			q.pop();
			if (node->left != NULL)q.push(node->left);
			if (node->right != NULL)q.push(node->right);
		}
		depth++;
	}
	return depth;
}

//check for balanced binary tree
int maxdepthBalanced(Node *node) {
	if (node == NULL) return 0;
	int lh = maxdepthBalanced(node->left);
	if (lh == -1) return -1;
	int rh = maxdepthBalanced(node->right);
	if (rh == -1)return -1;
	if (abs(lh - rh) > 1) return -1;
	return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
	return maxdepthBalanced(root) != -1;
}


int main() {
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	cout << "preorder" << endl;
	preorder(root);
	cout << "inorder" << endl;
	inorder(root);
	cout << "postorder" << endl;
	postorder(root);
	preInPost(root);
}