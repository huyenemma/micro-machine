# Meeting Notes
In this file, you are required to take notes for your weekly meetings. 
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any


# Meeting 28.10.2023 11.30

**Participants**: 
1. Huyen Do
2. Quan Hoang
3. Huyen Nguyen
4. Duy To

# Meeting agenda
   - Basic properties of every basic class

# Notes
## Next week goal TUES 7/11
1. A car running around with Box2D GUI
2. Implementation of basic class
- Vehicle: 
   - Keyboard control: arrow key
   - Speed: Hold key = car run; key release = car slow down and stop
   - Max speed: How to integrate this feature with Box2D. Wish: We can use max speed to control max performance of vehicle in different environment
   - Speed change: When called by Collectable => Change speed up/down
   - How collision works in a world for vehicle with vehicle.
   - How collision works in a world for vehicle and obstacle.

- Test for Vehicle: Testbed

- Collectable:
   - Detect collision: When collided, object get destroyed
   - Call some function in Vehicle to modify speed

- Obstacle: 
   - (Static) object: where and how to put in world
   - How collision works in a world for obstacle.

- World:
   - Have somewhere to put things in
   - Handle collision


## Project status  
   - Finish game logic (how to play this game)
   - Basic project structure 
   - External library decided 
   - Currently writing project plan  

### TODOs
1. Flow for everyone: Study their class => Implement it => Create a void world to test for yourself => Commit everytime a function is done + announce to group chat 

2. Assignment:
- Huyen: World + generate map/character draft
- Duy: Obstacle 
- Quan: Vehicle
- Linh: Collectable
- Huyen, Linh, Duy: When Quan finishes abstract Vehicle, other implement concrete vehicle classes
- Everyone: Testbed

3. Next meeting: TUESDAY 7/11
- Revise plan
- Integration + testing 