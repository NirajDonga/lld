Requirements:

should be played on n x n board.
2 player game. make turn using symbols(X and O).
player to get n symbols in row wins.
if all cells are filled. game ends in draw?
players should make legel moves.


entities:

Symbols
Gamestatus
WinningStratergy(check win)

Board
Game
Cell
Move
Players


reletions:

(has a)
Game -> board (1-1)
board -> cell(1-n)
cell -> symbol(1-1)
Game -> scoreboard
Game -> players
Game -> winninngStrategy
move -> player