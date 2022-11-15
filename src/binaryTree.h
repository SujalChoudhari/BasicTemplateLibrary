namespace btl {

	template <typename t_Type>
	struct node {
	public:

		t_Type value;

		node* left;
		node* right;

	public:
		node(t_Type value) :value(value), left(nullptr), right(nullptr) {}
	};
	template <typename t_Type>
	struct binaryTree {
		node* root;
	};
}