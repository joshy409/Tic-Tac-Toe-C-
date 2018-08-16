/*#Create a Tic Tac Toe game.You are free to use any IDE you like.

#Here are the requirements :

#2 players should be able to play the game(both sitting at the same computer)
#The board should be printed out every time a player makes a move
#You should be able to accept input of the player position and then place a symbol on the board

# 1 | 2 | 3
# -----        
# 4 | 5 | 6
# -----        
# 7 | 8 | 9

#board initialization.I chose dictonary because I want to call with keyword instead of indexing
board = { '1' : '', '2' : '','3' : '','4' : '', '5' : '','6' : '', '7' : '', '8' : '','9' : '' }

def print_board(player = '', move = '') :
	global board

	if move == '1' or '2' or '3' or '4' or '5' or '6' or '7' or '8' or '9' :
		board[move] = '  ' + player + '  '

		print()
		print(board['1'] + '|' + board['2'] + '|' + board['3'])
		print('------------------')
		print(board['1'] + '|' + board['2'] + '|' + board['3'])
		print('------------------')
		print(board['1'] + '|' + board['2'] + '|' + board['3'])

		def reset_board() :
		global board
		for clear in range(1, 10) :
			board[str(clear)] = '     '

			def space_check(move) :
			if move in['1', '2', '3', '4', '5', '6', '7', '8', '9'] :
				return board[move] == '     '
			else :
				return False

				def check_tie() :
				return '     ' in board.values()

				def win_check(player) :
				return (board['1'] == '  ' + player + '  ' and  board['2'] == '  ' + player + '  ' and  board['3'] == '  ' + player + '  ') or \
				(board['4'] == '  ' + player + '  ' and  board['5'] == '  ' + player + '  ' and  board['6'] == '  ' + player + '  ') or \
				(board['7'] == '  ' + player + '  ' and  board['8'] == '  ' + player + '  ' and  board['9'] == '  ' + player + '  ') or \
				(board['1'] == '  ' + player + '  ' and  board['4'] == '  ' + player + '  ' and  board['7'] == '  ' + player + '  ') or \
				(board['2'] == '  ' + player + '  ' and  board['5'] == '  ' + player + '  ' and  board['8'] == '  ' + player + '  ') or \
				(board['3'] == '  ' + player + '  ' and  board['6'] == '  ' + player + '  ' and  board['9'] == '  ' + player + '  ') or \
				(board['1'] == '  ' + player + '  ' and  board['5'] == '  ' + player + '  ' and  board['9'] == '  ' + player + '  ') or \
				(board['3'] == '  ' + player + '  ' and  board['5'] == '  ' + player + '  ' and  board['7'] == '  ' + player + '  ')

				def replay() :
				return input('\nDo you want to play again? Enter Yes or No: ').lower().startswith('y')


				print('Welcome to Tic Tac Toe!\n')
				player1 = 'X'
				player2 = 'O'
				print('Player 1 is X and Player 2 is O')
				import random
				rplay = True
				while rplay:
reset_board()
print_board()
pturn = random.choice([True, False])
win = False
print('\nPlayer who goes first is chosen randomly')

while not win:
#player 1's turn
if pturn:
move = input('\nMake your Move! Player 1! (1-9) : ')
if space_check(move) :
	print_board(player1, move)
	pturn = False
else :
	print('\nInvalid Move!')

	#check if the player2 won with last move then check if the game is tie
	if win_check(player1) :
		print('\nPlayer 1 is the Winner!')
		win = True
	else :
if not check_tie() :
	print('It is a tie!')
	break

	#player 2's turn        
else:
move = input('\nMake your Move! Player 2! (1-9) : ')
if space_check(move) :
	print_board(player2, move)
	pturn = True
else :
	print('\nInvalid Move!')

	#check if the player2 won with last move then check if the game is tie
	if win_check(player2) :
		print('\nPlayer 2 is the Winner!')
		win = True

	else :
if not check_tie() :
	print('It is a tie!')
	break

	rplay = replay() */