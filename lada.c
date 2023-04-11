#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// I just wanted a length function (High-level fan here)
int len(int size)
{
  return size/sizeof(char);
}
// Printing buffer for moving "animation"
int print_buffer(int *length) 
{
  for (int i = 0; i <= *length; i++)
  {
    printf(" ");
  }
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
  // Using trav to reduce buffer length
  for (int trav = 0; trav < *distance; trav++)
  {
    Sleep(*rate);
    system("cls");
    int buffer = *distance - trav; // Adjusting buffer between every frame
    // Literally just 2D array printing from down here, no magic
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
                     " '--(_)-------(_)--' ",};
  int distance = 55; // Total travel distance after entry
  int width = len(sizeof(lada[0])); // Don't modify, will fix itself when modifying vehicle according to instructions
  int height = sizeof(lada) / width; // Same as above
  int rate = 25; // New "frame" delay in milliseconds

  enter_vehicle(&width, &height, lada, &distance, &rate);
  drive_vehicle(&width, &height, lada, &distance, &rate);
  evict_vehicle(&width, &height, lada, &rate);
}


// I struggled way too much with this
// Plis no roast me :)
// Epic Lada appear O_o


