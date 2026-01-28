func searchMatrix(matrix [][]int, target int) bool {
    m, n := len(matrix), len(matrix[0])
    l, r := -1, m * n - 1
    for l + 1 < r {
        mid := l + (r - l) / 2
        if matrix[mid / n][mid % n] < target {
            l = mid
        } else {
            r = mid
        }
    }
    if matrix[r / n][r % n] == target {
        return true
    }
    return false
}