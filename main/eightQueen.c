#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int QUEEN = 8;                                       
#define ROW QUEEN
#define COL QUEEN   

//use a 'Place' array to save each queen positon(only record the columns),
//data in array will be overrided by following steps
//use an extra variable to record solution nums


void Placement(int Queen,int Place[]){     
    int col = -1;                                    
    while(++col < COL){

        // check whether the queen is safe
        // from fist row to the current row
        int row = -1;
        while(++row < Queen)
            if(col == Place[row] || abs(Queen - row) == abs(col - Place[row]))break;

        // deal with the safe queen
        if(row == Queen){                          
            Place[Queen] = col;   

            //find a solution
            if(Queen == ROW -1){                    
                ++Place[QUEEN];
                for(row = 0;row < QUEEN;row++)
	    printf("(%d,%d) ",row+1,Place[row]+1);
                printf("\n");
            }else Placement(Queen + 1,Place);
       }
    }
}

int main(int argc,char *argv[]){ 
    int opt;
    while ((opt = getopt(argc,argv,":n:h")) != -1) {
        switch (opt) {
            case 'n':
	QUEEN = atoi(optarg);
                break;
            case ':':
	printf("Error : -%c option needs a number.\n",optopt);
	exit(-1);
                break;
            case 'h':
	printf("option list.\n");
	printf("-h   --help  : list this menu.\n");
	//printf("-p   --print : print all solutions.\n");
	printf("-n   --num   : specify the queen nums.\n");
	exit(0);
	break;
            case '?':
	printf("Error : unknown option -%c\n",optopt);
	printf("use -h option to see more.\n");
	exit(-2);
	break;
        }
    }

    //Place[QUEEN] is to save solution nums
    int *Place = malloc(sizeof(int) * QUEEN);
    for (int i = 0;i < QUEEN+1;i++)
        Place[i] = 0;
    
    Placement(0,Place);
    printf("%d Queen has %d solutions.\n",QUEEN,Place[QUEEN]);
    system("pause");
}
