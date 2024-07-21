class Solution {
//seive of Eratosthenes
public:
    
    int countPrimes(int n) {
        int count = 0;
        vector<bool> prime(n+1,true);//sbko prime maan lia
        prime[0]=prime[1]=false;//01 prime nhi hote
        for(int i=2;i<n;i++){
            if(prime[i]){
            count++;
            
            for(int j=2*i;j<n;j=j+i){
                prime[j]=0;
            }
            }
        }
        return count;
        
    }
};