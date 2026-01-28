func indexOfMax(mat [][]int, i int) int {
    ans, idx := 0, 0
    for j, x := range mat[i] {
        if x > ans {
            idx = j
            ans = x
        }
    }
    return idx
}
func findPeakGrid(mat [][]int) []int {
    l, r := -1, len(mat) - 1
    for l + 1 < r {
        m := l + (r - l) / 2
        j := indexOfMax(mat, m)
        if mat[m][j] < mat[m + 1][j] {
            l = m
        } else {
            r = m
        }
    }
    return []int{r, indexOfMax(mat, r)}
}