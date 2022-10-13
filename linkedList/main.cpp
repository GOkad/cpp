#include <iostream>

struct Node {
	uint16_t value;
	Node* next_node;
};
struct LinkedList {
	Node* head;
};

// Without list 
void print_list(Node* head_node);
void append_node(Node* head_node, uint16_t value);
Node* get_node_by_value(Node* head_node, uint16_t value);
void remove_node(Node* head_node, Node* node);
void main_without_list();

// With list 
void append_node(LinkedList* list, uint16_t value);
void print_list(LinkedList* list);
Node* get_node_by_value(LinkedList* list, uint16_t value);
void remove_node(LinkedList* list, Node* node);

int main(int argc, char* argv) {

	LinkedList* list = new LinkedList();

	append_node(list, 1);
	append_node(list, 2);
	append_node(list, 3);
	append_node(list, 4);

	print_list(list);

	Node* node = get_node_by_value(list, 2);
	remove_node(list, node);
	print_list(list);

	node = get_node_by_value(list, 1);
	remove_node(list, node);
	print_list(list);

	main_without_list();
	return 0;
}

/**
* Append New node to the list
* 
* @param LinkedList* list - Linked list
* @param uint16_t value - Value for the new node
*/
void append_node(LinkedList* list, uint16_t value) {
	Node* current_node = list->head;
	
	Node* new_node = new Node();
	new_node->value = value;
	new_node->next_node = nullptr;


	if (!current_node) {
		list->head = new_node;
		return;
	}

	// Get last node
	while (current_node->next_node) {
		current_node = current_node->next_node;
	}
	current_node->next_node = new_node;

}

/**
 * Get Node by value
 *
 * @param LinkedList* list - Linked list
 * @param uint16_t value - node value
 * @return Node* node - pointer of the node or nullptr
 */
Node* get_node_by_value(LinkedList* list, uint16_t value) {
	
	if (!list->head) return nullptr;

	Node* current_node = list->head;

	while (current_node->next_node) {
		if (current_node->value == value) return current_node;
		current_node = current_node->next_node;
	}

	if (current_node->value == value) return current_node;

	return nullptr;
}

/**
 * Remove node
 *
 * @param Node* head_node - pointer of the head node
 * @param Node* node - pointer of the head node to be removed
 */
void remove_node(LinkedList* list, Node* node) {

	if (!list->head) return;

	Node* current_node = list->head;
	Node* previous_node = nullptr;

	// If the node to be removed is the head node
	if (current_node->value == node->value) {
		list->head = list->head->next_node;
		delete node;
		return;
	}

	while (current_node->next_node) {
		if (current_node->value == node->value) {
			previous_node->next_node = node->next_node;
			break;
		}

		previous_node = current_node;
		current_node = current_node->next_node;
	}

	delete node;
}

/**
* Print Linked list
*
* @param LinkedList* list - Linked list
*/
void print_list(LinkedList* list) {
	Node* current_node = list->head;

	while (current_node->next_node) {
		std::cout << current_node->value << " -> ";
		current_node = current_node->next_node;
	}
	std::cout << current_node->value << std::endl;

}

/* ---------------------------------------------- */
void main_without_list() {
	std::cout << "Without list" << std::endl;

	Node* head_node = new Node();
	head_node->value = 1;
	head_node->next_node = nullptr;

	append_node(head_node, 2);
	append_node(head_node, 3);
	append_node(head_node, 4);

	print_list(head_node);

	Node* node = get_node_by_value(head_node, 2);
	remove_node(head_node, node);
	print_list(head_node);

	node = get_node_by_value(head_node, 1);
	remove_node(head_node, node);
	print_list(head_node);
}
/**
 * Create a new node and append it
 *
 * @param Node* head_node - pointer to the head node
 * @param uint16_t value - value of the new Node
 */
void append_node(Node* head_node, uint16_t value) {

	// Get last node in list
	Node* current_node = head_node;
	while (current_node->next_node) {
		current_node = current_node->next_node;
	}

	// Create and assign new node
	Node* new_node = new Node();
	new_node->value = value;
	new_node->next_node = nullptr;
	current_node->next_node = new_node;
}

/**
 * Get Node by value
 *
 * @param Node* head_node - pointer to the head node
 * @param uint16_t value - node value
 * @return Node* node - pointer of the node or nullptr
 */
Node* get_node_by_value(Node* head_node, uint16_t value) {
	Node* current_node = head_node;

	while (current_node->next_node) {
		if (current_node->value == value) return current_node;
		current_node = current_node->next_node;
	}

	if (current_node->value == value) return current_node;

	return nullptr;
}

/**
 * Remove node
 * 
 * @param Node* head_node - pointer of the head node
 * @param Node* node - pointer of the head node to be removed
 */
void remove_node( Node* head_node, Node* node) {
	Node* current_node = head_node;
	Node* previous_node = nullptr;

	if (head_node->value == node->value) {
		std::cout << "Head Node can't be removed yet" << std::endl;
		return;
	}

	while (current_node->next_node) {
		if (current_node->value == node->value) {
			previous_node->next_node = node->next_node;
			break;
		}

		previous_node = current_node;
		current_node = current_node->next_node;
	}

	delete node;
}

void print_list(Node* head_node) {
	Node* current_node = head_node;

	while (current_node->next_node) {
		std::cout << current_node->value << " -> ";

		current_node = current_node->next_node;
	}

	std::cout << current_node->value << std::endl;
}