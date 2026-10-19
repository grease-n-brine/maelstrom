# Maelstrom

A lightweight, modular C++ file bit scrambler utilizing a symmetric binary XOR cipher.

## Compilation

        g++ main.cpp maelstrom.cpp -o maelstrom

## Usage

**1. Scrambling:**

        ./maelstrom <file_path> <encryption_key>


**2. Unscrambling:**

        ./maelstrom <file_path> <encryption_key>

## ⚠️ Important Note

This tool relies on symmetric byte transformation. If you lose or forget the key, the process cannot be reversed, and the file cannot be recovered.
