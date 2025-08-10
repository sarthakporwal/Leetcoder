long long dig[10][4];
constexpr long long tens[10]={1, 10, 100, 1000, (int)1e4, (int)1e5, (int)1e6, 
(int)1e7, (int)1e8, (int)1e9};

class Solution {
public:
    static auto hash(int x){// a function has no coincides among 1<<i
        long long digest=0;
        for(; x>0; x/=10){
            const long long r=x%10;
            digest+=tens[r];
        }
        return digest;
    }
    static void compute_dig(){
        if (dig[0][0]!=0) return;// compute once 
        for(int i=0, j=0, d=1; i<30; i++){
            const int x=(1<<i);
            if (x>tens[d]){
                d++;
                j=0;
            }
            dig[d][j++]=hash(x);
        //    cout<<x<<"->d="<<d<<", "<<j-1<<endl;
        }
    }
    static bool reorderedPowerOf2(int n) {
        if (n==1e9) return 0;// edge case
        compute_dig();
        int d=upper_bound(tens, tens+10, n)-tens;
    //    cout<<d<<endl;
        const auto fn=hash(n);
        for(int i=0; i<4; i++){
            if(fn==dig[d][i]) return 1;
        }
        return 0;
    }
};