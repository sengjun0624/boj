class Solution {
    static int n;
    static int ans=0;
    public void solve(int len, int sum,int target,int[] numbers){
        if(len==n){
            if(sum==target)ans++;
            return;
        }
        // 호출전에 양수로 더하고  호출후에 다시 빼고 음수를 더하게끔
        sum+=numbers[len];
        solve(len+1,sum,target,numbers);
        sum-=numbers[len];
        sum-=numbers[len];
        solve(len+1,sum,target,numbers);
    }
    public int solution(int[] numbers, int target) {
        
        n=numbers.length;
        solve(0,0,target,numbers);
        int answer = ans;
        return answer;
    }
}