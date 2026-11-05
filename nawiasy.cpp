#include <iostream>
using namespace std;


class Stack {
private:
    char* data;
    int size, max_size;
    
    void grow() {
        max_size *= 2;
        char* new_data = new char[max_size];
        for (int i = 0; i < size; ++i) new_data[i] = data[i];
        delete[] data;
        data = new_data;
    }
public:
    Stack(int max_size) {
        data = new char[max_size];
        size = 0;
        this->max_size = max_size; 
    }

    ~Stack() {
        delete[] data;
        size = max_size = 0;
    }

    void push(char element) {
        if (size == max_size) grow();

        data[size] = element;
        size++;
    }

    void pop() {
        if (size == 0) return;

        size--;
    }

    char peek() {
        if (size == 0) return 0;

        return data[size - 1];
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
    while (n--) {
        Stack s(2);
        char c;
        bool correct = true;
        do {
            cin >> c;
            if (!correct) continue;

            if (c == '(' || c == '[' || c == '{') {
                s.push(c);
            } else if (c == ')') {
                if (!s.is_empty() && s.peek() == '(') {
                    // jest prawidłowo, zdejmujemy ze stosu
                    s.pop();
                } else {
                    correct = false;
                }
            } else if (c == ']') {
                if (!s.is_empty() && s.peek() == '[') {
                    // jest prawidłowo, zdejmujemy ze stosu
                    s.pop();
                } else {
                    correct = false;
                }
            } else if (c == '}') {
                if (!s.is_empty() && s.peek() == '{') {
                    // jest prawidłowo, zdejmujemy ze stosu
                    s.pop();
                } else {
                    correct = false;
                }
            }
        } while (c != '.');

        if (!s.is_empty()) correct = false;
        if (correct) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }    
    return 0;
}