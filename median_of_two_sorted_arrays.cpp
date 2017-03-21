// https://leetcode.com/problems/median-of-two-sorted-arrays/#/description
//
class Solution {
public:
    int findKMin(vector<int>& nums1, vector<int>& nums2, int start1, int start2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        if (m <= start1) {
            return nums2[start2 + k - 1];
        }
        if (n <= start2) {
            return nums1[start1 + k - 1];
        }
        if (k == 1) {
            if (nums1[start1] > nums2[start2])  return nums2[start2];
            else    return nums1[start1];
        }
        int n1 = start1 + k/2 - 1>= m ? INT_MAX : nums1[start1 + k/2 - 1];
        int n2 = start2 + k/2 - 1>= n ? INT_MAX : nums2[start2 + k/2 - 1];
        if (n1 < n2){
            return findKMin(nums1, nums2, start1 + k/2, start2, k - k/2);
        } else {
            return findKMin(nums1, nums2, start1, start2 + k/2, k - k/2);
        }
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        double ret;
        
        if (sum & 1) {
            ret = findKMin(nums1, nums2, 0, 0, sum / 2 + 1);
        } else {
            ret = ((findKMin(nums1, nums2, 0, 0, sum / 2)) +
                    findKMin(nums1, nums2, 0, 0, sum / 2 + 1)) / 2.0;
        }
        return ret;
    }
};
