#include <stdio.h> 

int main() {
	for(int n, m; scanf("%d %d", &n, &m) == 2;) { 
		char g[505][505] = {}; 
		int sx, sy, x, y;
		int i, j;
		scanf("%d %d", &sx, &sy); 
		for(i = 1; i < m; i++) {
			scanf("%d %d", &x, &y); 
			while(sx != x || sy != y) {
				g[sx][sy] = ' '; 
				if(sx < x)	sx++;
				if(sx > x)	sx--;
				if(sy < y)	sy++;
				if(sy > y)	sy--;
			}
			g[sx][sy] = 1;
		}
		for(i = 0; i <= n+1; i++)
			putchar('-');     
		puts("");
		for(i = 1; i <= n; i++, puts("")) {
			putchar('|');    
			for(j = 1; j <= n; j++)
				printf("%c", g[i][j] ? '*' : ' ');  
			putchar('|');   
		}		
		for(i = 0; i <= n+1; i++)
			putchar('-');  
		puts("");
	}
	return 0;
}