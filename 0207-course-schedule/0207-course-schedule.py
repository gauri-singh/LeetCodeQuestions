from collections import defaultdict, deque
from typing import List

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # indegree = 0 means a course has no prerequisites

        indegree = [0] * numCourses
        mapping = defaultdict(list)

        # Correct logic: to take course x, you must first take course y
        # So edge is y -> x
        for x, y in prerequisites:
            indegree[x] += 1
            mapping[y].append(x)

        result = []
        queue = deque([i for i in range(len(indegree)) if indegree[i] == 0])

        while queue:
            curr = queue.popleft()
            result.append(curr)
            for neighbor in mapping[curr]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)

        return len(result) == numCourses
