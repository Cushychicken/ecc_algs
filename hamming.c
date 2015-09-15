#include <stdio.h>

int byte_parity(unsigned char word);
int column_parity(unsigned char *data);

int main(int argc, char *argv[])
{
	FILE *file_in;
	unsigned char data[512] = {};
	unsigned char col_parity = 0;
	int i = 0;

	// Read Data In
	file_in = fopen(argv[1], "rb");
	fread(&data, sizeof(unsigned char), 512, file_in);
	fclose(file_in);

	for (i = 0; i < 10; i++) {
		printf("Number %d: %d\n", i, data[i]);
		byte_parity(data[i]);
	}

	return 0;
}

int byte_parity(unsigned char word)
{
	int i  = 0; 
	unsigned char parity;

	printf("Starting word: %x\n", word);
	for (i = 0; i < 8; i++) {
		printf("word %d:   %x\n", i, ((word >> i) & 0x01));
		parity ^= ((word >> i) & 0x01);
		printf("parity %d: %x\n\n", i, parity);
	}

	return 0;
}

