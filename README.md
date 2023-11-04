# Huffman Codification Algorithm

This project implements the Huffman Algorithm, a popular method for lossless data compression. The program reads a text file, analyzes the character frequencies, and creates a binary tree to represent the variable-length codification of each character. This results in shorter binary codes for more frequent characters, leading to efficient data compression.

## How It Works

1. **Character Frequency Analysis**: The program reads a text file and counts the frequency of each character.

2. **Building the Huffman Tree**: Based on the character frequencies, the program constructs a binary tree where more frequent characters have shorter codewords.

3. **Generating Codewords**: The Huffman Tree is used to generate unique binary codewords for each character.

## How to Use

1. Clone this repository to your local machine.
2. Run the program and provide a text file as input.

```bash
./huffman file_name_without_extension
```

The program will analyze the text file, compress it into another file with the encoded text, and can decompress the same compressed file into another txt file with the same text as the original. 

## Author

This project was created by me :D.
