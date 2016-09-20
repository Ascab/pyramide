#include "pyramide.h"

int main ()
{
    int psize, nb_start;
    int tab[TAILLE][TAILLE];
    
    do
    {
        do
        {
            printf("De quelle taille voulez-vous que votre pyramide fasse ?\t");
            scanf("%d", &psize);
        }while(psize <= 0);
        
        printf("Quel sera votre nombre de départ ?\t");
        scanf("%d", &nb_start);
        
        ft_make_pyramide(tab, psize, nb_start);
        ft_print_pyramide(tab, psize);
        
    }while(ft_continuer("Voulez vous refaire une autre pyramide? [Y/N]"));
    return 0;
}

void ft_make_pyramide(int tab[TAILLE][TAILLE], int nb_lines, int nb_start)
{
    int i, j;
    
    tab[0][0] = nb_start ; 
    
    for(i = 1 ; i < nb_lines ; i++)
    {
        for(j = 0 ; j <= i*2 ; j++)
        {
            if((j == 0) || (j == 2 * i))
                tab[i][j] = ft_calc_side(tab, i, j);
            else
                tab[i][j] = tab[i-1][j-1];
        }
    }
}

int ft_calc_side(int tab[TAILLE][TAILLE], int row, int col)
{
    int i, nb_side;
    
    nb_side = (row - 1) * 2 + 1;
    for(i = 0 ; i <= row * 2 ; i++)
    {
        nb_side = nb_side + tab[row-1][i];
    }
    return (nb_side % 10);
}
void ft_print_pyramide(int tab[TAILLE][TAILLE], int nb_lines)
{
    int i, j, k;
    
    for(i = 0 ; i < nb_lines ; i++)
    {
        k = 0;
        while(k < nb_lines - i)
        {
            printf(" ");
            k++;
        }
        for (j = 0 ; j <= 2 * i ; j++)
            printf("%d", tab[i][j]);
            
        printf("\n");   
    }
}