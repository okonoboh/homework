import sys

FIRST_PLAYER = '1'
SECOND_PLAYER = '2'
EMPTY = ''

BOARDSIZE = 8
   
PIECE_TO_MOVES = {'b' : 'ishop', 'k' : 'ing', 'n' : 'ight', 'p' : 'awn',
   'r' : 'ook', 'q' : 'ueen'}

# Create an empty 8 by 8 chess board
board = [[EMPTY for i in range(BOARDSIZE)] for j in range(BOARDSIZE)]

def init_starting_board(b):   
   # FIRST PLAYER [White]
   board[7][0] = 'r' + FIRST_PLAYER # Rook
   board[7][7] = 'r' + FIRST_PLAYER # Rook
   board[5][2] = 'n' + FIRST_PLAYER # Knight
   board[5][5] = 'n' + FIRST_PLAYER # Knight
   board[7][2] = 'b' + FIRST_PLAYER # Bishop
   board[7][5] = 'b' + FIRST_PLAYER # Bishop
   board[5][3] = 'q' + FIRST_PLAYER # Queen
   board[7][4] = 'k' + FIRST_PLAYER # King
   board[6][0] = 'p' + FIRST_PLAYER # Pawn
   board[6][2] = 'p' + FIRST_PLAYER # Pawn
   board[6][4] = 'p' + FIRST_PLAYER # Pawn
   board[6][6] = 'p' + FIRST_PLAYER # Pawn
   board[5][1] = 'p' + FIRST_PLAYER # Pawn
   board[4][3] = 'p' + FIRST_PLAYER # Pawn

   # SECOND PLAYER [Black]
   board[0][0] = 'r' + SECOND_PLAYER # Rook
   board[0][7] = 'r' + SECOND_PLAYER # Rook
   board[0][1] = 'n' + SECOND_PLAYER # Knight
   board[2][5] = 'n' + SECOND_PLAYER # Knight
   board[1][1] = 'b' + SECOND_PLAYER # Bishop
   board[2][3] = 'b' + SECOND_PLAYER # Bishop
   board[0][3] = 'q' + SECOND_PLAYER # Queen
   board[0][4] = 'k' + SECOND_PLAYER # King
   board[1][3] = 'p' + SECOND_PLAYER # Pawn
   board[1][5] = 'p' + SECOND_PLAYER # Pawn
   board[1][7] = 'p' + SECOND_PLAYER # Pawn
   board[2][2] = 'p' + SECOND_PLAYER # Pawn
   board[3][0] = 'p' + SECOND_PLAYER # Pawn
   board[3][4] = 'p' + SECOND_PLAYER # Pawn  

def is_valid_position(position):
   row, col = position
   return row >= 0 and row < BOARDSIZE and col >= 0 and col < BOARDSIZE
      
def moves_bishop(board, player, position):
   moves = []
   
   moves_helpher(-1, -1, board, player, position, moves)
   moves_helpher(-1, 1, board, player, position, moves)
   moves_helpher(1, -1, board, player, position, moves)
   moves_helpher(1, 1, board, player, position, moves)

   return [(position, to) for to in moves]
            
def moves_helpher(dy, dx, board, player, position, moves):
   row, col = position
   
   row += dy
   col += dx
   
   while is_valid_position((row, col)):
      if board[row][col] == EMPTY or board[row][col][1] != player:
         moves.append((row, col))
         
      if board[row][col] != EMPTY:
         break
         
      row += dy
      col += dx
   
def moves_king(board, player, position):
   moves = [(position[0] + y, position[1] + x) for y in range(-1, 2) for x in
      range(-1, 2)]
      
   return [(position, to) for to in moves if is_valid_position(to) and
      (board[to[0]][to[1]] == EMPTY or board[to[0]][to[1]][1] != player)]
   
def moves_night(board, player, position):
   row, col = position

   moves = [(row - 1, col - 2), (row - 2, col - 1), (row - 2, col + 1),
            (row - 1, col + 2), (row + 1, col - 2), (row + 2, col - 1),
            (row + 2, col + 1), (row + 1, col + 2)]
      
   return [(position, to) for to in moves if is_valid_position(to) and
      (board[to[0]][to[1]] == EMPTY or board[to[0]][to[1]][1] != player)]
   
def moves_pawn(board, player, position):
   row, col = position
   dy, two_row = 1, 1

   if player == SECOND_PLAYER:
      dy, two_row = -1, 6

   moves = [(row + dy, col - 1), (row + dy, col + 1)]
   moves = [(r, c) for r, c in moves if is_valid_position((r, c)) and
      board[r][c] != EMPTY and board[r][c][1] != player]
   
   if is_valid_position((row + dy, col)) and board[row + dy][col] == EMPTY:
      moves.append((row + dy, col))

      if is_valid_position((row + dy + dy, col)) and row == two_row and \
         board[row + dy + dy][col] == EMPTY:
         moves.append((row + dy + dy, col))

   return [(position, to) for to in moves]

   
def moves_rook(board, player, position):
   moves = []
   
   moves_helpher(0, -1, board, player, position, moves)
   moves_helpher(0, 1, board, player, position, moves)
   moves_helpher(1, 0, board, player, position, moves)
   moves_helpher(-1, 0, board, player, position, moves)
   
   return [(position, to) for to in moves]
   
   
def moves_queen(board, player, position):
   return moves_bishop(board, player, position) + \
      moves_rook(board, player, position)

def moves_function(piece):
   return getattr(sys.modules[__name__], 'moves_' +
      piece + PIECE_TO_MOVES[piece])
      
def player_pieces(board, player):
   for i in range(BOARDSIZE):
      for j in range(BOARDSIZE):
         if board[i][j][1:] == player:
            yield (board[i][j][0], (i, j))

def possible_moves(board, player):
   moves = []

   for piece, position in player_pieces(board, player):
      moves_procedure = moves_function(piece)
      moves += moves_procedure(board, player, position)

   return moves
      

def print_moves(moves):
   for f, t in moves:
      print('{0}{1} to {2}{3}'.format(chr(f[1] + 65), BOARDSIZE - f[0],
         chr(t[1] + 65), BOARDSIZE - t[0]))
      
   
   
init_starting_board(board)

print("White's moves:")
moves = possible_moves(board, FIRST_PLAYER)
print_moves(moves)

print("\nBlack's moves:")
moves = possible_moves(board, SECOND_PLAYER)
print_moves(moves)
