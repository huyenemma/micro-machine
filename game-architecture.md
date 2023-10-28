# Game architecture 
## Library: 
- Box2D (game physics and logic)
- SFML (interactive effects n GUI)

## Class
Looby:
- Max 4 racer at a time 
- Choose my name and represent character (cat, dog, buffalo, dragon, snake)
abstract class Player(id, name, character)

- Choose map (forest, sea, moutain, otaniemi, desert) (from a collection or random)
abstract class Map() extend World?

- Choose 4 vehicles (Car, Boat, Feet, Skateboard) which have different properties (speed, power)
abstract class Vehicle() extend DynamicBody: 
    class Car: public Vehicle {}
    ...   

- Add bot/ add human player 
class Human extend Player()
class Bot extend Player()

- PLay! 

# In game  
- 1..2..3 go! 
class Game() contains Map object 

- User race by keyboard

- How to win: the first racer finish 5 rounds in 15min-> end the race
- Fixed and random booster around the race 
abstract class Collectible(id) extend StaticBody():  

- Scoreboard: time, how many rounds
1 variable in Game()

- Return to lobby at addbot state 
 
## handle stupid situation
- If no action in 5min, popup "Are you there?". If no response in 30s, loser. reason: out of juice
