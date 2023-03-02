# Conway-Game-Of-Life-Algorithm
The rules of the game are:
The Game Of Life is a cellular automaton algorithm. It runs on a universe, which is two-dimensional a grid of cells. Each cell can be in two states: alive or dead. There is an initial state for the universe, which defines alive cells and their positions in the universe. The automation progresses one step at a time by applying a set of rules to each cell in the universe. There rules are the following:

1) Any live cell with two or three live neighbors survives;
2) Any dead cell with three live neighbors becomes a live cell;
3) All other live cells die in the next generation. Similarly, all other dead cells stay dead.


The universe was initially populated with a glider pattern and animate its progress. The pattern is showed below:

<p align="center">
  <img width="400" height="300" src="/Glider pattern.png">
</p>

# Running-the-program
To run the program, simply run the conway.cpp in any IDE you want. The number of rows and columns are 8 in this case, however you can edit it in the cpp file. 
I ran the program for 50 generations however, you can change the number of generations in the global variable gen written globally.



# Output-of-the-program
The program ran for 50 generations and the first 3 generations are shown below. Alive cells are represented by 1 and dead cells are represented by 0. Note that the Universe state 0 is the initial state of the grid/universe with the glider pattern.
<p align="center">
  <img width="400" height="700" src="/First 3 generations.png">
</p>
