class Solution {

    class Trie {
        Trie[] child = new Trie[26];
        boolean end = false;
    }

    Trie root = new Trie();

    void insert(String s){
        Trie node = root;
        for(char c : s.toCharArray()){
            int i = c - 'a';
            if(node.child[i] == null)
                node.child[i] = new Trie();
            node = node.child[i];
        }
        node.end = true;
    }

    boolean dfs(String s, int idx, Trie node, int edits){
        if(edits > 2) return false;
        if(idx == s.length()) return node.end;

        for(int i=0;i<26;i++){
            if(node.child[i] != null){
                int newEdit = edits + (i != (s.charAt(idx) - 'a') ? 1 : 0);
                if(dfs(s, idx+1, node.child[i], newEdit))
                    return true;
            }
        }
        return false;
    }

    public List<String> twoEditWords(String[] queries, String[] dictionary) {
        for(String w : dictionary) insert(w);

        List<String> ans = new ArrayList<>();

        for(String q : queries){
            if(dfs(q, 0, root, 0))
                ans.add(q);
        }

        return ans;
    }
}