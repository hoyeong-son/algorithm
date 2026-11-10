# Subsets

- Given an integer array `nums` of **unique** elements, return _all possible_ _subsets_ _(the power set)_.

---

## 핵심 설계

- 상태 공간 트리 관점의 접근
	- 부분집합을 구하는 과정을 각 원소를 '선택한다(true)', '선택하지 않는다(false)'로 가지를 뻗어나가는 DFS 형태의 상태 공간 트리(완전 이진 트리)로 생각했다.

- bitmask 활용
	- 각 원소의 선택 여부를 하나의 비트로 표현한다. 즉, $N$개의 원소에 대응하는 $N$개의 비트로 하나의 부분집합을 나타낼 수 있다.
	- 따라서 $0$부터 $2^N-1$까지의 정수를 순회하면 모든 부분집합을 빠짐없이 표현할 수 있다.

- 시간 복잡도
	- $2^{N}$개의 부분집합 생성, 각 부분집합마다 최대 $N$회의 비트 검사 : $O(N \cdot 2^{N})$
