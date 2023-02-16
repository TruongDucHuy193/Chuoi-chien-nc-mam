#include <stdio.h>
#include <conio.h>
struct Node{
	int data;
	Node* pNext;
};
struct Stack{
	Node* Top;
};
void createStack(Stack &s) {
	s.Top = NULL;
}
Node* createNode(int x) {
	Node* p = new Node;
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(Stack(s)) {
	if (s.Top == NULL) {
		return true;
	}
	return false;
}
//thêm vào đầu Stack_LIFO
bool Push(Stack& s, Node* p) {
	if (p == NULL) {
		return false;
	}
	if (IsEmpty(s)) {
		s.Top = p; //node p là node đầu
	}
	else {
		p->pNext = s.Top; //cho con trỏ node p trỏ đến node đầu
		s.Top = p;//cập nhật lại node đầu
	}
	return true;
}
//lấy phần tử đầu Stack và trả về giá trị của nó rồi hủy đi
bool Pop(Stack& s, int& x) {
	//nếu danh sách rỗng
	if (IsEmpty(s)) {
		return false;
	}
	else {
		Node* temp = s.Top; //cho 1 node tạm thế mạng
		x = temp->data; //gán giá trị node đầu vào x
		s.Top = s.Top->pNext; //cập nhật lại node đầu là node kế tiếp
	}
	return true; 
}
//xem thông tin node và không xóa
bool Top(Stack& s, int& x) {
	if (IsEmpty(s)) {
		return false;
	}
	x = s.Top->data; //lấy ra xem
	return true;
}
void showStack(Stack& s) {
	while (IsEmpty(s) == false) {
		int x;
		Pop(s, x);
		printf("%d ", x);
	}
	if (IsEmpty(s)) {
		printf("\nStack is empty");
	}
	else {
		printf("\nStack is exist value");
	}
}
void Menu(Stack &s) {
	int choose;
	do {
		printf("\n1.Insert Stack");
		printf("\n2.Show Stack");
		printf("\n3.See the top element of the Stack");
		printf("\n0.Exit");
		printf("\nEnter choose: "); scanf_s("%d", &choose);
		if (choose == 1) {
			int x, n;
			printf("\nEnter a count of Stack: "); scanf_s("%d", &n);
			for (int i = 1; i <= n; i++) {
				printf("\nEnter element: "); scanf_s("%d", &x);
				Node* p = createNode(x);
				Push(s, p);
			}
		}
		if (choose == 2) {
			printf("\nStack include: ");
			showStack(s);
		}
		if (choose == 3) {
			int x;
			Top(s, x);
			printf("\nThe top element of the Stack is %d", x);
		}
	} while (choose != 0);
}
int main() {
	Stack s;
	createStack(s);
	Menu(s);
	_getch;
	return 0;
}