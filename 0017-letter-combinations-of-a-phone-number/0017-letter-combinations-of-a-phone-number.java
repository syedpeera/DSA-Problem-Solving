class Solution {
    public void backtrack(String digits, int index, Map<Character, String> digitToLetters, StringBuilder current, List<String> result){
        if(index == digits.length()){
            result.add(current.toString());
            return;
        }
        
        String letters = digitToLetters.get(digits.charAt(index));
        for(char letter: letters.toCharArray()){
            current.append(letter);
            backtrack(digits, index+1, digitToLetters, current, result);
            current.deleteCharAt(current.length()-1);
        }
    }
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if(digits.length() == 0){
            return result;
        }
        
        Map<Character, String> digitToLetters = new HashMap<>();
        digitToLetters.put('2', "abc");
        digitToLetters.put('3', "def");
        digitToLetters.put('4', "ghi");
        digitToLetters.put('5', "jkl");
        digitToLetters.put('6', "mno");
        digitToLetters.put('7', "pqrs");
        digitToLetters.put('8', "tuv");
        digitToLetters.put('9', "wxyz");
        
        StringBuilder current = new StringBuilder();
        backtrack(digits, 0, digitToLetters, current, result);
        
        return result;
    }
}