class Solution {
public:
    int smallestNumber(int n, int t) {

        while(true){
            int prod = 1;
            int temp = n;

            while(temp>0){
                prod = prod*(temp%10);
                temp = temp/10;
                if(prod==0) break;
            }

            // return (prod%t==0) ? n : n++;
            if(prod%t==0) return n;
            n++; 
        }

        // int a = n;

        // while(a<=100){
        //     int b=a%10;
        //     int c=a/10;
        //     int res = b*c;

        //     if(res%t==0){
        //         return a;
        //         break;
        //     }else{
        //         a++;
        //     }
        //}
    }
};

// class Solution {
// public:
//     int smallestNumber(int n, int t) {
//         while (true) {
//             int prod = 1;
//             int temp = n;
//             while (temp > 0) {
//                 prod *= temp % 10;
//                 temp /= 10;
//                 if (prod == 0) break;
//             }
//             if (prod % t == 0) return n;
//             n++;
//         }
//     }
// };