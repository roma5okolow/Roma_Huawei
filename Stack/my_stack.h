#ifndef MY_STACK_H
#define MY_STACK_H

template <typename T>
class Stack {
public:
    Stack();
    Stack(T* data, int size);
    Stack(const Stack & other);
    Stack(Stack && other);
    ~Stack();

    bool is_empty() const;
    void push();
    T pop();
    int size() const;
    T& top();

    Stack & operator=(const Stack & rhs);
    bool operator==(const Stack & rhs) const;
    bool operator!=(const stack & rhs) const;

    const int START_STACK_SIZE = 32;

private:
    T* data_;
    int capacity_;
    int top_;
};

#endif //MY_STACK_H