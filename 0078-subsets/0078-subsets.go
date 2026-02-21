
import "slices"
func subsets(nums []int) (ans [][]int) {
    n := len(nums)
    path := []int{}
    var dfs func(int)
    dfs = func(i int) {
        ans = append(ans, slices.Clone(path))
        for j := i; j < n; j++ {
            path = append(path, nums[j])
            dfs(j + 1)
            path = path[:len(path) - 1]
        }
    }
    dfs(0)
    return ans
}
