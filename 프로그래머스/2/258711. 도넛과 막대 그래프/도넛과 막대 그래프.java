import java.util.*;

class Solution {
    
    static final int MAX = 1000001;
    ArrayList<ArrayList<Integer>> graph = new ArrayList<>(MAX);
    boolean[] visited = new boolean[MAX];
    
    public int hasCycle(int node){
        visited[node] = true;
        Queue<Integer> q = new LinkedList<>();
        q.offer(node);  // 시작 노드를 큐에 추가
        int cycle = 0;
        while(!q.isEmpty()){
            int cur = q.poll();
            for(int next : graph.get(cur)){
                if(visited[next]){
                    cycle++;
                    continue;
                }else{
                    q.offer(next);
                    visited[next] = true;
                }
            }
        }
        
        return cycle;
    }
    
    public int[] solution(int[][] edges) {
        int[] ingoing = new int[MAX];
        int[] outgoing = new int[MAX];
        
        for(int i = 0; i < MAX; i++){
            graph.add(new ArrayList<>());
        }
        for(int[] edge : edges){
            graph.get(edge[0] - 1).add(edge[1] - 1);  // 0-based 인덱스로 변경
            ingoing[edge[1] - 1]++;
            outgoing[edge[0] - 1]++;
        }
        
        int created = 0;
        for(int i = 0; i < MAX; i++){
            if(outgoing[i] >= 2 && ingoing[i] == 0) created = i + 1;
        }
        
        int[] result = {created, 0, 0, 0};
        
       
        for(int next: graph.get(created-1)){
                int cycle = hasCycle(next);
                System.out.println(cycle);
                switch(cycle){
                    case 0:
                        result[2]++;
                        break;
                    case 1:
                        result[1]++;
                        break;
                    case 2:
                        result[3]++;
                        break;
                }
        }
        
       
        return result;
    }
    
}