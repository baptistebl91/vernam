
**Homework on generating a key to encode and decode a message**:

To compile the program:

```
gcc -o vernam vernam.c
```

**Usage Advice**:

Running `./vernam` alone will show how to use the program, what arguments to enter on the command line, and how to launch the program.

The files `<key_file>`, `<encoded_msg_file>`, and `<decoded_msg_file>` will be generated during the execution of the program, so they are not present on its GitHub page.

First, run the code with the option to generate a key: the -k option.

Once the key is generated, encode the original message with the -c option, using `<msg_file>` and `<key_file>`. The encoded message will be placed in `<encoded_msg_file>`.

Finally, decode the encoded message with the -d option, using `<encoded_msg_file>` and `<key_file>`. The decoded message will be placed in `<decoded_msg_file>`.

**To launch the program**:

- `./vernam -k <msg_file> <key_file>` -> Generates an encryption key based on the message in `<msg_file>` and stores the key in `<key_file>`.
- `./vernam -c <msg_file> <key_file> <encoded_msg_file>` -> Generates an encoded message from the message in `<msg_file>` and the key in `<key_file>` and stores the encoded message in `<encoded_msg_file>`.
- `./vernam -d <encoded_msg_file> <key_file> <decoded_msg_file>` -> Generates a decoded message from the message in `<encoded_msg_file>` and the key in `<key_file>` and stores the decoded message in `<decoded_msg_file>`.

**Program Limitations**:

For the encryption algorithm to work, the key size must be greater than or equal to the message size. This is not practical when encrypting large messages as a key of the same size as the message is required for decoding. The program was tested with a "lorem ipsum" text of 500 words, and I did not experience any significant slowdowns during the encoding and decoding of the message. The computation time was instantaneous, and the file containing the decoded message `<decoded_msg_file>` is generated in one go.
