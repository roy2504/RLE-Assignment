#include "Buffer.h"
//Gitesh - DSA - Assignment 5


int main() {
	// Define input data for testing
	char input1[] = "aaaaaaabbbbbbbcccccccddddddddddeeeeeee";
	char input2[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	char output[BUFFER_SIZE]; // Buffer to store compressed data

	// Test case 1: Compresses well
	printf("Test Case 1:\n");
	printf("Original input: ");
	print_buffer(input1, strlen(input1));
	printf("Original length: %zu\n", strlen(input1));

	// Encode the input using RLE
	int encoded_length = rle_encode(input1, output, ESCAPE_CHAR);
	if (encoded_length != -1) {
		printf("Encoded output: ");
		print_buffer(output, encoded_length);
		printf("\nEncoded Length: %d \n", encoded_length);

		// Decode the encoded data
		char decoded_output[BUFFER_SIZE];
		int decoded_length = rle_decode(output, decoded_output, ESCAPE_CHAR);
		printf("Decoded output: ");
		print_buffer(decoded_output, decoded_length);
		printf("\nDecoded length: %d\n", decoded_length);
	}
	else {
		printf("Error: Compression failed. \n");
	}

	// Test case 2: Does not compress
	printf("\nTest Case 2:\n");
	printf("Original input: ");
	print_buffer(input2, strlen(input2));
	printf("Original Length: %zu\n", strlen(input2));

	// Encode the input using RLE
	int encoded_length2 = rle_encode(input2, output, ESCAPE_CHAR);
	if (encoded_length2 != -1) {
		printf("Encoded output: ");
		print_buffer(output, encoded_length2);
		printf("\nEncoded length: %d\n", encoded_length2);

		// Decode the encoded data
		char decoded_output2[BUFFER_SIZE];
		int decoded_length2 = rle_decode(output, decoded_output2, ESCAPE_CHAR);
		printf("Decoded output: ");
		print_buffer(decoded_output2, decoded_length2);
		printf("\nDecoded length: %d\n", decoded_length2);
	}
	else {
		printf("Error: Compression failed.\n");
	}

	printf("\n");
	return 0;
}
