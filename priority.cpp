#include <iostream>
using namespace std;


class PriorityQueue {
private:
    struct Element {
        unsigned int x, p;
    };
    Element* data;
    int size, max_size;
    
    void grow() {
        max_size *= 2;
        Element* new_data = new Element[max_size];
        for (int i = 0; i < size; ++i) new_data[i] = data[i];
        delete[] data;
        data = new_data;
    }
public:
    PriorityQueue(int max_size) {
        data = new Element[max_size];
        size = 0;
        this->max_size = max_size; 
    }

    ~PriorityQueue() {
        delete[] data;
        size = max_size = 0;
    }

    void push(unsigned int x, unsigned int p) {
        if (size == max_size) grow();

        Element key = {x, p};
        int i = size - 1;
        while (i >=0 && (key.p < data[i].p || (key.p == data[i].p && key.x > data[i].x))) {
            data[i + 1] = data[i];
            i--;
        }
        data[i + 1] = key;
        size++;
    }

    void pop() {
        if (size == 0) return;

        size--;
    }

    unsigned int peek() {
        if (size == 0) return 0;

        return data[size - 1].x;
    }

    bool is_empty() {
        return (size == 0);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    PriorityQueue pq(2);

    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            unsigned int x, p;
            cin >> x >> p;
            pq.push(x, p);
        } else if (op == 2) {
            cout << pq.peek() << " ";
            pq.pop();
        } 
    }
    return 0;
}