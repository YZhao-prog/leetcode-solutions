func findPeakElement(nums []int) int {
    n := len(nums)
    l, r := -1, n - 1
    for l + 1 < r {
        m := l + (r - l) / 2
        if nums[m] < nums[m + 1] {
            l = m
        } else {
            r = m
        }
    }
    return r
}