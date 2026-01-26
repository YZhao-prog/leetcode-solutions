func findMin(nums []int) int {
    // nums[mid] > last    nums[mid] => ans's left
    // nums[mid] <= last  nums[mid] =>  ans's right
    n := len(nums)
    l, r := -1, n - 1
    for l + 1 < r {
        m := l + (r - l) / 2
        if nums[m] <= nums[n - 1] {
            r = m
        } else {
            l = m
        }
    }
    return nums[r]
}