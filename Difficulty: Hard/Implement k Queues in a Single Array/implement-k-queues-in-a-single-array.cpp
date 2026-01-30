class kQueues {
public:
    int n, k;
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;

    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        // initialize queues
        int i = 0;
        while (i < k) {
            front[i] = -1;
            rear[i] = -1;
            i++;
        }

        // initialize free list
        i = 0;
        while (i < n - 1) {
            next[i] = i + 1;
            i++;
        }
        next[n - 1] = -1;

        freeSpot = 0;
    }

    void enqueue(int x, int qi) {
        if (freeSpot == -1) {
            return; // array is full
        }

        int index = freeSpot;
        freeSpot = next[index];

        if (front[qi] == -1) {
            front[qi] = index;
        } else {
            next[rear[qi]] = index;
        }

        next[index] = -1;
        rear[qi] = index;
        arr[index] = x;
    }

    int dequeue(int qi) {
        if (front[qi] == -1) {
            return -1;
        }

        int index = front[qi];
        front[qi] = next[index];

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    bool isEmpty(int qi) {
        if (front[qi] == -1) {
            return true;
        }
        return false;
    }

    bool isFull() {
        if (freeSpot == -1) {
            return true;
        }
        return false;
    }
};
