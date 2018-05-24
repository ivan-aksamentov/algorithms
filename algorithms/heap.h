#pragma once
#include <vector>

#include <common/debug.h>

template<typename T>
class vector_one_based {
    std::vector<T> m_data;
  public:
    typedef T                   value_type;
    typedef T&                  reference;
    typedef const T&            const_reference;

    void push_back(const_reference val) {
        m_data.push_back(val);
    }

    void pop_back() {
        assert(m_data.size() > 0);
        m_data.pop_back();
    }

    size_t size() const {
        return m_data.size();
    }

    reference operator[](size_t i) {
        assert(m_data.size() > 0);
        return m_data[i - 1];
    }

    const_reference operator[](size_t i) const {
        assert(m_data.size() > 0);
        return m_data[i - 1];
    }

    const std::vector<T>& internal_vector() const {
        return m_data;
    }
};

template<typename T>
class heap {
    vector_one_based<T> m_data;
  public:
    typedef T                   value_type;
    typedef T&                  reference;
    typedef const T&            const_reference;

    const std::vector<T>& internal_vector() const {
        return m_data.internal_vector();
    }

    reference operator[](size_t i) {
        assert(m_data.size() > 0);
        return m_data[i];
    }

    const_reference operator[](size_t i) const {
        assert(m_data.size() > 0);
        return m_data[i];
    }

    void push(const_reference val) {
        m_data.push_back(val);
        heap_up(m_data.size()-1);
    }

    T pop() {
        T popped = m_data[1];
        if (m_data.size() > 1) {
            m_data[1] = m_data[m_data.size() - 1];
            m_data.pop_back();
        }
        if (m_data.size() > 1) {
            heap_down(1);
        }
        return popped;
    }

  private:
    void parent(int k) {
        return k / 2;
    }

    void heap_up(int k) {
        while ((k > 1) && (m_data[k/2] < m_data[k])) {
            swap(m_data[k/2], m_data[k]);
            k /= 2;
        }
    }

    void heap_down(int k) {
        const auto n = m_data.size();
        while ((2 * k) <= n) {
            auto j = 2 * k;

            // pick smaller child
            if ((j < (n - 1)) && (m_data[j] < m_data[j + 1]))
                ++j;

            // stop if children are less
            if(!(m_data[k] < m_data[j]))
                break;

            // sink if not
            swap(m_data[k], m_data[j]);
            k = j;
        }
    }

};

