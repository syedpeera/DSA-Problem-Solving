class Solution {
    public boolean isPalindrome(String s, int start, int end){
        while(start < end){
            if(s.charAt(start) != s.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    public void solvePartition(String s, int start, List<String> current, List<List<String>> result){
        if(start == s.length()){
            result.add(new ArrayList<>(current));
            return;
        }
        for(int end=start; end<s.length(); end++){
            if(isPalindrome(s, start, end)){
                current.add(s.substring(start, end+1));
                solvePartition(s, end+1, current, result);
                current.remove(current.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        List<String> current = new ArrayList<>();
        solvePartition(s, 0, current, result);
        return result;
    }
}