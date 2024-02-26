#include <stdio.h>
#include <stdbool.h>

#define n 6
#define m 4

int alloc[n][m] = { { 0, 1, 0, 3}, // P0
                    { 2, 0, 0, 3}, // P1
                    { 3, 0, 2, 0}, // P2
                    { 2, 1, 1, 5}, // P3
                    { 0, 0, 2, 2}, // P4
                    { 1, 2, 3, 1}  // P5
};

int max[n][m] = {   { 6, 4, 3, 4 },
                    { 3, 2, 2, 4 }, 
                    { 9, 1, 2, 6 }, 
                    { 2, 2, 2, 8 }, 
                    { 4, 3, 3, 7 }, 
                    { 6, 2 ,6, 5 }
}; 

int avail[m] = { 2, 2, 2, 1 };

int main()
{
	int end[n];
	int need[n][m];
    int arr[n];
    int count = 0;

	for (int k = 0; k < n; k++){
		end[k] = 0;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	for (int k = 0; k < 5; k++){
		for (int i = 0; i < n; i++){
			if (end[i] == 0) 
			{
				bool flag = false;

				for (int j = 0; j < m; j++){
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0) 
				{
					arr[count++] = i;
					for (int pro = 0; pro < m; pro++){
						avail[pro] += alloc[i][pro];
					}
					end[i] = 1;
				}
			}
		}
	}

	bool condition = true;

	for(int i = 0; i < n; i++){
        if(end[i] == 0)
        {
            condition = false;
            printf("Not Safe");
            break;
        }
	}
	if(condition == true)
	printf("Safe Sequence: ");
	{
	for (int i = 1; i < n; i++){
		printf("P%d -> ", (arr[i-1]));
	}
	printf("P%d\n", (arr[n - 1]));
	}
}