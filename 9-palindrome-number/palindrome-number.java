class Solution {
    public boolean isPalindrome(int x) {
        
        if(x<0){
            return false;
        }
        int y=x;

        long rev =0;

        while(y != 0){
            
            int digit = y%10;
            rev = rev * 10 + digit;
            y /= 10;
        }

        if(x == rev){
            return true;
        }else{
            return false;
        }
    }
}