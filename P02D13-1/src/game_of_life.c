#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>


#define HEIGHT 25
#define LENGTH 80

void choose_game();
void draw_field(char **main_matrix);
int allocMemory(char ***main_matrix);
void freeMemory(char **main_matrix);
void print_field(char **main_matrix);
int field_analyzation();


int main(){
    char **main_matrix;
    allocMemory(&main_matrix);
    choose_game();
    draw_field(main_matrix);
    print_field(main_matrix);
    freeMemory(main_matrix);
}

int allocMemory(char ***main_matrix) {
  int check = 1;
  (*main_matrix) = malloc(HEIGHT * sizeof(char *));
  if (*main_matrix != NULL) {
    for (int i = 0; i < HEIGHT; i++) {
      (*main_matrix)[i] = malloc(LENGTH * sizeof(char));
      if ((*main_matrix)[i] == NULL) {
        check = 0;
        for (int j = 0; j < i; j++) 
          free((*main_matrix)[i]);
        free(main_matrix);
        break;
      }
    }
  } else {
    check = 0;
  }
  return check;
}

void freeMemory(char **main_matrix) {
  for (int i = 0; i < HEIGHT; i++)
    free(main_matrix[i]);
  free(main_matrix);
}

/*void choose_game() {
    int var = 0;
    printf("Выберете вариант игры:\n");
    printf("1 - прож\n");
    printf("2 - прож\n");
    printf("3 - ролж\n");
    printf("4 - прож\n");
    printf("5 - прож\n");

    scanf("%d", &var);

    if (var < 1 || var > 5) {
        printf("Вы выбрали не существующий файл\n");
        return;
    }

    char *filename = malloc(20);
    sprintf(filename, "pict/txt_%d", var);

    // Открытие файла с выбранным изображением
    freopen(filename, "r", stdin);
    free(filename);
}*/

void choose_game(){
    int var = 0;
    printf("Выберете вариант игры:\n");
    printf("1 - прож\n");
    printf("2 - прож\n");
    printf("3 - ролж\n");
    printf("4 - прож\n");
    printf("5 - прож\n");
    scanf("%d", &var);
    if (var == 1){
        freopen("pict/txt_1.txt", "r", stdin);
    }else if(var == 2){
        freopen("pict/txt_2.txt", "r", stdin);
    }else if(var == 3){
        freopen("pict/txt_3.txt", "r", stdin);
    }else if(var == 4){
        freopen("pict/txt_4.txt", "r", stdin);
    }else if(var == 5){
        freopen("pict/txt_5.txt", "r", stdin);
    }else{
        printf("Вы выбрали не существующий файл");
    }

}

void draw_field(char **main_matrix){
    for (int i=0; i<HEIGHT; i++){
        for (int j=0; j<LENGTH; j++){
            char c;
            scanf("%c", &c);
            if (c == '1')
                c = '*';
            if (c == '0')
                c = ' ';
            main_matrix[i][j]=c;
        }
    }
}


void print_field(char **main_matrix) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < LENGTH; j++) {
            printf("%c", main_matrix[i][j]);
        }
    }
    printf("\n");
}

int field_analyzation(){

}