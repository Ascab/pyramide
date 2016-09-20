#ifndef PYRAMIDE_H
#define PYRAMIDE_H

#include <stdlib.h>
#include <stdio.h>

#define TAILLE 100

int ft_continuer(const char *str);
void ft_make_pyramide(int tab[TAILLE][TAILLE], int nb_lines, int nb_start);
int ft_calc_side(int tab [TAILLE][TAILLE], int row, int col);
void ft_print_pyramide(int tab[TAILLE][TAILLE], int nb_lines);

#endif