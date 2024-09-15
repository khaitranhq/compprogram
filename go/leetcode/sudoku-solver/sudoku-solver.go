package sudokusolver

var foundResult bool
var result [][]byte

func checkRow(board [][]byte, x int, y int, currentNumber byte) bool {
	for i := 0; i < 9; i++ {
		if board[x][i] == currentNumber && i != y {
			return false
		}
	}
	return true
}

func checkColumn(board [][]byte, x int, y int, currentNumber byte) bool {
	for i := 0; i < 9; i++ {
		if board[i][y] == currentNumber && i != x {
			return false
		}
	}
	return true
}

func checkSquare(board [][]byte, x int, y int, currentNumber byte) bool {
	row := (x / 3) * 3
	col := (y / 3) * 3
	for i := row; i-row < 3; i++ {
		for j := col; j-col < 3; j++ {
			if board[i][j] == currentNumber && (i != x || j != y) {
				return false
			}
		}
	}
	return true
}

func nextCell(x int, y int) (int, int) {
	if x < 8 && y == 8 {
		return x + 1, 0
	}

	if x == 8 && y == 8 {
		return -1, -1
	}

	return x, y + 1
}

func clone2DArrayByte(arr [][]byte) [][]byte {
	clone := make([][]byte, len(arr))
	for i := range arr {
		clone[i] = append(clone[i], arr[i]...)
	}
	return clone
}

func backtracking(board [][]byte, x int, y int) {
	if foundResult {
		return
	}

	nextX, nextY := nextCell(x, y)

	if board[x][y] != '.' {
		if nextX != -1 && nextY != -1 {
			backtracking(board, nextX, nextY)
		} else {
			result = clone2DArrayByte(board)
			foundResult = true
		}
		return
	}

	for replaceNumber := byte('1'); replaceNumber <= byte('9'); replaceNumber++ {
		if !checkRow(board, x, y, replaceNumber) ||
			!checkColumn(board, x, y, replaceNumber) ||
			!checkSquare(board, x, y, replaceNumber) {
			continue
		}

		clonedBoard := clone2DArrayByte(board)
		clonedBoard[x][y] = replaceNumber

		if nextX != -1 && nextY != -1 {
			backtracking(clonedBoard, nextX, nextY)
		} else {
			result = clone2DArrayByte(clonedBoard)
			foundResult = true
			return
		}
	}
}

func solveSudoku(board [][]byte) {
	foundResult = false
	backtracking(board, 0, 0)
	for i := range board {
		for j := range board[i] {
			board[i][j] = result[i][j]
		}
	}
}
