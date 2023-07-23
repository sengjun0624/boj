#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	if (nodeCnt == 0)return;
	nodeCnt = 0;
	while (head->next != nullptr) {
		Node* old = head;
		head = head->next;
		old = nullptr;
	}
}

void addNode2Head(int data)
{
	if (nodeCnt == MAX_NODE)return;
	Node* New = getNode(data);
	if (nodeCnt != 1) {
		New->next = head;
	}
	head = New;
}

void addNode2Tail(int data)
{
	if (nodeCnt == MAX_NODE)return;
	Node* New = getNode(data);
	Node* cur = head;
	if (nodeCnt != 1) {
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = New;
	}
	else {
		head = New;
	}
}

void addNode2Num(int data, int num)
{
	if (data == 8) {
		int a = 0;
}
	if (nodeCnt == MAX_NODE)return;
	Node* New = getNode(data);
	Node* cur = head;
	if (num == 1) {
		if (nodeCnt == 1) {
			head = New;
			return;
		}
		New->next = head;
		head = New;
	}
	else {
	for (int i = 1; i < num-1; i++) {
		cur = cur->next;
	}
	New->next = cur->next;
	cur->next = New;
	}

}

void removeNode(int data)
{
	if (nodeCnt == 0)return;
	Node* Delete = head;
	Node* pre = Delete;
	while (Delete->next != nullptr) {
		if (Delete->data == data)break;
		pre = Delete;
		Delete = Delete->next;
	}
	if (Delete->data != data)return;

	if (Delete == head) {
		head = Delete->next;
	}
	else {
		pre->next = Delete->next;
	}
	Delete=nullptr;
}

int getList(int output[MAX_NODE])
{
	Node* cur = head;
	int cnt = 0;
	while (cur!= nullptr) {
		output[cnt] = cur->data;
		cur = cur->next;
		cnt++;
	}
	return cnt;
}