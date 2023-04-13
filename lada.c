#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// I just wanted a length function (High-level fan here)

// This could've been used for both integers and chars but since
// only chars are needed here this reduces the required params
int len(int size)
{
  return size/sizeof(char);
}

// Alternative len() function
//
// int len(int size, void * arr)
// {
//    return size/sizeof(arr[0])
// }

// Printing buffer for moving "animation"
int print_buffer(int *length) 
{
  for (int i = 0; i <= *length; i++)
  {
    printf(" ");
  }
}
// Credit: https://stackoverflow.com/a/12642749
int get_columns()
{
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  int columns;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  return columns;
}

// Don't worry of all attributes, they figure themselves out
void enter_vehicle(int *width, int *height, char arr[][*width], int *distance, int *rate)
{
  // Iterating throught the vehicle n times (n = length of the vehicle)
  for (int entry = 0; entry < *width; entry++)
  { 
    Sleep(*rate);
    system("cls");
    int buffer = *width + *distance - entry; // Adjusting buffer on every frame
    // Iterating throught the height of the vehicle
    for (int vert = 0; vert < *height; vert++)    
    {
      print_buffer(&buffer); 
      // Iterating through the width of the vehicle for as long as it's visible by this         point
      for (int hori = 0; hori < entry; hori++)
      {
        printf("%c", arr[vert][hori]);
      }
      printf("\n");
    }
  }
}

void drive_vehicle(int *width, int *height, char arr[][*width], int *distance, int *rate)
{ 
  // int 'trav' is used later to reduce buffer length
  for (int trav = 0; trav < *distance; trav++)
  {
    Sleep(*rate);
    system("cls");
    // Adjusting buffer between every frame for movement reasons
    int buffer = *distance - trav; 
    // Literally just 2D array printing from down here, no magic

    // One line of the vehicle is printed at a time since buffer
    // needs to be printed separately for evely line
    for (int vert = 0; vert < *height; vert++)
    {
      print_buffer(&buffer);
      for (int hori = 0; hori < *width; hori++)
      {
        printf("%c", arr[vert][hori]);
      }
      printf("\n");
    }
  }
}

void evict_vehicle(int *width, int *height, char arr[][*width], int *rate)
{
  for (int depart = 0; depart < *width; depart++)
  {
    Sleep(*rate);
    system("cls");
    // This time buffer is not adjusted but print offset is adjuset below
    for (int vert = 0; vert < *height; vert++)
    {
      // Offsetting hori to depart for exit animation
      // More 2D array printing
      for (int hori = depart; hori < *width; hori++)
      {
        printf("%c", arr[vert][hori]);
      }
      printf("\n");
    }
  }
}


int main()
{ // MODIFY VARIABLES HERE, EVERYTHING RELEVANT CAN BE CHANGED HERE
  // When modifying the vehicle make sure every string is the same length
  char lada[][22] = {"      .--------.     ",
                     " ____/_____|___ \\___ ",
                     "0    _   -     _   ,*",
                     " '--(_)-------(_)--' "};
  int columns = get_columns(); // Makes travel distance dynamic
  int width = len(sizeof(lada[0])); // Don't modify, will fix itself when modifying vehicle according to instructions
  int height = sizeof(lada) / width; // Same as above
  int distance = columns - width - 1; // Fixing distance to avoid sketchy looking vehicle 
  int rate = 25; // New "frame" delay in milliseconds
  
  enter_vehicle(&width, &height, lada, &distance, &rate);
  drive_vehicle(&width, &height, lada, &distance, &rate);
  evict_vehicle(&width, &height, lada, &rate);
  // Eviction does not require buffer thus int 'distance' is not needed

  return 0;
}


// I struggled way too much with this
// Plis no roast me :)
// Epic Lada appear O_o


