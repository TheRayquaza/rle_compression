# RLE compression (Run Length Encoding)

## What is the rle compression ?
The RLE compression which stands for Run Length Enconding, 
This program allows you to compress your files and works really well for files where repeated characters appear.

## What result ?
For file with a content : 'AAABBBCCC', the result would be '3A3B3C'.

## How it works ?
You just have to run 'rle' followed by the file.
Then the program will ask to you to compress or decompress your file.

## Configuration

### Clone
Firstly clone the project :

```git clone https://github.com/TheRayquaza95/rle_compression.git```

### Install
Then, you have to run the installation shell script which will just copy the 'rle' build file from the build folder.

```sh
cd rle_compression/install
./install.sh
```

### Uninstall
To uninstall the program, you just have to remove the rle program from the /usr/bin folder or just run the shell script located in the 'build' folder.

```sh
cd rle_compression/install
./uninstall.sh
```

## Roadmap

* [x] Basics
  * [x] Compression
  * [x] Decompression
  * [x] Utils
* [ ] Bugs
  * [x] Basic bugs
  * [ ] Full support
  * [ ] Memory leaks
* [x] Cross-platform
  * [ ] Installation program
  * [x] Program
