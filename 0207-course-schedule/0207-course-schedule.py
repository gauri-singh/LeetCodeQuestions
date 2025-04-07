from collections import defaultdict, deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # indegree = 0 is when a course has no requirements left

        indegree = [0] * numCourses
        mapping = defaultdict(list)
        for x, y in prerequisites:
            indegree[y] += 1
            mapping[x].append(y)
        result = []
        queue = deque([i for i in range(len(indegree)) if indegree[i] == 0])
        while queue:
            curr = queue.popleft()
            result.append(curr)
            for neighbor in mapping[curr]:
                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    queue.append(neighbor)
        if len(result) != numCourses:
            return False
        return True
