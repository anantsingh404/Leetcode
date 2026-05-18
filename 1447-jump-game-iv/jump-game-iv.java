class Pair implements Comparable<Pair> {
    int first;  // Represents steps
    int second; // Represents index

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair other) 
    {
        if (this.first != other.first) {
            return Integer.compare(this.first, other.first);
        }
        return Integer.compare(this.second, other.second);
    }
}

class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        if (n <= 1) return 0;

        // Group indices by their array values
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < n; i++) {
            graph.computeIfAbsent(arr[i], v -> new ArrayList<>()).add(i);
        }

        // Min-Heap using your custom Pair class
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        
        // visited[i] stores the minimum steps found so far to reach index i
        int[] visited = new int[n];
        Arrays.fill(visited, Integer.MAX_VALUE);

        // Start at index 0 with 0 steps
        pq.add(new Pair(0, 0));
        visited[0] = 0;

        while (!pq.isEmpty()) {
            Pair current = pq.poll();
            int steps = current.first;
            int idx = current.second;

            // If we found a better path to this index already, skip processing
            if (steps > visited[idx]) {
                continue;
            }

            // Target reached
            if (idx == n - 1) {
                return steps;
            }

            // Option 1: Jump to all indices with the same value
            if (graph.containsKey(arr[idx])) {
                for (int nextIdx : graph.get(arr[idx])) {
                    // Only push if the new step count is strictly less than what is recorded
                    if (steps + 1 < visited[nextIdx]) {
                        visited[nextIdx] = steps + 1;
                        pq.add(new Pair(steps + 1, nextIdx));
                    }
                }
                // Clear map entry to prevent redundant scanning of the same value group
                graph.remove(arr[idx]);
            }

            // Option 2: Jump forward
            if (idx + 1 < n && steps + 1 < visited[idx + 1]) {
                visited[idx + 1] = steps + 1;
                pq.add(new Pair(steps + 1, idx + 1));
            }

            // Option 3: Jump backward
            if (idx - 1 >= 0 && steps + 1 < visited[idx - 1]) {
                visited[idx - 1] = steps + 1;
                pq.add(new Pair(steps + 1, idx - 1));
            }
        }

        return visited[n - 1];
    }
}