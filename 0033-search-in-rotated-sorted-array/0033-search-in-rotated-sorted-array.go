func search(nums []int, target int) int {
    n := len(nums)
    l, r := -1, n - 1
    for l + 1 < r {
        m := l + (r - l) / 2
        if nums[m] <= nums[n - 1] && target > nums[n - 1] { // target in left, m in right
            r = m
        } else if nums[m] > nums[n - 1] && target <= nums[n - 1] { // target in right, m in left
            l = m
        } else { // same part
            if nums[m] >= target {
                r = m
            } else {
                l = m
            }
        }
    }
    if nums[r] != target {
        return -1
    }
    return r
}