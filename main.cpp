#include <iostream>

using namespace std;

/* 请在这里填写答案 */
template<class T>
class Vector {
private:
    T *m_elements;
    int m_size;
public:
    Vector() {
        m_size = 0;
        m_elements = new T;
    }

    Vector(int num) : m_size(num) {
        m_elements = new T[num];
        for (int i = 0; i < num; i++) {
            m_elements[i] = i;
        }
    }

    Vector<T> &operator=(const Vector<T> &that) {
        delete[] m_elements;
        m_size = that.get_size();
        m_elements = new T[m_size];
        for (int i = 0; i < that.get_size(); i++) {
            m_elements[i] = that.m_elements[i];
        }
        return *this;
    }

    const T &operator[](int index) const {
        if (index >= 0 && index < m_size) {
            return m_elements[index];
        } else {
            return -1;
        }
    }

    const int add(const T &element) {
        Vector<T> old;
        old = *this;
        delete[] m_elements;
        m_size++;
        m_elements = new T[m_size];
        for (int i = 0; i < m_size - 1; i++) {
            m_elements[i] = old.m_elements[i];
        }
        m_elements[m_size - 1] = element;
        delete[] old.m_elements;
        return m_size - 1;
    }

    void remove(int index) {
        Vector old;
        old = *this;
        delete[] m_elements;
        m_size--;
        m_elements = new T[m_size];
        for (int i = 0; i < index; i++) {
            m_elements[i] = old[i];
        }
        for (int i = index + 1; i < m_size; i++) {
            m_elements[i - 1] = old[i];
        }
        delete[] old.m_elements;
    }

    const int get_size() const {
        return m_size;
    }

    virtual ~Vector() = default;
};

int main() {
    Vector<int> vint;
//    Vector<int> vint_2 = Vector<int>(20);
//    vint_2.add(15);
//    for (int i = 0; i < 21; i++) {
//        cout << "vint_2[" << i << "]: " << vint_2[i] << endl;
//    }
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