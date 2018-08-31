#include <stdio.h>
#include <stdlib.h>

int main() {
	
char no[3] = "n";
char No[3] = "N";	

char x_position_choice[10];
char y_position_choice[10];
char z_position_choice[10];

char c_x_pos[30];
char c_y_pos[30];
char c_z_pos[30];

float x_pos;
float y_pos;
float z_pos;

char c_box_rotation[30];
float box_rotation;

char c_x_size[30];
char c_y_size[30];
char c_z_size[30];

float x_size;
float y_size;
float z_size;

  printf("cmd2box\n");
  printf("\n");
  
  printf("Input 'x' position\n");
  scanf("%s", &c_x_pos);
  x_pos = atof(c_x_pos);

  printf("Input 'y' position\n");
  scanf("%s", &c_y_pos);
  y_pos = atof(c_y_pos);

  printf("Input 'z' position\n");
  scanf("%s", &c_z_pos);
  z_pos = atof(c_z_pos);

  printf("Input box rotation.(0 is fine.) \n");
  scanf("%s", &c_box_rotation);
  box_rotation = atof(c_box_rotation);
  
  printf("Input box 'x' size.\n");
  scanf("%s", &c_x_size);
  x_size = atof(c_x_size);
  printf("Input box 'y' size.\n");
  scanf("%s", &c_y_size);
  y_size = atof(c_y_size);
  printf("Input box 'z' size.\n");
  scanf("%s", &c_z_size);
  z_size = atof(c_z_size);
  
  printf("Is the 'x' position positive (Y/N): ");
  scanf("%s", &x_position_choice);
  if ((strcmp (x_position_choice, no) == 0) || (strcmp (x_position_choice, No) == 0)) {
      x_pos = x_pos * -1.0;
  }
  
  printf("Is the 'y' position positive (Y/N): ");
  scanf("%s", &y_position_choice);
  if ((strcmp (y_position_choice, no) == 0) || (strcmp (y_position_choice, No) == 0)){
	  y_pos = y_pos * -1.0;
  }
  
  printf("Is the 'z' position positive (Y/N): ");
  scanf("%s", &z_position_choice);
  if ((strcmp (z_position_choice, no) == 0) || (strcmp (z_position_choice, No) == 0)) {
      z_pos = z_pos * -1.0;
  }

  FILE *box;
  box = fopen("box.bzw", "wb");
  if (box) {
	  fprintf(box, "box\n");
	  fprintf(box, "position %.3f %.3f %.3f \n", x_pos, y_pos, z_pos);
	  fprintf(box, "size %.3f %.3f %.3f \n", x_size, y_size, z_size);
	  fprintf(box, "rotation %.3f\n", box_rotation);
	  fprintf(box, "end\n");
      fclose(box);
  }
  return 0;
}
