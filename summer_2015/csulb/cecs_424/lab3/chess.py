import sys

BOARDSIZE = 8
   
PIECE_TO_MOVES = {'b' : 'ishop', 'k' : 'ing', 'n' : 'ight', 'p' : 'awn',
   'r' : 'ook', 'q' : 'ueen'}

# Create an empty 8 by 8 chess board
board = [['' for i in range(BOARDSIZE)] for j in range(BOARDSIZE)]

def init_starting_board(b):
   # Initialize Player 1's non-Pawns
   board[0][0] = 'r1' # Rook
   board[0][1] = 'n1' # Knight
   board[0][2] = 'b1' # Bishop
   board[0][3] = 'q1' # Queen
   board[0][4] = 'k1' # King
   board[0][5] = 'b1' # Bishop
   board[0][6] = 'n1' # Knight
   board[0][7] = 'r1' # Rook
   
   # Player 1's Pawns
   for i in range(BOARDSIZE):
      board[1][i] = 'p1'
      
   # Initialize Player 2's non-Pawns
   board[6][0] = 'r2' # Rook
   board[6][1] = 'n2' # Knight
   board[6][2] = 'b2' # Bishop
   board[6][3] = 'q2' # Queen
   board[6][4] = 'k2' # King
   board[6][5] = 'b2' # Bishop
   board[6][6] = 'n2' # Knight
   board[6][7] = 'r2' # Rook
   
   # Player 2's Pawns
   for i in range(BOARDSIZE):
      board[7][i] = 'p2'
      
def moves_bishop(board, player, position):
   x = 1
   
def moves_king(board, player, position):
   left_column = position[1] - 1;
   right_column = position[1] + 1;
   upper_row = position[0] - 1;
   lower_row = position[0] + 1;
   
   moves = []
   
   def helpher(column):
      if upper_row >= 0:
         moves.append((upper_row, column))
         
      moves.append((position[0], column))   
         
      if lower_row < BOARDSIZE:
         moves.append((lower_row, column))
      
   
   if left_column >= 0:
      helpher(left_column)
   
   if right_column < BOARDSIZE:
      helpher(right_column)
         
   if upper_row >= 0:
      moves.append((upper_row, position[1]))
      
   if lower_row < BOARDSIZE:
      moves.append((lower_row, position[1]))
      
   return [(position, to) for to in moves if board[to[0]][to[1]] == '' or
      board[to[0]][to[1]][1] != player]
   
def moves_night(board, player, position):
   x = 1
   
def moves_pawn(board, player, position):
   x = 1
   
def moves_rook(board, player, position):
   moves = []
   
   moves_helpher(0, -1, board, player, position, moves)
   moves_helpher(0, 1, board, player, position, moves)
   moves_helpher(1, 0, board, player, position, moves)
   moves_helpher(-1, 0, board, player, position, moves)
   
   return [(position, to) for to in moves]
   
   
def moves_queen(board, player, position):
   x = 1

def moves_function(piece):
   return getattr(sys.modules[__name__], 'moves_' +
      piece + PIECE_TO_MOVES[piece])
      
def player_pieces(board, player):
   for i in range(BOARDSIZE):
      for j in range(BOARDSIZE):
         if board[i][j][1:] == player:
            yield (board[i][j][0], (i, j))
            
def moves_helpher(dy, dx, board, player, position, moves):
   row, column = position
   
   row += dy
   column += dx
   
   while row >= 0 and row < BOARDSIZE and column >= 0 and column < BOARDSIZE:
      if board[row][column] == '' or board[row][column][1] != player:
         moves.append(row, column)
         
      if board[row][column] != '':
         break
         
      row += dy
      column += dx
   
   
init_starting_board(board)
#current_module = sys.modules[__name__]
#print(moves_function('k'))

#for i in player_pieces(board, '2'):
#   print(i)

print(moves_king(board, '1', (0, 5)))