//-----Notes-----//
/* 
I wrote this like C code, not C++ so there may be room for optimization.
I have not yet included the code for checking if each peg has at least one wall. 
This might be easy for the random generation, 
but there will need to be something additional for the actual code or 
else the mouse will immediately assume that walls exist when they actually don't.
Flood tries to pull values that are off the edge of the grid. 
Consider making the grid 18x18 and give the outer grid spaces walls that face inward.
*/

int main(void){
  //-----Initialization-----//
  int maze[16][16][5];  //maze[x-axis][y-axis][walls & flood] (0=North, 1=East, 2=South, 3=West, 4=Flood) 
  int mx = 0;           //micromouse x-axis value
  int my = 0;           //micromouse y-axis value
  
  //-----Maze Setup-----//
  //puts walls along the outer perimeter
  for(int i=0;i<15;i++){
    for(int j=0;i<15;i++){
      maze[i][0][0] = 1;
      maze[i][15][2] = 1;
      maze[0][j][3] = 1;
      maze[15][j][1] = 1;
    }
  }
  //puts a third wall in every corner
  //South-West (micromouse starting position)
  maze[0][0][1] = 1;
  maze[1][0][3] = 1;
  //North-West
  maze[0][14][2] = 1;
  maze[0][15][0] = 1;
  //South-East
  maze[15][0][0] = 1;
  maze[15][1][2] = 1;
  //North-East
  maze[14][15][1] = 1;
  maze[15][15][3] = 1;
  
  //-----Flood-----//
  //fills all flood array spaces with -1
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      maze[i][j][4] = -1;
    }
  }
  //fills the four goal flood array spaces with 0
  maze[7][7][4] = 0;
  maze[7][8][4] = 0;
  maze[8][7][4] = 0;
  maze[8][8][4] = 0;
  //fills the flood array with values using flood fill logic
  for(int k=0;maze[mx][my][4]==-1;k++){  //stops filling when the flood fill reaches the micromouse's position
    for(int i=0;i<15;i++){
      for(int j=0;j<15;j++){
        if(maze[i][j][4]==k){  //if the flood array space equals k (starting at 0), place k+1 in adjacent flood array spaces
          if(!maze[i][j+1][2] && (maze[i][j+1][4]=-1)){  //North
            maze[i][j+1][4] = maze[i][j][4] + 1;
          }
          if(!maze[i][j-1][2] && (maze[i][j-1][4]=-1)){  //South
            maze[i][j-1][4] = maze[i][j][4] + 1;
          }
          if(!maze[i+1][j][2] && (maze[i+1][j][4]=-1)){  //East
            maze[i+1][j][4] = maze[i][j][4] + 1;
          }
          if(!maze[i-1][j][2] && (maze[i-1][j][4]=-1)){  //West
            maze[i-1][j][4] = maze[i][j][4] + 1;
          }
        }
      }
    }
  }
  return 0;
}
