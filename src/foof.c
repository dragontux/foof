#include <stdio.h>
#include <inc/processor.h>

void print_help( ){
	printf(
		"Usage: foof -[h]\n"
		"	-h: view this help message\n"
	);
}

int main( int argc, char *argv[] ){
	print_help( );
	return 0;
}
