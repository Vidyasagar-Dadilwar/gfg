class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        graph = defaultdict(list)
        for src, dst in edges:
            graph[src].append(dst)
            graph[dst].append(src)
        
        q = deque([1]) 
        curr = 0
        res = -1
        vis = defaultdict(list)
        while(q):

            for i in range(len(q)): 
                node = q.popleft()
                if node==n:
                    if res!=-1:
                        return curr
                    res = curr 

                for nei in graph[node]:
                    nei_times = vis[nei]
                    if len(nei_times)==0 or (len(nei_times)==1 and nei_times[0]!=curr):
                        q.append(nei)
                        vis[nei].append(curr)
            if (curr//change)%2==1:
                curr += change - (curr%change)

            curr+=time 
            