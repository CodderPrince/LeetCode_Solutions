class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        # Get the number of rows and columns in the board
        ROWS, COLUMNS = len(board), len(board[0])

        # Create a path set to store all visited paths
        path = set()
        
        # Create a solve function
        def solve(rows, cols, i):
            # i indicates the position of character in the word
            if i == len(word):
                return True  # It means we found the word correctly
            
            # Some ways when we return false:
            '''
            ROWS = len(board) means 3 if the board has 3 rows
            COLUMNS = len(board[0]) means 3 if the board has 3 columns
            1. if rows < 0, it means no rows exist in negative index
            2. if cols < 0, it means no columns exist in negative index
            3. if rows >= ROWS, it means rows start at 0 to 2 [3]
               but our ROWS size is 3 so when we reach rows 3, that doesn't exist
            4. if cols >= COLUMNS, same as previous
            5. word[i] != board[rows][cols], it means the character at this index does not match the word
            6. (rows, cols) in path, it means we should not go to the same path again
            '''
            if (rows < 0 or cols < 0 or rows >= ROWS or cols >= COLUMNS or 
                word[i] != board[rows][cols] or (rows, cols) in path):
                return False
        
            # If none of the above conditions are false, it means we are on the correct path
            path.add((rows, cols))
            result = (solve(rows + 1, cols, i + 1) or
                      solve(rows - 1, cols, i + 1) or
                      solve(rows, cols + 1, i + 1) or
                      solve(rows, cols - 1, i + 1))
            
            # Backtrack by removing the current position from the path
            path.remove((rows, cols))
            return result

        # Nested for loop to start the search from each cell
        for rows in range(ROWS):
            for cols in range(COLUMNS):
                if solve(rows, cols, 0):
                    return True

        return False
