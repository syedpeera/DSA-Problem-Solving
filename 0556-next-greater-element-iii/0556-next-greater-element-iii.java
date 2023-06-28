class Solution {
    public int nextGreaterElement(int n) {
        int input = n;
        List<Integer> digits = new ArrayList<>();
        while (n != 0) {
            digits.add(n % 10);
            n = n / 10;
        }
        Collections.reverse(digits);
        int index1 = -1;
        int index2 = -1;
        for (int i = digits.size() - 1; i > 0; i--) {
            if (digits.get(i) > digits.get(i - 1)) {
                index1 = i - 1;
                break;
            }
        }
        if (index1 == -1) {
            Collections.reverse(digits);
        } else {
            for (int i = digits.size() - 1; i > 0; i--) {
                if (digits.get(i) > digits.get(index1)) {
                    index2 = i;
                    break;
                }
            }
            Collections.swap(digits, index1, index2);
            Collections.reverse(digits.subList(index1 + 1, digits.size()));
        }
        long num = 0;
        for (int i = 0; i < digits.size(); i++) {
            num = num * 10 + digits.get(i);
        }
        if (num <= input || num > Integer.MAX_VALUE) {
            return -1;
        }
        return (int) num;
    }
}