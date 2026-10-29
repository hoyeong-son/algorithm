# N-Queens

- The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

---

## 핵심 설계

- 행별 배치 : 퀸의 공격 특성 상 각 Row에는 반드시 1개의 퀸만 배치되어야 한다.
- 상태 공간 트리 : 트리의 각 Level이 하나의 Row를 의미하도록 탐색 트리 설계
- 가지치기 : 현재 행에서 유효하지 않은 Column은 탐색에서 제외하여 해당 경로의 탐색을 종료한다.
- 재귀 함수 : 콜 스택 구조를 이용하여 DFS를 수행

---

## 구현 (C)

```c
static void dfs(int row) {
		// 종료 조건 : Leaf Node까지 valid 검사를 통과한 경우 (해 발견)
        if (row == N) {
                add_solution(); // 발견한 해 저장
                return;
        }
        
        // 현재 row에서 가능한 모든 col 선택지 탐색
        for (int col = 0; col < N; col++) {
		        // child node가 valid 검사 통과 시 다음 row로 진행
		        // 실패 시 가지치기
                if (is_valid(row, col)) { 
                        col_at_row[row] = col;
	                    // 재귀 호출(콜 스택)을 통해 다음 행으로 깊이 우선 탐색
                        dfs(row + 1);
                }
        }
}

static bool is_valid(int row, int col) {
        for (int i = 0; i < row; i++) {
		        // 1. 같은 column에 다른 퀸이 있는지 검사
		        // 2. 대각선에 다른 퀸이 있는지 검사
                if (col_at_row[i] == col || abs(col_at_row[i] - col) == row - i)
                { return false; }
        }
        return true;
}
```

---

## 시간복잡도 분석

- **가지치기가 없을 경우**: 각 행마다 N개의 열을 선택할 수 있으므로 탐색 경로 : $N^N$가지
    - **열 중복 가지치기 적용**: 같은 열을 선택할 수 없으므로 탐색 경로 : $N!$가지
- **노드당 비용**: `is_valid()`는 이전 행들을 전부 검사하므로 $O(row) \leq O(N)$
- **시간복잡도 상한**: $O(N! \cdot N)$

- 실제로는 대각선 가지치기에 의해 방문하는 노드 수가 훨씬 적을 수 있다.

## 공간복잡도 분석

- **재귀 깊이 상한** : $O(N)$
- **배치 배열(`col_at_row`)** : $O(N)$
- **공간복잡도**: $O(N)$
