#include "Buffer.h"

//Gitesh - DSA - Assignment 5

// RLE encoding function
int rle_encode(const char* input, char* output, char escape_char)
{
	int input_len = strlen(input);
	int output_len = 0;

	// Loop through the input string
	for (int i = 0; i < input_len; i++) {
		char current_char = input[i];
		int count = 1;

		// Count consecutive occurrences of the same character (up to 127 repetitions)
		while (i + 1 < input_len && input[i] == input[i + 1] && count < 127) {
			count++;
			i++;
		}

		// If the count is greater than 3 or the current character is the escape character,
		// use RLE encoding for this segment, otherwise, copy the character as-is
		if (count > 3 || current_char == escape_char) {
			output[output_len++] = escape_char;
			output[output_len++] = count;
			output[output_len++] = current_char;
		}
		else {
			// Copy the character as many times as its count
			for (int j = 0; j < count; j++) {
				output[output_len++] = current_char;
			}
		}
	}

	// Null-terminate the output string
	output[output_len] = '\0';
	return output_len;
}

// RLE decoding function
int rle_decode(const char* input, char* output, char escape)
{
	int input_len = strlen(input);
	int output_len = 0;

	// Loop through the input string
	for (int i = 0; i < input_len; i++)
	{
		char current_char = input[i];

		// Check if the current character is the escape character
		if (current_char == escape)
		{
			// Retrieve the count and the character to repeat
			int count = input[i + 1];
			char repeat = input[i + 2];

			// Repeat the character count times in the output string
			for (int j = 0; j < count; j++) {
				output[output_len++] = repeat;
			}
			i += 2; // Skip the count and repeat character
		}
		else {
			// Copy the character as-is to the output string
			output[output_len++] = current_char;
		}
	}

	// Null-terminate the output string
	output[output_len] = '\0';
	return output_len;
}

// function to print the buffer
void print_buffer(const char* buffer, int length) {
	for (int i = 0; i < length; i++) {
		char current_char = buffer[i];

		if (current_char == ESCAPE_CHAR) {
			// If the character is the escape character, print the count and character
			printf("?%d'%c'", buffer[i + 1], buffer[i + 2]);
			i += 2; // Skip the count and repeat character
		}
		else {
			// Print the character as-is
			printf("%c", current_char);
			
		}
	}

}
