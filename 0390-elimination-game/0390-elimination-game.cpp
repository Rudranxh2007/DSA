class Solution {
public:
    int lastRemaining(int n) {
        int head=1;
        int gap=1;
        int remaining=n;
        bool left=true;
        while(remaining>1){
            if(left){
                head+=gap;
            }else{
                if(remaining%2==1){
                    head+=gap;
                }
            }
            gap*=2;
            remaining/=2;
          left=!left;

        }
        return head;
    }
};