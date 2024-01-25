# Battleship

#### The program I made as a final project for the C++ course at Reykjavik University.

The program randomly positions the ships for both the player and the AI. There are 5 ships on the board. One 5 cell ship, one 4 cell ship, two 3 cell ships, and one 2 cell ship.

The player plays against an AI that has two levels of difficulty.

In easy mode, the AI shoots randomly at new coordinates.

In hard mode, the AI has 2 search modes, hunt mode, and target mode. Hunt mode is just like easy mode, which is randomly shooting to find ships. Target
mode starts when hunt mode hits a target. The initial coordinates are
added to a queue and the AI will shoot around that coordinate. When it
hits again the new coordinates are added to the back of the queue.
When the AI has shot at all the coordinates next to the first hit, it will
then remove it from the queue and use the next coordinates in the
queue. When the queue is empty the AI will go back to hunt mode to
find the next target.

```
Compile: g++ *.cpp -o battleship
Run: ./battleship
```
