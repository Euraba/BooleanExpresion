//
// Created by Euraba on 03.03.2021.
//

#ifndef TURNURI4_HEAP_H
#define TURNURI4_HEAP_H


class Heap {
private :
    static const int maxn = 1e5;
    int v[maxn + 1];
    int N;
public :
    Heap() {
        N = 0;
    }

    int getMax() {
        return v[1];
    }

    void heapify(int node) {
        int son;
        do {
            son = 0;
            if (2 * node <= N) {
                son = 2 * node;
                if (2 * node + 1 <= N && v[2 * node] < v[2 * node + 1]) {
                    son = 2 * node + 1;
                }
                if (v[son] < v[node]) {
                    son = 0;
                }
            }
            if (son) {
                std::swap(v[node], v[son]);
                node = son;
            }
        } while (son);
    }

    void filter(int node) {
        int val = v[node];
        while (node > 1 && val > v[node / 2]) {
            std::swap(v[node], v[node / 2]);
            node >>= 1;
        }
    }

    void buildHeap(int n, int aux[]) {
        N = n;
        for (int i = 1; i <= n; ++i) {
            v[i] = aux[i];
        }
        for (int i = N / 2; i > 0; --i) {
            heapify(i);
        }
    }

    void pop(int node = 1) {
        v[node] = v[N];
        N--;
        if ((node > 1) && v[node / 2] < v[node]) {
            filter(node);
        } else {
            heapify(node);
        }
    }

    void add(int val) {
        v[++N] = val;
        filter(N);
    }

};

#endif //TURNURI4_HEAP_H
