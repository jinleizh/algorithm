package cn.webank.ctrl.learn.lecture.lecture.list;

import java.util.ArrayList;
import java.util.List;

/**
 * @author ctrlzhang on 2018/5/16.
 */
public class Heap {
    public List<Integer> arr = new ArrayList<>();
    private int capacity = 0;

    Heap(List<Integer> input) {
        this.arr = input;
        this.capacity = input.size();
    }

    public void heapfy() {
        int n = arr.size();
        for(int i = (n - 1) / 2; i >= 0; i--) {
            adjust(i);
        }
    }

    public void adjust(int idx) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int end = capacity - 1;
        int tmp = idx;
        if (left < end) {
            if (arr.get(tmp) > arr.get(left)) {
                tmp = left;
            }
        }

        if (right < end) {
            if (arr.get(tmp) > arr.get(right)) {
                tmp = right;
            }
        }

        if (tmp != idx) {
            swap(arr, tmp, idx);
            adjust(tmp);
        }
    }

    public int pop() {
        if (capacity <= 0) return -1;
        int ans = arr.get(0);
        swap(arr, 0, capacity - 1);
        arr.remove(capacity - 1);
        capacity--;
        adjust(0);
        return ans;
    }

    public void push(int d) {
        arr.add(d);
        capacity = arr.size();
        int idx = capacity - 1;
        int parent = (idx - 1) / 2;
        while (parent >= 0) {
            if (arr.get(idx) < arr.get(parent)) {
                swap(arr, idx, parent);
                idx = parent;
                parent = (idx - 1) / 2;
            } else {
                break;
            }
        }
    }

    void swap(List<Integer> data, int l, int r) {
        int tmp = data.get(l);
        data.set(l, data.get(r));
        data.set(r, tmp);
    }

    void output() {
        for (int i = 0; i < arr.size(); i++) {
            System.out.println(this.arr.get(i));
        }
    }

    public static void main(String[] args) {
        List<Integer> input = new ArrayList<>();
        input.add(10);
        input.add(5);
        input.add(25);
        input.add(3);
        input.add(99);

        Heap myHeap = new Heap(input);
        myHeap.heapfy();
        myHeap.output();

        System.out.println("==========");

        myHeap.push(1);
        myHeap.output();
        System.out.println("==========");

        int k = 0;
        while (k < 3) {
            int val = myHeap.pop();
            System.out.println("pos ans=" + val);
            k++;
        }
        System.out.println("==========");
        myHeap.output();
    }
}
