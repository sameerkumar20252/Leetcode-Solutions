class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        boolean[] vis = new boolean[numCourses];
        List<Integer> st = new ArrayList<>();
        List<List<Integer>> adj = new ArrayList<>(numCourses);
        for(int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        for(int[] e : prerequisites) {
            adj.get(e[0]).add(e[1]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        int[] idx = new int[numCourses];
        for(int i = st.size() - 1; i >= 0; i--) {
            idx[st.get(i)] = i;
        }
        List<Boolean> ans = new ArrayList<>();

        for(int[] q : queries) {
            int u = q[0];
            int v = q[1];

            if(idx[u] > idx[v]) {
                ans.add(true);
            } else {
                ans.add(false);
            }
        }

        return ans;
    }

    void dfs(int u, List<List<Integer>> adj, boolean[] vis, List<Integer> st) {
        vis[u] = true;

        for(int v : adj.get(u)) {
            if(!vis[v]) {
                dfs(v, adj, vis, st);
            }
        }

        st.add(u);
    }
}