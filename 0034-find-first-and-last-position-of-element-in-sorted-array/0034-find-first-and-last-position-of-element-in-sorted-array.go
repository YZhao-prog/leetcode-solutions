func lower_bound(nums []int, t int) int {
    l, r := -1, len(nums)
    for l + 1 < r {
        m := l + (r - l) / 2;
        if nums[m] < t {
            l = m
        } else {
            r = m
        }
    }
    return r
}
func searchRange(nums []int, target int) []int {
    start := lower_bound(nums, target)
    if start == len(nums) || nums[start] != target {
        return []int{-1, -1}
    }
    end := lower_bound(nums, target + 1) - 1
    return []int{start, end}
}