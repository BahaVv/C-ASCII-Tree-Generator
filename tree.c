//this program takes in an odd-numbered integer and two characters, and uses them to generate a tree. The integer is base size. The first char is trunk character. The second is leaf.


#include <stdio.h>
#include <stdlib.h>

int validInput(int argc, char** argv);//function that checks for valid input
char* genTree(int baseSize, char trunkchar, char leafchar);

int main(int argc, char** argv){
    if(validInput(argc, argv) != 1){
		return 0;
	}
	char* tree= genTree(atoi(argv[1]), argv[2][0], argv[3][0]);
	printf("%s", tree);
}


int validInput(int argc, char** argv){
	if (argc != 4 
		|| atoi(argv[1]) < 3 
		|| atoi(argv[1]) > 21 
		|| atoi(argv[1]) %2 != 1 
		|| argv[2][0] < 33 
		|| argv[2][0] > 126 
		|| argv[3][0] < 33 
		|| argv[2][0] > 126){
			printf("Hey, you haven't given me the correct input.\nLike, at all.\nI need an integer and two characters, space separated.\nTry harder next time.\nI'm probably about to segfault, aren't I?\n");
			printf("arg1: %d (should be an integer between 3 and 21)\narg2: %s (should be ASCII character)\narg3: %s (should be ASCII character)\n", atoi(argv[1]), argv[2], argv[3]);
			printf("%d\n", argc);
			return 0;
	}
	return 1;
}


char* genTree(int baseSize, char trunk, char leaf){//this is going to be ugly
	int numChar = 1;
	int numSpaces = (baseSize - 1) / 2;
	int pos = 0;
	char* tree = calloc(1, 300);//or malloc(300)
	while (numSpaces >= 0){//iterate from top to bottom, increasing character amount by 2 each time until original input is reached
		for (int spaces = numSpaces; spaces>0; spaces--){//add first round of spaces
			tree[pos] = ' ';
			pos++;
		}
		for (int charNum = numChar; charNum>0; charNum--){//add characters
			tree[pos] = leaf;
			pos++;
		}
		for (int spaces = numSpaces; spaces>0; spaces--){//add second round of spaces
			tree[pos] = ' ';
			pos++;
		}
        tree[pos] = '\n';
		pos++;
		numSpaces -= 1;
		numChar += 2;
	}
	numSpaces = (baseSize - 3) / 2; //time to print the base!
	for (int spaces = numSpaces; spaces>0; spaces--){
		tree[pos] = ' ';
		pos++;
	}
	for (int i = 0; i < 3; i++){
		tree[pos] = trunk;
		pos++;
	}
	for (int spaces = numSpaces; spaces>0; spaces--){
		tree[pos] = ' ';
		pos++;
	}
	tree[pos] = '\n';
    return tree;
}
