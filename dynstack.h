using namespace std;

namespace dynstack {
  template <typename T>
  struct node {
    T data;
    node* next;
  };
  
  template <typename T>
  struct stack {
    node<T>* head;
  };
  
  template <typename T>
  void init(stack<T>& s) {
    s.head = NULL;
  }
  
  template <typename T>
  bool empty(stack<T> s) {
    return s.head == NULL;
  }
  
  template <typename T>
  void push(stack<T>& s, T value) {
    node<T>* aux = new(node<T>);
    aux->data = value;
    aux->next = s.head;
    s.head = aux;
  }
  
  template <typename T>
  void pop(stack<T>& s) {
    s.head = s.head->next;
  }
  
  template <typename T>
  T top(stack<T> s) {
    return s.head->data;
  }
  
  template <typename T>
  void prt(stack<T> s) {
    cout << "\nElementi dello stack: ";
    prtHelper(s.head);
  }
  
  template <typename T>
  void prtHelper(node<T>* n) {
    if(n != NULL) {
      cout << n->data << " ";
      prtHelper(n->next);
    }
  }
}