class Solution {
public:
    int maxProduct(vector<int>& arr, int k) {

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        long long ans = 1;

        if (k % 2 == 1) {

            if (arr[right] > 0) {
                ans *= arr[right];
                right--;
                k--;
            }
            else {
 
                for (int i = 0; i < k; i++) {
                    ans *= arr[right - i];
                }
                return ans;
            }
        }

        while (k > 0) {

            long long leftProduct =
                1LL * arr[left] * arr[left + 1];

            long long rightProduct =
                1LL * arr[right] * arr[right - 1];

            if (leftProduct > rightProduct) {
                ans *= leftProduct;
                left += 2;
            }
            else {
                ans *= rightProduct;
                right -= 2;
            }

            k -= 2;
        }

        return ans;
    }
};