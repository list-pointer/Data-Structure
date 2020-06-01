
	stack<Node*> stk;
	stk.push(root);
	stack<int> out;
	while (!stk.empty())
	{
		Node *curr = stk.top();
		stk.pop();

		out.push(curr->data);
		if (curr->left)
			stk.push(curr->left);

		if (curr->right)
			stk.push(curr->right);
	}
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
