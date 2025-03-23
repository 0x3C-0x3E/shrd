# shrd
shrd is a very easy to crack tool to encrypt and decrypt files, written in pure C

## Usage ##

# Generate Key
```
./shrd genkey <output_file.key>
```
> the output file is not required it will just save as 0.key

# Encrypt File
```
./shrd enc <input_file.key> <mykey.key>
```

# Decrypt File
```
./shrd dec <input_file.key> <mykey.key>
```
