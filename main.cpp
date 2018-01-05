#include <iostream>

using namespace std;

/* 请在这里填写答案 */
template<class T>
class Vector {
private:
    T *m_elements;
    int m_size;
public:
    Vector() = default;

    Vector(int num);

    Vector(const Vector &);

    Vector &operator=(const Vector &);

    T &operator[](int index);

    const int add(const T &element);

    void remove(int index);

    const int get_size();

    virtual ~Vector() = default;
};

template<class T>
Vector<T>::Vector(int num) {

}

template<class T>
Vector<T>::Vector(const Vector &) {

}

template<class T>
Vector &Vector<T>::operator=(const Vector &) {
    return <#initializer#>;
}

template<class T>
T &Vector<T>::operator[](int index) {
    return <#initializer#>;
}

template<class T>
const int Vector<T>::add(const T &element) {
    return 0;
}

template<class T>
void Vector<T>::remove(int index) {

}

template<class T>
const int Vector<T>::get_size() {
    return 0;
}

int main() {
    Vector<int> vint;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        //	add() can inflate the vector automatically
        vint.add(i);
    }
    //	get_size() returns the number of elements stored in the vector
    cout << vint.get_size() << endl;
    cout << vint[m] << endl;
    //	remove() removes the element at the index which begins from zero
    vint.remove(m);
    cout << vint.add(-1) << endl;
    cout << vint[m] << endl;
    Vector<int> vv = vint;
    cout << vv[vv.get_size() - 1] << endl;
    vv.add(m);
    cout << vint.get_size() << endl;
}