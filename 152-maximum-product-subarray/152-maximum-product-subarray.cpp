class Solution {
public:
    long long MP(vector<int> arr, int n) {
    long long prdt=1;
   int head =-1;
   int  tail =0;
   long long ans = -1e9;

   for (int i = 0; i < n; ++i)
   {
       ans=max(ans, 1LL*(arr[i]));
   }

   while(tail<n){
     while(head+1<n && (arr[head+1]!=0)  )
     { 


          head++;
          prdt*=arr[head];
          ans=max(ans,prdt);


     }
     
     if(head>=tail)
     ans=max(ans,prdt);

     if(head>=tail){ 
         
         prdt/=arr[tail];


        tail++;
             }

     else{ 
       tail++;
       head=tail-1;
       prdt=1;
         }
         
   }return ans;
  }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        return MP(nums,n);
    }
};