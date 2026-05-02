class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size(), n2 = nums2.size();
        int half = (n1 + n2) / 2;
        int left = 0, right = n1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int partition = half - mid;

            int maxLeft1 = (mid == 0) ? INT_MIN : nums1[mid - 1];
            int minRight1 = (mid == n1) ? INT_MAX : nums1[mid];
            int maxLeft2 = (partition == 0)  ? INT_MIN : nums2[partition - 1];
            int minRight2 = (partition == n2) ? INT_MAX : nums2[partition];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // correct partition found
                if ((n1 + n2) % 2 == 0)
                    return ((double)max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                else
                    return min(minRight1, minRight2);
            }
            else if (maxLeft1 > minRight2) right = mid - 1;
            else left = mid + 1;
        }

        return -1; // unreachable for valid input
    }
};
