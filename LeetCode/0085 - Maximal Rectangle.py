class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        
        dp = [[0] * len(matrix[0]) for row in range(len(matrix))]
        max_area = 0
        
        for x in range(len(matrix)):
            for y in range(len(matrix[0])):
                if matrix[x][y] == "1":
                    if y == 0:
                        dp[x][y] = 1
                    else:
                        dp[x][y] = dp[x][y - 1] + 1
                        
                    current_width = dp[x][y]
        
                    for z in range(x, -1, -1):  # for (int z = x; z > -1; z--)
                        current_width = min(current_width, dp[z][y])
                        max_area = max(max_area, current_width * (x - z + 1))
        
        return max_area