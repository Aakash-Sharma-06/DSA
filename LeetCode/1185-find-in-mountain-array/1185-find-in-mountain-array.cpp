/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();

        int l=0;
        int h=n-1;
        while(l<h){
            int mid=l+(h-l)/2;

            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                l=mid+1;
            }
            else{
                h=mid;
            }
        }
        int peak=l;
        
        int l1=0;
        int h1=peak;
        while(l1<=h1){
            int mid1=l1+(h1-l1)/2;

            if(mountainArr.get(mid1) == target){
                return mid1;
            }
            else if(mountainArr.get(mid1) < target){
                l1=mid1+1;
            }
            else{
                h1=mid1-1;
            }
        }

        int l2 = peak + 1;
        int h2 = n - 1;
        while(l2<=h2){
            int mid2=l2+(h2-l2)/2;

            if(mountainArr.get(mid2) == target){
                return mid2;
            }
              
            else if(mountainArr.get(mid2) < target){
                h2=mid2-1;
            }
            else{
                l2=mid2+1;
            }
        }

        return -1;
    }
};