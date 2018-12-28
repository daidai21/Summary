# -*- coding: utf-8 -*-


class Solution:
    """
    @param grid: a 2D array
    @return: the maximum total sum that the height of the buildings can be increased
    """
    def maxIncreaseKeepingSkyline(self, grid):
        # Write your code here
        level_length = len(grid[0])
        vertical_length = len(grid)
        level_max = [0 for i in range(level_length)]
        vertical_max = [0 for i in range(vertical_length)]
        for i in range(level_length):
            for j in range(vertical_length):
                if grid[i][j] > vertical_max[i]:
                    vertical_max[i] = grid[i][j]
                if grid[i][j] > level_max[j]:
                    level_max[j] = grid[i][j]
        max_add = 0
        for i in range(level_length):
            for j in range(vertical_length):
                while True:
                    if grid[i][j] < vertical_max[i] and grid[i][j] < level_max[j]:
                        max_add += 1
                        grid[i][j] += 1
                    else:
                        break
        return max_add
