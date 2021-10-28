using namespace std;

namespace dynqueue {
  template <typename T>
  struct node {
    T data;
    node* next;
  };
  
  template <typename T>
  struct queue {
    node<T>* head;
    node<T>* tail;
  };
  
  template <typename T>
  void init(queue<T>& q) {
    q.head = NULL;
    q.tail = NULL;
  }
  
  template <typename T>
  bool empty(queue<T> q) {
    return q.head == NULL;
  }
  
  template <typename T>
  void enqueue(queue<T>& q, T value) {
    node<T>* aux = new(node<T>);
    aux->data = value;
    aux->next = NULL;
    if(q.head == NULL) {
      q.head = aux;
      q.tail = aux;
    } else {
      q.tail->next = aux;
      q.tail = aux;
    }
  }
  
  template <typename T>
  void dequeue(queue<T>& q) {
    q.head = q.head->next;
  }
  
  template <typename T>
  T front(queue<T> q) {
    return q.head->data;
  }
  
  template <typename T>
  void prt(queue<T> q) {
    cout << "\nElementi della coda: ";
    prtHelper(q.head);
  }
  
  template <typename T>
  void prtHelper(node<T>* n) {
    if(n != NULL) {
      cout << n->data << " ";
      prtHelper(n->next);
    }
  }
}