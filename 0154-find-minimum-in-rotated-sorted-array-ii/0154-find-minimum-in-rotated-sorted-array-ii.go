func findMin(nums []int) int {
    n := len(nums)
    l, r := -1, n - 1
    for l + 1 < r {
        m := l + (r - l) / 2
        if nums[m] == nums[r] {
            r -= 1
        } else if nums[m] < nums[r] {
            r = m
        } else {
            l = m
        }
    }
    return nums[r]
}