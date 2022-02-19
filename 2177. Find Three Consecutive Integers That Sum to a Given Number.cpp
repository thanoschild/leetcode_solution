class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num == 0)
                return {-1, 0, 1};
        if(num%3 == 0){
                return {num/3 - 1, num/3, num/3+1};
     }
            return { };
         
    }
};
