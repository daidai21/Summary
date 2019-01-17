/*
    打印数字1-9的全排列组合
*/
#include "stdio.h"
#define N 9
int x[N];
int count = 0;
 
void dump() {
  int i = 0;
  for (i = 0; i < N; i++) {
    printf("%d", x[i]);
  }
  printf("\n");
}
 
void swap(int a, int b) {
  int t = x[a];
  x[a] = x[b];
  x[b] = t;
}
 
void run(int n) {
  int i;
  if (N - 1 == n) {
    dump();
    count ++;
    return;
  }
  for (i = n; i < N; i++) {
    swap(n, i); // 从第n个元素依次和后面的元素进行交换.，i=n,表示不交换，原序打印
    run(n + 1); // 处理[n+1,N-1]的元素排列
    swap(n, i); // 交换回原样，以便再递归处理后面的元素
  }
}
 
int main() {
  int i;
  for (i = 0; i < N; i++) {
    x[i] = i + 1;
  }
  run(0);
  printf("* Total: %d\n", count);
}
