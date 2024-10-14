import java.util.*;
class Solution {
    /*
    정렬을 어떻게 해야할까 숫자가 큰순서? 그럼 9가 10보다 작음 그래서 
    109가 되는데 무조건 자리수가 큰거가 앞으로 와야겠네 
    9999이런애들
    987654321 비교하고 응 그렇게 
    */
    public String solution(int[] numbers) {
        String str[]=new String[numbers.length];
        for(int i=0;i<numbers.length;i++){
            str[i]=String.valueOf(numbers[i]);
        }
        Arrays.sort(str,new Comparator<String>(){
            @Override
            public int compare(String a, String b){
                return (b+a).compareTo(a+b);
            }
        });
        StringBuilder sb= new StringBuilder();
        for(int i=0;i<str.length;i++){
            sb.append(str[i]);
        }
        if (str[0].equals("0")) {
            return "0";
        }
        String answer = sb.toString();
        return answer;
    }
}