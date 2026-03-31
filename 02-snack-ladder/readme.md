Requirements:

n players can play the game. each taking turn one by one. total m cells
snack and ladders can be passed at runtime.
rolling dice determine players move.
one winner.
multiple game can happen concurrently.


Entities:

Game():
Board(m):
Jump():
Dice():
Player():


Relations:

Game has a Board(1-1)
Board has a Jump(1-1)
Game has a Dice(1-1)
Game has players(1-n)