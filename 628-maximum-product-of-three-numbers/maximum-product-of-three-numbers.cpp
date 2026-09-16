class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int lar=INT_MIN;
        int seclar=INT_MIN;
        int thirdlar=INT_MIN;
        int small=INT_MAX;
        int secsmall=INT_MAX;
        for(int x: nums)
        {
            if(x>=lar){
                thirdlar=seclar;
                seclar=lar;
                lar=x;
            }
            else if(x>=seclar)
            {
                thirdlar=seclar;
                seclar=x;
            }
            else if(x>thirdlar)
            {
                thirdlar=x;
            }

            if(x<=small)
            {
                secsmall=small;
                small=x;
            }
            else if(x<secsmall)
            {
                secsmall=x;
            }
        }
        int product1=small*secsmall*lar;
        int product2=lar*seclar*thirdlar;
        return max(product1,product2);
    
        
        
    }
};