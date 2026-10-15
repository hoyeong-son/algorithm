# Binary Search

## Code - Binary Search

```c
int search(int* nums, int numsSize, int target) {

    int low = 0;
    int high = numsSize - 1;

    while (low <= high) {
        int mid = low + ((high - low) / 2);
        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}
```

- `low` 왼쪽의 모든 원소(인덱스 `0 ~ low-1`)는 target보다 작다
- `high` 오른쪽의 모든 원소(인덱스 `high+1 ~ n-1`)는 target보다 크다
- `[low, high]` : target이 등장할 수 있는 Boundary
- loop의 최종 상태 : `low == high + 1`

- 최종 low, high의 상태를 파악해 searchInsert, sqrt 문제 해결이 가능했다.

## Time Complexity

- loop 내부(계산, 비교, 대입) : O(1)
- loop 반복 횟수

| 반복 횟수 | 남은 원소 수         |
| ----- | --------------- |
| 0     | $n$             |
| 1     | $\frac{n}{2}$   |
| 2     | $\frac{n}{4}$   |
| 3     | $\frac{n}{8}$   |
| ...   | ...             |
| t     | $\frac{n}{2^t}$ |

- loop 는 남은 원소의 개수가 1개($\frac{n}{2^t} = 1$)일 때까지 돈다.
 
$$\frac{n}{2^t} = 1 \rightarrow n = 2^t \rightarrow t = \log_{2}n$$

- 반복 횟수는 약 $\log_{2}n + 1$ 회가 된다.

- $O(1) \times O(\log n) = O(\log n)$
- Binary Search 시간 복잡도 : $O(\log n)$
