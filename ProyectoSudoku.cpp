// Sudoku por backtracking
#include <bits/stdc++.h>
using namespace std;
 
// *UNASSIGNED se usa para las celdas vacias
#define UNASSIGNED 0
 
// N se usa para el tamanio del sudoku
// El tamanio sera de NxN
#define N 9
int grid[N][N];

void printGrid(int arr[N][N])
{
     for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
             printf("%d ",arr[i][j]);
             if (j==2 || j==5 || j==8) printf("    ");
         }

        if (i==2 || i==5 || i==8) printf("\n\n");
      printf("\n");

       }
}


void crearSudoku()
{
  int i,j,aux;
      srand(time(0)); /*Establece que el origen de los numeros rand() seran el numero de segundos sucedidos entre el anyo Nuevo de 1970 hasta hoy: time(0)*/
  grid[0][0] = (rand()%(9))+1; /*Para obtener un entero entre 0 y 8, sacamos el resto (con el operador %) de un aleatorio entre 9, dando un numero entre 0 y 8. Le sumamos 1 para que sea entre 1 y 9 en numero resultante*/
  do aux = (rand()%(9)) + 1;
      while(aux == grid[0][0]); /*Se busca un numero aleatorio que NO sea igual al anterior*/
  grid[0][1] = aux;
  do aux = (rand()%(9))+1;
      while(aux == grid[0][0] || aux == grid[0][1]);/*Se busca un numero aleatorio que NO sea igual que los anteriores*/
  grid[0][2] = aux;
  do aux = (rand()%(9))+1;
      while(aux == grid[0][0] || aux == grid[0][1] || aux == grid[0][2]);
  grid[1][0] = aux;
  do aux = (rand()%(9))+1;
      while(aux == grid[0][0] || aux == grid[0][1] || aux == grid[0][2] || aux == grid[1][0]);
  grid[1][1] = aux;
  do aux = (rand()%(9))+1;
      while(aux == grid[0][0] || aux == grid[0][1] || aux == grid[0][2] || aux == grid[1][0] || aux == grid[1][1]);
  grid[1][2] = aux;
  do aux = (rand()%(9))+1;
      while(aux == grid[0][0] || aux == grid[0][1] || aux == grid[0][2] || aux == grid[1][0] || aux == grid[1][1] || aux == grid[1][2]);
  grid[2][0] = aux;
  do aux = (rand()%(9))+1;
      while(aux == grid[0][0] || aux == grid[0][1] || aux == grid[0][2] || aux == grid[1][0] || aux == grid[1][1] || aux == grid[1][2] || aux == grid[2][0]);
  grid[2][1] = aux;
  do aux = (rand()%(9))+1;
      while(aux == grid[0][0] || aux == grid[0][1] || aux == grid[0][2] || aux == grid[1][0] || aux == grid[1][1] || aux == grid[1][2] || aux == grid[2][0] || aux == grid[2][1]);
  grid[2][2] = aux;
  /*Se rellenan los dos cuadros que quedan de arriba*/
  grid[1][3]=grid[0][0];
  grid[1][4]=grid[0][1];
  grid[1][5]=grid[0][2];

  grid[2][6]=grid[0][0];
  grid[2][7]=grid[0][1];
  grid[2][8]=grid[0][2];

  grid[2][3]=grid[1][0];
  grid[2][4]=grid[1][1];
  grid[2][5]=grid[1][2];

  grid[0][6]=grid[1][0];
  grid[0][7]=grid[1][1];
  grid[0][8]=grid[1][2];

  grid[0][3]=grid[2][0];
  grid[0][4]=grid[2][1];
  grid[0][5]=grid[2][2];

  grid[1][6]=grid[2][0];
  grid[1][7]=grid[2][1];
  grid[1][8]=grid[2][2];

  /*Se rellenan los cuadros de la izquierda*/
  grid[3][1]=grid[0][0];
  grid[4][1]=grid[1][0];
  grid[5][1]=grid[2][0];

  grid[6][2]=grid[0][0];
  grid[7][2]=grid[1][0];
  grid[8][2]=grid[2][0];

  grid[3][2]=grid[0][1];
  grid[4][2]=grid[1][1];
  grid[5][2]=grid[2][1];

  grid[6][0]=grid[0][1];
  grid[7][0]=grid[1][1];
  grid[8][0]=grid[2][1];

  grid[3][0]=grid[0][2];
  grid[4][0]=grid[1][2];
  grid[5][0]=grid[2][2];

  grid[6][1]=grid[0][2];
  grid[7][1]=grid[1][2];
  grid[8][1]=grid[2][2];

  /* Se rellena el cuadro central y derecho-centro*/
  grid[3][3]=grid[5][0];
  grid[3][4]=grid[5][1];
  grid[3][5]=grid[5][2];

  grid[4][6]=grid[5][0];
  grid[4][7]=grid[5][1];
  grid[4][8]=grid[5][2];

  grid[5][3]=grid[4][0];
  grid[5][4]=grid[4][1];
  grid[5][5]=grid[4][2];

  grid[3][6]=grid[4][0];
  grid[3][7]=grid[4][1];
  grid[3][8]=grid[4][2];

  grid[5][6]=grid[3][0];
  grid[5][7]=grid[3][1];
  grid[5][8]=grid[3][2];

  grid[4][3]=grid[3][0];
  grid[4][4]=grid[3][1];
  grid[4][5]=grid[3][2];

  /* Se rellena el cuadro central y derecho-centro*/
  grid[6][3]=grid[8][0];
  grid[6][4]=grid[8][1];
  grid[6][5]=grid[8][2];

  grid[7][6]=grid[8][0];
  grid[7][7]=grid[8][1];
  grid[7][8]=grid[8][2];

  grid[8][3]=grid[7][0];
  grid[8][4]=grid[7][1];
  grid[8][5]=grid[7][2];

  grid[6][6]=grid[7][0];
  grid[6][7]=grid[7][1];
  grid[6][8]=grid[7][2];

  grid[8][6]=grid[6][0];
  grid[8][7]=grid[6][1];
  grid[8][8]=grid[6][2];

  grid[7][3]=grid[6][0];
  grid[7][4]=grid[6][1];
  grid[7][5]=grid[6][2];



            for (i=0;i<=8;i++) {
            for (j=0;j<=8;j++) {
                    if ( (rand()%81)>30 )
                    {
                      int valor= grid[i][j];
                      grid[i][j]=valor;
                    }
         else
           {
		   	grid[i][j]= 0;
           }
            }
            }

            printf(" -- S U D O K U   A   R E S O L V E R -- \n\n");
            printGrid(grid);

}
 
// esta funcion encuenrtra un espacio en la tabla que no este asignado
bool FindUnassignedLocation(int grid[N][N],
                            int& row, int& col);
 
// revisa si se puede asignar un numero a la fila o columna
bool isSafe(int grid[N][N], int row,
            int col, int num);
 
/* Toma un sudoku parcialmente resuelto e intenta completarlo cumpliendo con los 
criterios para la solucion de este */
bool SolveSudoku(int grid[N][N])
{
    int row, col;
 
    // Si no hay un espacio sin asignar, esta terminado
    if (!FindUnassignedLocation(grid, row, col))
        // success!
        return true;
 
    // Considera los digitos del 1 al 9
    for (int num = 1; num <= 9; num++) 
    {
         
        // Revisa si se puede rellenar
        if (isSafe(grid, row, col, num)) 
        {
             
            // Ingresa un numero tentativo
            grid[row][col] = num;
    
 
            // Regresa si hay exito
            if (SolveSudoku(grid))
                return true;
 
            // Si falla lo deshace y vuelve a intentar
            grid[row][col] = UNASSIGNED;
        
        }
    }
    
    // Esto acciona el backtracking
    return false;
}
 
/* .Busca un espacio que este sin asignar, si lo encuentra, 
los parametros de fila y columna se colocan y devuelve 
un TRUE, de lo contrario devuelve un FALSE */

bool FindUnassignedLocation(int grid[N][N],
                            int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}
 
/* Indica si el numero especificado ya fue usado en el mismo renglon */
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Indica si el numero indicado ya fue usado en la misma columna */
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
 
/* Indica si el numero usado ya fue asignado en un espacio de 3x3 */
bool UsedInBox(int grid[N][N], int boxStartRow,
               int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow]
                    [col + boxStartCol] ==
                                       num)
                return true;
    return false;
}
 
/* Indica si es seguro asignar el numero en esa fila y columna */
bool isSafe(int grid[N][N], int row,
            int col, int num)
{
    /* Revisa si el numero no esta ya colocado en un espacio de 3x3 */
    return !UsedInRow(grid, row, num)
           && !UsedInCol(grid, col, num)
           && !UsedInBox(grid, row - row % 3,
                         col - col % 3, num)
           && grid[row][col] == UNASSIGNED;
}
 

 

int main()

{
   
    crearSudoku();
    cout << "\n ----------------------------------------------------------------------\n\n";
    system("pause");
    if (SolveSudoku(grid) == true){
	    cout << "\n\n";
        printGrid(grid);}
       
    else
        cout << "No solution exists";
 
    return 0;
}
 
//fuentes: https://opengl-esp.superforo.net/t12-ejemplo-de-c-ns-aleatorios-generador-de-sudokus
//fuentes: https://www.geeksforgeeks.org/sudoku-backtracking-7/?ref=lbp
