
#include <stdio.h>
#include <stdlib.h>


// access and updates cache with each recursive call 
// checks are based on the zero provided we already know that subsequent fib will never equals zero. 
// so zero means that cache is for that specific n is not calculated.
int fib(int n,int *cache){
    if (n==0 || n==1){
        return cache[0] ; // also == cache[1]
    }
    else{
        // n has already been evaluated before and cached.
        
        int one_before,two_before ; 
        
        // both are in cache 
        if(cache[n-1]!=0 && cache[n-2]!=0){
            one_before = cache[n-1] ;
            two_before = cache[n-2] ;
        } // only one is in cache.
        else if(cache[n-1]==0 && cache[n-2]!=0){
            
            one_before = fib(n-1,cache) ; 
            two_before = cache[n-2] ;   
            
        }
        // none is in the cache. 
        else {
            one_before = fib(n-1,cache) ; 
            two_before = fib(n-2,cache) ; 
        }
        cache[n] = one_before + two_before ; 
        
        return one_before + two_before ; 
    }
}

// cached fibbonacci series 

int cachedFib(int n){
    int *cache = (int *)calloc(n,sizeof(int)) ; // set all values to 0 also. 
    if(cache==NULL){
        printf("cannot allocated heap space for cache. exiting\n");
        exit(1);
    }
    
    
    
    cache[0] = 1 ;
    cache[1] = 1 ; 
    static int cache_size = 2 ; // already have cache[0]
    
    int result = fib(n,cache) ; 
    
    for(int i = 0 ; i < n ; i ++ ){
        printf("%d ",cache[i]);
    }
    printf("\n");
    free(cache);
    return result ; 
}


int main()
{
    int result = cachedFib(100);
    printf("result = %d\n",result);
    return 0;
}
