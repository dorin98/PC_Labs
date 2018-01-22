#include <stdio.h>
#include <stdlib.h>

char ***alloc3D(int x, int y, int z)
{
    char ***the_array = calloc(x, sizeof(char**));
    for(int i = 0 ; i < x ; ++i)
    {
        the_array[i] = calloc(y, sizeof(char*));

        for(int j = 0; j < y; ++j)
        {
            the_array[i][j] = calloc(z, sizeof(char));

            for(int k = 0 ; k < z ; ++k)
            {
                the_array[i][j][k]= '0';
            }
        }
    }
    return the_array;
}

int inSpace(int x1, int y1, int z1, int x, int y, int z)
{
	return 0 <= x1 && x1 < x && 0 <= y1 && y1 < y && 0 <= z1 && z1 < z;
}

int main()
{
	char ***bombSpace;
	int x, y, z, N;
	int di[]={-1, -1, -1, 0, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 1, 1, 1, -1, -1, -1, 0, 0, 0, 1, 1, 1}, 
	dj[]={-1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1, -1, 0, 1}, 
	dk[]={-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0 ,0 ,0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	scanf("%d %d %d", &x, &y, &z);
	bombSpace = alloc3D(x, y, z);
	scanf("%d", &N);
	for (int i = 0 ; i < N ; ++i)
	{
		int x1, y1, z1;
		scanf("%d %d %d", &x1, &y1, &z1);
		if (inSpace(x1,y1,z1,x,y,z)) bombSpace[x1][y1][z1] = '1';
	}
	for (int i = 0 ; i < x ; ++i)
		for (int j = 0 ; j < y ; ++j)
			for (int k = 0 ; k < z ; ++k)
				if (bombSpace[i][j][k]=='0')
				{
					int k_bombs = 0;
					for (int cnt = 0 ; cnt < 26 ; ++cnt)
					{
						int xv = i + di[cnt], yv = j + dj[cnt], zv = k + dk[cnt];
						if (inSpace(xv,yv,zv,x,y,z) && bombSpace[xv][yv][zv] == '1')
							++k_bombs;
					}
					printf("Pentru cubul de coordonare (%d,%d,%d) numarul de bombe vecine este: %d\n", i, j, k, k_bombs);
				}
}