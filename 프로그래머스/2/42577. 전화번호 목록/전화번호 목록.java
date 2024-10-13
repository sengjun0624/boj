import java.util.*; 

class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        HashMap<String,Integer>arr=new HashMap<>();
        Arrays.sort(phone_book);
        for(int i=0;i<phone_book.length;i++){
            String cmd="";
            for(int j=0;j<phone_book[i].length();j++){
                cmd+=phone_book[i].charAt(j);
                if(arr.containsKey(cmd)){
                    answer = false;
                    return answer;
                }
            }
            arr.put(cmd,1);
        }
        
        return answer;
    }
}