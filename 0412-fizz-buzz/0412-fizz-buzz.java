class Solution {
    public List<String> fizzBuzz(int n) {
        List<String> answer = new ArrayList<>();
        int fizz=0;
        int buzz=0;
        for(int i=1;i<=n;i++){
            fizz++;
            buzz++;
            StringBuilder sb = new StringBuilder();
            if(fizz==3){
                sb.append("Fizz");
                fizz=0;
            }
            if(buzz==5){
                sb.append("Buzz");
                buzz=0;
            }
            if(sb.length()==0){
                sb.append(i);
            }
            answer.add(sb.toString());
        }
        return answer;
    }
}