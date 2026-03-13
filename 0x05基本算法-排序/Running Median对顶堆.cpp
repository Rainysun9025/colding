#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5005  // 修正：去掉分号

int maxheap[MAXSIZE];  // 最大堆，存放较小的一半
int minheap[MAXSIZE];  // 最小堆，存放较大的一半
int maxSize = 0;       // 最大堆当前大小
int minSize = 0;       // 最小堆当前大小

// 交换两个整数
void exchange(int *a, int *b) {  // 修正：参数类型为指针
    int temp = *a;      // 修正：使用temp变量
    *a = *b;
    *b = temp;
}

// 打印堆状态（调试用）
void printHeaps() {
    printf("最大堆(size=%d): ", maxSize);
    for (int i = 1; i <= maxSize; i++) {
        printf("%d ", maxheap[i]);
    }
    if (maxSize > 0) printf(" (堆顶=%d)\n", maxheap[1]);
    else printf("\n");
    
    printf("最小堆(size=%d): ", minSize);
    for (int i = 1; i <= minSize; i++) {
        printf("%d ", minheap[i]);
    }
    if (minSize > 0) printf(" (堆顶=%d)\n", minheap[1]);
    else printf("\n");
}

// 最大堆上浮调整（插入时使用）
void rise_maxheap(int idx) {
    while (idx > 1) {
        int parent = idx / 2;
        if (maxheap[idx] > maxheap[parent]) {
            exchange(&maxheap[idx], &maxheap[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

// 最小堆上浮调整（插入时使用）
void rise_minheap(int idx) {
    while (idx > 1) {
        int parent = idx / 2;
        if (minheap[idx] < minheap[parent]) {
            exchange(&minheap[idx], &minheap[parent]);
            idx = parent;
        } else {
            break;
        }
    }
}

// 最大堆下沉调整（删除堆顶时使用）
void sink_maxheap(int idx) {
    while (idx * 2 <= maxSize) {
        int left = idx * 2;
        int right = left + 1;
        int largest = idx;
        
        if (left <= maxSize && maxheap[left] > maxheap[largest]) {
            largest = left;
        }
        if (right <= maxSize && maxheap[right] > maxheap[largest]) {
            largest = right;
        }
        
        if (largest != idx) {
            exchange(&maxheap[idx], &maxheap[largest]);
            idx = largest;
        } else {
            break;
        }
    }
}

// 最小堆下沉调整（删除堆顶时使用）
void sink_minheap(int idx) {
    while (idx * 2 <= minSize) {
        int left = idx * 2;
        int right = left + 1;
        int smallest = idx;
        
        if (left <= minSize && minheap[left] < minheap[smallest]) {
            smallest = left;
        }
        if (right <= minSize && minheap[right] < minheap[smallest]) {
            smallest = right;
        }
        
        if (smallest != idx) {
            exchange(&minheap[idx], &minheap[smallest]);
            idx = smallest;
        } else {
            break;
        }
    }
}

// 平衡两个堆的大小
void balanceHeaps() {
    // 情况1：最大堆比最小堆多2个或以上元素
    if (maxSize > minSize + 1) {
        // 将最大堆堆顶移到最小堆
        int movedValue = maxheap[1];
        
        // 插入到最小堆
        minheap[++minSize] = movedValue;
        rise_minheap(minSize);  // 上浮调整
        
        // 删除最大堆堆顶
        maxheap[1] = maxheap[maxSize];
        maxSize--;
        if (maxSize > 0) {
            sink_maxheap(1);  // 下沉调整
        }
    }
    // 情况2：最小堆比最大堆多元素
    else if (minSize > maxSize) {
        // 将最小堆堆顶移到最大堆
        int movedValue = minheap[1];
        
        // 插入到最大堆
        maxheap[++maxSize] = movedValue;
        rise_maxheap(maxSize);  // 上浮调整
        
        // 删除最小堆堆顶
        minheap[1] = minheap[minSize];
        minSize--;
        if (minSize > 0) {
            sink_minheap(1);  // 下沉调整
        }
    }
}

// 交换两个堆的堆顶（如果最大堆堆顶 > 最小堆堆顶）
void exchangeHeapTops() {
    if (minSize > 0 && maxheap[1] > minheap[1]) {
        exchange(&maxheap[1], &minheap[1]);
        
        // 调整两个堆
        sink_maxheap(1);
        sink_minheap(1);
    }
}

// 插入新元素
void insert(int num) {
    // 第一步：插入到最大堆
    maxheap[++maxSize] = num;
    rise_maxheap(maxSize);  // 上浮调整
    
    // 第二步：检查并交换堆顶（如果最大堆堆顶 > 最小堆堆顶）
    exchangeHeapTops();
    
    // 第三步：平衡两个堆的大小
    balanceHeaps();
}

// 获取当前中位数
int getMedian() {
    return maxheap[1];  // 中位数总是最大堆堆顶
}

int main() {
    int P;
    scanf("%d", &P);
    
    while (P--) {
        int datasetNum, M;
        scanf("%d %d", &datasetNum, &M);
        
        // 重置堆
        maxSize = 0;
        minSize = 0;
        
        // 存储中位数
        int medianCount = (M + 1) / 2;
        int medians[medianCount];
        int medianIdx = 0;
        
        // 读取并处理M个数字
        for (int i = 1; i <= M; i++) {
            int num;
            scanf("%d", &num);
            
            insert(num);
            
            // 如果是第奇数个，记录中位数
            if (i % 2 == 1) {
                medians[medianIdx++] = getMedian();
            }
        }
        
        // 输出结果
        printf("%d %d\n", datasetNum, medianCount);
        
        for (int i = 0; i < medianCount; i++) {
            printf("%d", medians[i]);
            if ((i + 1) % 10 == 0 && i != medianCount - 1) {
                printf("\n");
            } else if (i != medianCount - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
