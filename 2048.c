#include <ctype.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void menu();
void resume();
void best_move();
int posrand(int size) {
  int randnr = 1 + (rand() % size);
  return randnr;
}
int randgenerator() {
  int set[2] = {2, 4};
  int randnr = rand() % 2;
  return set[randnr];
}
void Arrow(int pos1, int pos2, WINDOW *win) {
  if (pos1 == pos2) {
    mvwprintw(win, pos1, 27, "<--");
    wrefresh(win);
  } else {
    mvwprintw(win, pos1, 27, "     ");
  }
}
void check(int matrix[][4], int *av, int *size) {
  int i, j, t = 1;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (matrix[i][j] == 0) {
        av[t++] = i;
        av[t++] = j;
        (*size)++;
      }
    }
  }
}
void realpositions(int *x, int *y) {
  // functie care transforma coordonatele matricei in coordonatele tabelei de
  // joc
  if (*y == 0) {
    *y = 2;
  } else if (*y == 1) {
    *y = 5;
  } else if (*y == 2) {
    *y = 8;
  } else if (*y == 3) {
    *y = 11;
  }
  if (*x == 0) {
    *x = 1;
  } else if (*x == 1) {
    *x = 6;
  } else if (*x == 2) {
    *x = 11;
  } else if (*x == 3) {
    *x = 16;
  }
}
void show(int matrix[][4], WINDOW *newwin1, int *winner) {
  int i, j, realx, realy, t, p;
  // initializam culorile pentru fiecare numar posibil si iar apoi luam un
  // switch pentru fiecare caz si ca sa coloram toata celula luam 2 for uri
  // pentru coordonatele celulelor
  start_color();
  init_pair(3, COLOR_WHITE, COLOR_GREEN);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  init_color(8, 100, 1000, 100);
  init_color(9, 1000, 500, 0);
  init_color(20, 1000, 0, 0);
  init_color(21, 1000, 1000, 0);
  init_color(22, 0, 800, 800);
  init_color(23, 100, 200, 300);
  init_color(24, 1000, 0, 1000);
  init_color(25, 1000, 500, 1000);
  init_color(26, 200, 600, 600);
  init_pair(7, 0, 2);
  init_pair(8, 0, 8);
  init_pair(9, 0, 9);
  init_pair(10, 0, 20);
  init_pair(11, 0, 21);
  init_pair(12, 0, 22);
  init_pair(13, 0, 23);
  init_pair(14, 0, 24);
  init_pair(15, 0, 25);
  init_pair(16, 7, 26);
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      realy = i;
      realx = j;
      realpositions(&realx, &realy);
      switch (matrix[i][j]) {
        case 2:
          wattron(newwin1, COLOR_PAIR(7));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, " %d  ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(7));
          break;

        default:
          break;
        case 0:
          wattron(newwin1, COLOR_PAIR(4));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "    ");
          wattroff(newwin1, COLOR_PAIR(4));
          break;
        case 4:

          wattron(newwin1, COLOR_PAIR(8));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, " %d  ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(8));
          break;
        case 8:
          wattron(newwin1, COLOR_PAIR(9));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, " %d  ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(9));
          break;
        case 16:
          wattron(newwin1, COLOR_PAIR(10));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "%d  ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(10));
          break;
        case 32:
          wattron(newwin1, COLOR_PAIR(11));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "%d  ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(11));
          break;
        case 64:
          wattron(newwin1, COLOR_PAIR(12));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "%d  ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(12));
          break;
        case 128:
          wattron(newwin1, COLOR_PAIR(13));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "%d ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(13));
          break;
        case 256:
          wattron(newwin1, COLOR_PAIR(14));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "%d ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(14));
          break;
        case 512:
          wattron(newwin1, COLOR_PAIR(15));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "%d ", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(15));
          break;
        case 1024:
          wattron(newwin1, COLOR_PAIR(16));
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "%d", matrix[i][j]);
          wattroff(newwin1, COLOR_PAIR(16));
          break;
        case 2048:
          for (p = realy - 1; p < realy; p++) {
            for (t = realx; t < realx + 4; t++) {
              mvwprintw(newwin1, p, t, " ");
            }
          }
          mvwprintw(newwin1, realy, realx, "%d", matrix[i][j]);
          break;
      }
      // verificam daca am ajuns la 2048 si winner devine 1
      if (matrix[i][j] == 2048) {
        *winner = 1;
      }
    }
  }
  wrefresh(newwin1);
}
void show2(WINDOW *newwin2) {
  // afisam legenda colorata
  start_color();
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  wattron(newwin2, COLOR_PAIR(1));
  mvwprintw(newwin2, 1, 3, "^ - mutare in sus");
  mvwprintw(newwin2, 3, 3, "> - mutare la dreapta");
  mvwprintw(newwin2, 5, 3, "v - mutare in jos");
  mvwprintw(newwin2, 7, 3, "< - mutare la stanga");
  mvwprintw(newwin2, 9, 3, "q - pentru a revenii la meniu");
  mvwprintw(newwin2, 11, 3,
            "Daca nu faceti o miscare in 10 secunde se va face automat una "
            "aleatoare");
  wattroff(newwin2, COLOR_PAIR(1));
  wrefresh(newwin2);
}
void show3(WINDOW *newwin3, int total_score, int score) {
  // afisam scorul impreuna cu total scoreul si cat este adaugta la fiecare
  // mutare,plus culorile
  start_color();
  init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  wattron(newwin3, COLOR_PAIR(1));
  mvwprintw(newwin3, 0, 0, "Score: %d", total_score);
  wattroff(newwin3, COLOR_PAIR(1));
  wattron(newwin3, COLOR_PAIR(2));
  if (score) {
    if (score < 10) {
      mvwprintw(newwin3, 0, 13, "( +  %d   )", score);
    } else if (score < 100) {
      mvwprintw(newwin3, 0, 13, "( +  %d  )", score);
    } else if (score < 1000) {
      mvwprintw(newwin3, 0, 13, "( +  %d )", score);
    }
  } else {
    mvwprintw(newwin3, 0, 13, "             ");
  }
  wattroff(newwin3, COLOR_PAIR(2));
  wrefresh(newwin3);
}
void show4(WINDOW *newwin4) {
  // afisam timpul curent cu ajutorul structurii tm
  start_color();
  init_pair(6, COLOR_YELLOW, COLOR_BLACK);
  wattron(newwin4, COLOR_PAIR(6));
  time_t current_time;
  current_time = time(NULL);
  time(&current_time);
  struct tm *struct_time = localtime(&current_time);
  mvwprintw(newwin4, 2, 0, "Data curenta: %02d/%02d/%04d", struct_time->tm_mday,
            struct_time->tm_mon + 1, struct_time->tm_year + 1900);
  mvwprintw(newwin4, 3, 0, "Ora curenta: %02d:%02d:%02d", struct_time->tm_hour,
            struct_time->tm_min, struct_time->tm_sec);
  wattroff(newwin4, COLOR_PAIR(6));
  wrefresh(newwin4);
}
void time_skip(WINDOW *newwin1, int *keyPress, WINDOW *newwin4,
               int matrix[][4]) {
  // in aceasta functie verificam daca trec 10 secunde de la ultima tasta
  // apasata sau daca se apasa trimitem input-ul in game
  // Ne folosim de difftime unde calculam diferenta dintre start time si end
  // time care e actualizat in continuu in while.Am folosit nodelay pentru a
  // trece prin comada wgetch aceasta nemaiblocand programul.Daca trec 10
  // secunde atunci generam cea mai buna mutare
  int count = 0;
  time_t start_time, end_time;
  time(&start_time);
  (*keyPress) = ERR;
  while (1) {
    show4(newwin4);
    (*keyPress) = wgetch(newwin1);
    if ((*keyPress) != ERR) {
      count++;
      break;
    }
    time(&end_time);
    double elapsed = difftime(end_time, start_time);
    if (elapsed >= 10 && (*keyPress) == ERR) {
      count = 0;
      break;
    }
  }
  if (count == 0) {
    best_move(matrix, &(*keyPress));
  }
}
void best_move(int matrix[][4], int *keyPress) {
  int i, j, matrix2[4][4], coord[4], k, p, up = 0, down = 0, right = 0,
                                           left = 0, through = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      matrix2[i][j] = matrix[i][j];
    }
  }
  // trecem prin toate miscarile si verificam dupa fiecare cate celule de 0 sunt
  // la fiecare ,cea care are cele mai multe este cea mai buna cum s a mentionat
  // si in enunt
  for (j = 0; j < 4; j++) {
    i = 1, k = 0;
    for (p = 0; p < 4; p++) {
      coord[p] = -1;
    }
    while (i < 4) {
      while (i < 4 && matrix2[i][j] == 0) {
        i++;
      }

      if (i >= 4) {
        break;
      }
      while (i > 0 &&
             (matrix2[i - 1][j] == 0 || matrix2[i][j] == matrix2[i - 1][j])) {
        through = 1;
        if (matrix2[i - 1][j] == 0) {
          matrix2[i - 1][j] = matrix2[i][j];
          matrix2[i][j] = 0;
          i--;
        } else if (matrix2[i][j] == matrix2[i - 1][j]) {
          for (p = 0; p < 4; p++) {
            if (coord[p] == i - 1) {
              goto megred_up;
            }
          }
          matrix2[i - 1][j] *= 2;
          matrix2[i][j] = 0;
          coord[k++] = i - 1;
          break;
        }
      }
    megred_up:
      i++;
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (matrix2[i][j] == 0) {
        up++;
      }
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      matrix2[i][j] = matrix[i][j];
    }
  }
  for (j = 0; j < 4; j++) {
    i = 2, k = 0;
    for (p = 0; p < 4; p++) {
      coord[p] = -1;
    }
    while (i >= 0) {
      while (i >= 0 && matrix2[i][j] == 0) {
        i--;
      }

      if (i < 0) {
        break;
      }
      while (i < 3 &&
             (matrix2[i + 1][j] == 0 || matrix2[i + 1][j] == matrix2[i][j])) {
        through = 1;
        if (matrix2[i + 1][j] == 0) {
          matrix2[i + 1][j] = matrix2[i][j];
          matrix2[i][j] = 0;
          i++;
        } else if (matrix2[i][j] == matrix2[i + 1][j]) {
          for (p = 0; p < 4; p++) {
            if (coord[p] == i + 1) {
              goto merged_down;
            }
          }
          matrix2[i + 1][j] *= 2;
          matrix2[i][j] = 0;
          coord[k++] = i + 1;

          break;
        }
      }
    merged_down:
      i--;
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (matrix2[i][j] == 0) {
        down++;
      }
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      matrix2[i][j] = matrix[i][j];
    }
  }
  for (i = 0; i < 4; i++) {
    j = 1, k = 0;
    for (p = 0; p < 4; p++) {
      coord[p] = -1;
    }
    while (j < 4) {
      while (j < 4 && matrix2[i][j] == 0) {
        j++;
      }
      if (j >= 4) {
        break;
      }
      while (j > 0 &&
             (matrix2[i][j - 1] == 0 || matrix2[i][j - 1] == matrix2[i][j])) {
        through = 1;
        if (matrix2[i][j - 1] == 0) {
          matrix2[i][j - 1] = matrix2[i][j];
          matrix2[i][j] = 0;
          j--;
        } else if (matrix2[i][j - 1] == matrix2[i][j]) {
          for (p = 0; p < 4; p++) {
            if (coord[p] == j - 1) {
              goto merged_left;
            }
          }
          matrix2[i][j - 1] *= 2;
          matrix2[i][j] = 0;
          coord[k++] = j - 1;
          break;
        }
      }
    merged_left:
      j++;
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (matrix2[i][j] == 0) {
        left++;
      }
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      matrix2[i][j] = matrix[i][j];
    }
  }
  for (i = 0; i < 4; i++) {
    j = 2, k = 0;
    for (p = 0; p < 4; p++) {
      coord[p] = -1;
    }
    while (j >= 0) {
      while (j >= 0 && matrix2[i][j] == 0) {
        j--;
      }
      if (j < 0) {
        break;
      }
      while (j < 3 &&
             (matrix2[i][j + 1] == 0 || matrix2[i][j + 1] == matrix2[i][j])) {
        through = 1;
        if (matrix2[i][j + 1] == 0) {
          matrix2[i][j + 1] = matrix2[i][j];
          matrix2[i][j] = 0;
          j++;
        } else if (matrix2[i][j + 1] == matrix2[i][j]) {
          for (p = 0; p < 4; p++) {
            if (coord[p] == j + 1) {
              goto megred_right;
            }
          }
          matrix2[i][j + 1] *= 2;
          matrix2[i][j] = 0;
          coord[k++] = j + 1;

          break;
        }
      }
    megred_right:
      j--;
    }
  }
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (matrix2[i][j] == 0) {
        right++;
      }
    }
  }
  // comparam numarul celulelor de 0 de la fiecare mutare si selectam mutarea
  // corespunzator sau daca nicio mutare nu este mai buna generam una radnom
  int max = up, index = 1;
  if (through) {
    if (down > max) {
      max = down;
      index = 2;
    }
    if (left > max) {
      max = left;
      index = 3;
    }
    if (right > max) {
      max = right;
      index = 4;
    }
    if (index == 1) {
      (*keyPress) = KEY_UP;
    }
    if (index == 2) {
      (*keyPress) = KEY_DOWN;
    }
    if (index == 3) {
      (*keyPress) = KEY_LEFT;
    }
    if (index == 4) {
      (*keyPress) = KEY_RIGHT;
    }
  } else {
    int random = posrand(4);
    if (random == 1) {
      (*keyPress) = KEY_UP;
    }
    if (random == 2) {
      (*keyPress) = KEY_RIGHT;
    }
    if (random == 3) {
      (*keyPress) = KEY_DOWN;
    }
    if (random == 4) {
      (*keyPress) = KEY_LEFT;
    }
  }
}
void check_game(WINDOW *newwin1, int matrix[][4], int *game_over) {
  int i, j, count = 0, matrix2[4][4];
  // verificam daca avem toate celulele ocupate pentru a avea sens trecerea prin
  // algoritmul de mai jos si copiem matricea
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      if (matrix[i][j] == 0) {
        (*game_over) = 0;
      } else {
        (*game_over) = 1;
      }
      matrix2[i][j] = matrix[i][j];
    }
  }
  // daca toate sunt ocupate atunci incercam sa folosim toate miscarile pe rand
  // si verificam daca dupa oricare mutare avem macar o celula egala cu 0
  if (*game_over) {
    int coord[4], k = 0, p;
    for (j = 0; j < 4; j++) {
      i = 1, k = 0;
      for (p = 0; p < 4; p++) {
        coord[p] = -1;
      }
      while (i < 4) {
        while (i < 4 && matrix2[i][j] == 0) {
          i++;
        }

        if (i >= 4) {
          break;
        }
        while (i > 0 &&
               (matrix2[i - 1][j] == 0 || matrix2[i][j] == matrix2[i - 1][j])) {
          if (matrix2[i - 1][j] == 0) {
            matrix2[i - 1][j] = matrix2[i][j];
            matrix2[i][j] = 0;
            i--;
          } else if (matrix2[i][j] == matrix2[i - 1][j]) {
            for (p = 0; p < 4; p++) {
              if (coord[p] == i - 1) {
                goto megred_up2;
              }
            }
            matrix2[i - 1][j] *= 2;
            matrix2[i][j] = 0;
            coord[k++] = i - 1;
            break;
          }
          count++;
        }
      megred_up2:
        i++;
      }
      if (count) {
        break;
      }
    }
    if (count == 0) {
      for (j = 0; j < 4; j++) {
        i = 2, k = 0;
        for (p = 0; p < 4; p++) {
          coord[p] = -1;
        }
        while (i >= 0) {
          while (i >= 0 && matrix2[i][j] == 0) {
            i--;
          }

          if (i < 0) {
            break;
          }
          while (i < 3 && (matrix2[i + 1][j] == 0 ||
                           matrix2[i + 1][j] == matrix2[i][j])) {
            if (matrix2[i + 1][j] == 0) {
              matrix2[i + 1][j] = matrix2[i][j];
              matrix2[i][j] = 0;
              i++;
            } else if (matrix2[i][j] == matrix2[i + 1][j]) {
              for (p = 0; p < 4; p++) {
                if (coord[p] == i + 1) {
                  goto merged_down2;
                }
              }
              matrix2[i + 1][j] *= 2;
              matrix2[i][j] = 0;
              coord[k++] = i + 1;
              break;
            }
            count++;
          }
        merged_down2:
          i--;
        }
        if (count) {
          break;
        }
      }
    }
    if (count == 0) {
      for (i = 0; i < 4; i++) {
        j = 1, k = 0;
        for (p = 0; p < 4; p++) {
          coord[p] = -1;
        }
        while (j < 4) {
          while (j < 4 && matrix2[i][j] == 0) {
            j++;
          }
          if (j >= 4) {
            break;
          }
          while (j > 0 && (matrix2[i][j - 1] == 0 ||
                           matrix2[i][j - 1] == matrix2[i][j])) {
            if (matrix2[i][j - 1] == 0) {
              matrix2[i][j - 1] = matrix2[i][j];
              matrix2[i][j] = 0;
              j--;
            } else if (matrix2[i][j - 1] == matrix2[i][j]) {
              for (p = 0; p < 4; p++) {
                if (coord[p] == j - 1) {
                  goto merged_left2;
                }
              }
              matrix2[i][j - 1] *= 2;
              matrix2[i][j] = 0;
              coord[k++] = j - 1;
              break;
            }
            count++;
          }
        merged_left2:
          j++;
        }
        if (count) {
          break;
        }
      }
    }
    if (count == 0) {
      for (i = 0; i < 4; i++) {
        j = 2, k = 0;
        for (p = 0; p < 4; p++) {
          coord[p] = -1;
        }
        while (j >= 0) {
          while (j >= 0 && matrix2[i][j] == 0) {
            j--;
          }
          if (j < 0) {
            break;
          }
          while (j < 3 && (matrix2[i][j + 1] == 0 ||
                           matrix2[i][j + 1] == matrix2[i][j])) {
            if (matrix2[i][j + 1] == 0) {
              matrix2[i][j + 1] = matrix2[i][j];
              matrix2[i][j] = 0;
              j++;
            } else if (matrix2[i][j + 1] == matrix2[i][j]) {
              for (p = 0; p < 4; p++) {
                if (coord[p] == j + 1) {
                  goto megred_right2;
                }
              }
              matrix2[i][j + 1] *= 2;
              matrix2[i][j] = 0;
              coord[k++] = j + 1;
              break;
            }
            count++;
          }
        megred_right2:
          j--;
        }
        if (count) {
          break;
        }
      }
    }  // daca dupa toate miscarile count ul este 0 inseamna ca nu mai putem
       // face nicio miscare si jocul este pierdut
    if (count) {
      (*game_over) = 0;
    } else {
      (*game_over) = 1;
    }
  }
}
void game(int matrix[][4], int position, int ymax, int xmax, WINDOW *win,
          int condition, int total_score, int score) {
  int keyPress;
  int winner = 0, game_over = 0, condition2 = 0;
  if (position == 4 && condition == 1) {
    // daca position este 4 si conditia este 1 inseamna ca am pornit un joc nou
    // si am dat resume dupa deci dam pozitiei valoarea 2 ca si gand ar fii new
    // game dar condition2 primeste 1 pentru a da skip la actiunile care se fac
    // in mod normal la newgame cum ar fii generarea de 2 nr aleatoare
    position = 2;
    condition2 = 1;
  } else if (position == 4 && condition != 1) {
    // iar daca se da resume fara new game inainte revenim la meniu
    goto noresume;
  }
  if (position == 2) {
    // creeam ferestrele pentru legenda scor si timp
    WINDOW *newwin3 = newwin(2, 30, ymax / 8 - 2, xmax / 8);
    WINDOW *newwin2 = newwin(ymax / 2, xmax / 2, ymax / 8, xmax / 4);
    WINDOW *newwin1 = newwin(ymax / 4, xmax / 8 + 1, ymax / 8, xmax / 8);
    WINDOW *newwin4 = newwin(ymax / 2, xmax / 2, (3 * ymax / 8) + 1, xmax / 8);
    wclear(win);
    wrefresh(win);
    nodelay(newwin1, TRUE);
    box(newwin1, 0, 0);
    int i, j;
    // creeam tabela de joc
    for (i = 1; i < 12; i++) {
      for (j = 0; j <= 20; j++) {
        if (j % 5 == 0) {
          mvwprintw(newwin1, i, j, "|");
        }
        if (i % 3 == 0) {
          mvwprintw(newwin1, i, j, "-");
        }
      }
    }
    wrefresh(newwin1);
    keypad(newwin1, true);
    int t, number = randgenerator(), realx, realy;
    int av[35] = {0}, size = 4, aux[17];
    // daca avem joc nou deci condition2 este 0 ii dam lui aux valori de la 0 la
    // 3 pentru a selecta random prima pozitie adica ii generam random x-ul si
    // y-ul si initializam matricea cu 0
    if (condition2 == 0) {
      for (i = 1; i <= 4; i++) {
        aux[i] = i - 1;
      }
      for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
          matrix[i][j] = 0;
        }
      }

      i = aux[posrand(size)];
      j = aux[posrand(size)];
      // transformam si retinem indicii pozitiei pentru coordonatele corecte
      // pentru tabla iar apoi afisam numarul
      realx = j;
      realy = i;
      matrix[i][j] = number;
      realpositions(&realx, &realy);
      mvwprintw(newwin1, realy, realx, " %d ", number);
      // pentru a genera a 2-a pozitie random folosim un vector in care vom
      // retine coordonatele celulelor libere prima data y apoi x in fuctia
      // check unde retinem si cate perechi sunt in size deoarece vom folosii un
      // vector ca sa generam o pereche random
      for (i = 1; i <= 35; i++) {
        av[i] = 0;
      }
      size = 0;
      check(matrix, av, &size);

      for (i = 1; i <= size; i++) {
        aux[i] = i;
      }
      t = posrand(size);
      i = av[t * 2 - 1];
      j = av[t * 2];
      realx = j;
      realy = i;
      realpositions(&realx, &realy);
      number = randgenerator();
      matrix[i][j] = number;
      mvwprintw(newwin1, realy, realx, " %d ", number);
      wrefresh(newwin1);
      // afisam toate ferestrele indiferent daca e resume sau newgame
      show(matrix, newwin1, &winner);
      show2(newwin2);
      show3(newwin3, total_score, score);
      show4(newwin4);
    } else {
      show(matrix, newwin1, &winner);
      show2(newwin2);
      show3(newwin3, total_score, score);
      show4(newwin4);
    }
    // folosim acest while ca sa vedem daca trec 10 secunde fara vreo mutare dar
    // si sa actualizam timpul in timp real loopstart este pentru a evita
    // folosirea altor taste decat cele mentionate in cerinta
  loopstart:
    keyPress = ERR;
    while (keyPress == ERR) {
      time_skip(newwin1, &keyPress, newwin4, matrix);
      show4(newwin4);
    }
    // cat timp nu se apasa q inseaman ca userul se mai joaca
    while (keyPress != 'q') {
      int coord[4], k = 0, p, through = 0;
      score = 0;
      // daca se foloseste sageata in sus atunci luam un for pentru a trece prin
      // toate coloanele si plecam de la i=1 ca sa putem folosi i-1.Initializam
      // vectorul de coord cu -1 ca sa fie diferit de coordonatele care vor fi
      // retinute.Adaugam in vectorul acesta ,in functie de ce miscare se
      // foloseste, i-ul sau j-ul celulei in care am imbinat 2 dintre ele si
      // verificam la fiecare imbinare daca a mai fost imbinata inainte si
      // astfel evitam imbinarile multiple in aceeasi celula
      //  Algoritmul de  keyup e pe aceeasi idee cu celelalte mutari
      // Cat timp n am iesit din coordonatele matricei cautam prima celula
      // diferita de 0 sau iesim din while daca nu exista.Dupa care cat timp
      // i-ul macar a doua pozitie ,si elementul de dinainte este 0 sau este
      // egal cu el le mutam corespunzator.Avem si through care verifica daca
      // mutarea este posibila si scorul care se mareste cand se imbina 2
      // celule.De asemenea daca a mai fost imbinata anterior folosim goto sa
      // trecem de while

      if (keyPress == KEY_UP) {
        for (j = 0; j < 4; j++) {
          i = 1, k = 0;
          for (p = 0; p < 4; p++) {
            coord[p] = -1;
          }
          while (i < 4) {
            while (i < 4 && matrix[i][j] == 0) {
              i++;
            }

            if (i >= 4) {
              break;
            }
            while (i > 0 && (matrix[i - 1][j] == 0 ||
                             matrix[i][j] == matrix[i - 1][j])) {
              through = 1;
              if (matrix[i - 1][j] == 0) {
                matrix[i - 1][j] = matrix[i][j];
                matrix[i][j] = 0;
                i--;
              } else if (matrix[i][j] == matrix[i - 1][j]) {
                for (p = 0; p < 4; p++) {
                  if (coord[p] == i - 1) {
                    goto megred_up;
                  }
                }
                matrix[i - 1][j] *= 2;
                matrix[i][j] = 0;
                total_score += matrix[i - 1][j];
                score += matrix[i - 1][j];
                coord[k++] = i - 1;

                break;  // Adăugăm break pentru a evita combinări multiple în
                        // aceeași coloană
              }
            }
          megred_up:
            i++;
          }
        }
      } else if (keyPress == KEY_DOWN) {
        for (j = 0; j < 4; j++) {
          i = 2, k = 0;
          for (p = 0; p < 4; p++) {
            coord[p] = -1;
          }
          while (i >= 0) {
            while (i >= 0 && matrix[i][j] == 0) {
              i--;
            }

            if (i < 0) {
              break;
            }
            while (i < 3 && (matrix[i + 1][j] == 0 ||
                             matrix[i + 1][j] == matrix[i][j])) {
              through = 1;
              if (matrix[i + 1][j] == 0) {
                matrix[i + 1][j] = matrix[i][j];
                matrix[i][j] = 0;
                i++;
              } else if (matrix[i][j] == matrix[i + 1][j]) {
                for (p = 0; p < 4; p++) {
                  if (coord[p] == i + 1) {
                    goto merged_down;
                  }
                }
                matrix[i + 1][j] *= 2;
                matrix[i][j] = 0;
                total_score += matrix[i + 1][j];
                score += matrix[i + 1][j];
                coord[k++] = i + 1;

                break;
              }
            }
          merged_down:
            i--;
          }
        }
      } else if (keyPress == KEY_LEFT) {
        for (i = 0; i < 4; i++) {
          j = 1, k = 0;
          for (p = 0; p < 4; p++) {
            coord[p] = -1;
          }
          while (j < 4) {
            while (j < 4 && matrix[i][j] == 0) {
              j++;
            }
            if (j >= 4) {
              break;
            }
            while (j > 0 && (matrix[i][j - 1] == 0 ||
                             matrix[i][j - 1] == matrix[i][j])) {
              through = 1;
              if (matrix[i][j - 1] == 0) {
                matrix[i][j - 1] = matrix[i][j];
                matrix[i][j] = 0;
                j--;
              } else if (matrix[i][j - 1] == matrix[i][j]) {
                for (p = 0; p < 4; p++) {
                  if (coord[p] == j - 1) {
                    goto merged_left;
                  }
                }
                matrix[i][j - 1] *= 2;
                matrix[i][j] = 0;
                total_score += matrix[i][j - 1];
                score += matrix[i][j - 1];
                coord[k++] = j - 1;
                break;
              }
            }
          merged_left:
            j++;
          }
        }
      } else if (keyPress == KEY_RIGHT) {
        for (i = 0; i < 4; i++) {
          j = 2, k = 0;
          for (p = 0; p < 4; p++) {
            coord[p] = -1;
          }
          while (j >= 0) {
            while (j >= 0 && matrix[i][j] == 0) {
              j--;
            }
            if (j < 0) {
              break;
            }
            while (j < 3 && (matrix[i][j + 1] == 0 ||
                             matrix[i][j + 1] == matrix[i][j])) {
              through = 1;
              if (matrix[i][j + 1] == 0) {
                matrix[i][j + 1] = matrix[i][j];
                matrix[i][j] = 0;
                j++;
              } else if (matrix[i][j + 1] == matrix[i][j]) {
                for (p = 0; p < 4; p++) {
                  if (coord[p] == j + 1) {
                    goto megred_right;
                  }
                }
                matrix[i][j + 1] *= 2;
                matrix[i][j] = 0;
                total_score += matrix[i][j + 1];
                score += matrix[i][j + 1];
                coord[k++] = j + 1;

                break;
              }
            }
          megred_right:
            j--;
          }
        }
      } else {
        // daca s a apasat alta tasta ne intoarcem la inceput si nimic nu se va
        // fi intamplat
        goto loopstart;
      }
      if (through == 1) {
        // daca miscarea a fost valida generam un nou element random altfel nu
        for (i = 1; i <= 33; i++) {
          av[i] = 0;
        }
        size = 0;
        check(matrix, av, &size);

        for (i = 1; i <= size; i++) {
          aux[i] = i;
        }

        t = posrand(size);
        i = av[t * 2 - 1];
        j = av[t * 2];
        realx = j;
        realy = i;
        realpositions(&realx, &realy);
        number = randgenerator();
        matrix[i][j] = number;
      }
      show(matrix, newwin1, &winner);
      show3(newwin3, total_score, score);
      show4(newwin4);
      // verificam daca s a castigat la fiecare mutare si verificam si daca se
      // mai poate face vreo mutare sau jocul s a pierdut
      if (winner) {
        break;
      }
      check_game(newwin1, matrix, &game_over);
      if (game_over) {
        break;
      }
      // in aceasta functie se verifica daca se apasa vreo tasta valida in 10
      // secunde sau daca se apasa una valida se transmite inapoi
      time_skip(newwin1, &keyPress, newwin4, matrix);
    }
    if (winner) {
      mvwprintw(newwin4, 0, 0,
                "Ati castigat!Felicitari!\nApasati tasta q pentru a revenii la "
                "meniu!");
      wrefresh(newwin4);
    before1:
      keyPress = wgetch(newwin1);
      if (keyPress != 'q') {
        goto before1;
      }
    }
    if (game_over) {
      mvwprintw(newwin4, 0, 0,
                "Ati Pierdut!Mai mult noroc data viitoare!\nApasati tasta q "
                "pentru a revenii la meniu");
      wrefresh(newwin4);
    before2:
      keyPress = wgetch(newwin1);
      if (keyPress != 'q') {
        goto before2;
      }
    }
    if (keyPress == 'q') {
      wclear(newwin1);
      wrefresh(newwin1);
      wclear(newwin2);
      wrefresh(newwin2);
      wclear(newwin3);
      wrefresh(newwin3);
      wclear(newwin4);
      wrefresh(newwin4);
    noresume:
      menu(ymax, xmax, matrix, total_score, score, condition);
    }
  }
}
void menu(int ymax, int xmax, int matrix[][4], int total_score, int score,
          int started) {
  // creeam fereastra pentru meniu facem un box si butoanele
  WINDOW *win = newwin(ymax / 4, xmax / 4, ymax / 8, ymax / 8);
  refresh();
  box(win, 0, 0);
  int position = 2, keyPress = 0;
  keypad(win, true);
  noecho();
  curs_set(0);
  // cat timp nu se apasa enter pentru a selecta una dintre comenzi
  while (keyPress != 10) {
    // daca position este 2 folosim atributul sa adaugam efectul de inversare a
    // culorii de la scris cu cea de fundal ca sa reprezentam ce este selectat
    // in momentul respectiv
    // De asemenea functia Arrow verifica ce optiune este selectata si ii pune o
    // sageata in dreapta
    if (position == 2) {
      wattron(win, A_REVERSE);
      mvwprintw(win, 2, 15, "New Game");
      wattroff(win, A_REVERSE);
    } else {
      mvwprintw(win, 2, 15, "New Game");
    }
    Arrow(2, position, win);
    if (position == 4) {
      wattron(win, A_REVERSE);
      mvwprintw(win, 4, 15, "Resume");
      wattroff(win, A_REVERSE);
    } else {
      mvwprintw(win, 4, 15, "Resume");
    }
    Arrow(4, position, win);
    if (position == 6) {
      wattron(win, A_REVERSE);
      mvwprintw(win, 6, 15, "Quit");
      wattroff(win, A_REVERSE);
    } else {
      mvwprintw(win, 6, 15, "Quit");
    }
    Arrow(6, position, win);
    wrefresh(win);
    // verificam ce taste au fost apasate si de asemenea daca suntem la limita
    // meniului si adaugam sau scadem la position pt a trece la urmatoarea
    // optiune
    keyPress = wgetch(win);
    if (keyPress == KEY_DOWN && position != 6) {
      position += 2;
    } else if (keyPress == KEY_UP && position != 2) {
      position -= 2;
    } else if (keyPress == KEY_DOWN && position == 6) {
      position = 2;
    } else if (keyPress == KEY_UP && position == 2) {
      position = 6;
    } else {
      position = position;
    }
  }
  // daca position este 6 inseamna ca s a selectat quit si terminam programul
  if (position == 6) {
    wclear(win);
    endwin();
  }
  // daca position este 2 atunci inseamna ca  s a selectat newgame si deci dam
  // valoarea 0 la score si totalscore si started devine 1 ca sa avem un indice
  // pt resume sa nu se poata selecta pana nu a fost pornit un joc nou
  if (position == 2) {
    total_score = 0;
    score = 0;
    started = 1;
  }
  game(matrix, position, ymax, xmax, win, started, total_score, score);
}
int main() {
  int ymax, xmax;
  int matrix[4][4];
  int score = 0, total_score = 0, started = 0;
  // ncurses start
  initscr();
  // setam seedul pt functia rand
  srand(time(NULL));
  // pornim sistemul de culori din ncurses
  start_color();
  // luam xmax si ymax de la standard screen pentru a putea construi ferestrele
  // necesare
  getmaxyx(stdscr, ymax, xmax);
  menu(ymax, xmax, matrix, total_score, score, started);
  endwin();
  return 0;
}
