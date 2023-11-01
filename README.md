# Huffman Codification Algorithm

This project implements the Huffman Algorithm, a popular method for lossless data compression. The program reads a text file, analyzes the character frequencies, and creates a binary tree to represent the variable-length codification of each character. This results in shorter binary codes for more frequent characters, leading to efficient data compression.

## How It Works

1. **Character Frequency Analysis**: The program reads a text file and counts the frequency of each character.

2. **Building the Huffman Tree**: Based on the character frequencies, the program constructs a binary tree where more frequent characters have shorter codewords.

3. **Generating Codewords**: The Huffman Tree is used to generate unique binary codewords for each character.

4. **Example**:
   - Input Text: "aaaaaabbbc"
   - Character Frequencies: (a->6), (b->3), (c->1)
   - Huffman Tree:
     ```
                (a->6)
        ( ->10)
                (b->3)
            ( ->4)
                (c->1)
     ```

## How to Use

1. Clone this repository to your local machine.
2. Run the program and provide a text file as input.

```bash
./huffman file_name_without_extension
```

The program will analyze the text file, create the Huffman Tree, and display the results, including the character frequencies and their corresponding binary codewords.

Soon it will actually compacts a file!

## Author

This project was created by me :D.