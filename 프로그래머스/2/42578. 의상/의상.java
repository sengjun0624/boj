import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        HashMap<String,Integer>hash=new HashMap<>();
        for(String [] arr : clothes){
            if(hash.containsKey(arr[1])){
               hash.put(arr[1],hash.get(arr[1])+1);
            }else{
                hash.put(arr[1],1);
            }
        } 
        int answer = 1;
        for(Integer values: hash.values()){
            answer *= (values+1);
        }
    
        return answer-1;
    }
}