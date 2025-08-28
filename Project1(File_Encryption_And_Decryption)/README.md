# File_Encryption_And_Decryption

> _aka_ **Text File Encryption and Decryption (File I/O)**  
> A lightweight CLI tool in **C** that encrypts and decrypts text files using a simple XOR-based cipher.

<p align="center">
  <img alt="C Badge" src="https://img.shields.io/badge/C-Programming-00599C" />
  <img alt="License" src="https://img.shields.io/badge/License-MIT-green" />
  <img alt="Build" src="https://img.shields.io/badge/build-gcc%20%7C%20clang-informational" />
</p>

---

## ✨ Features
- Encrypts text files using XOR cipher with a randomly generated key (0–255)
- Prompts for key during decryption with up to **10 attempts**
- Automatically removes the original file after encryption
- Generates prefixed filenames: `Encrypted_<file>` and `Decrypted_<file>`
- Clear error handling with `perror`

---

## ⚙️ How It Works
1. User provides the name of a text file (without extension). The program appends `.txt` automatically.  
2. During encryption:
   - A random key (0–255) is generated.
   - Each byte of the file is XOR’d with the key.
   - Encrypted file saved as `Encrypted_<filename>.txt`.
   - The **original file is deleted**.
3. During decryption:
   - User must re-enter the correct key (max 10 attempts).
   - If correct, decryption restores file as `Decrypted_<filename>.txt`.

---

## 🛠️ Build & Run
### Windows (MinGW)
```bash
gcc -O2 -Wall -Wextra -o filecrypt main.c
filecrypt.exe
```

### Linux / macOS
```bash
gcc -O2 -Wall -Wextra -o filecrypt main.c
./filecrypt
```

---

## 📖 Usage Example
```bash
Enter the name of the file you want to encrypt (without extension): myfile

Attempting to open 'myfile.txt' for encryption...
--- Starting Encryption Process ---
Generated encryption key: 143
Encrypting your file, please wait...
File encrypted successfully!
IMPORTANT: The Encryption Code is 143. Keep it safe!

File 'myfile.txt' deleted successfully.
Opening encrypted file for decryption...

Enter the Encryption Code to decrypt (Attempts left: 10): 143
Correct code entered!
Decrypting your file, please wait...
File decrypted successfully! Saved as: Decrypted_myfile.txt
--- Program Finished ---
```

---

## 📁 Folder Structure
```
File_Encryption_And_Decryption/
├─ main.c        # complete source code
├─ LICENSE       # MIT license
└─ README.md     # this file
```

---

## 🔒 Security Notes
- This program uses a simple XOR cipher, which is **not secure** for real-world encryption.
- Keys are single-byte values (0–255), making brute-force trivial.
- Educational purpose only — do not use for sensitive information.

---

## 🧭 Roadmap
- [ ] Support stronger ciphers (AES/ChaCha20)
- [ ] Add `--keep-original` flag
- [ ] Add hex/ASCII key input
- [ ] Support multiple file formats

---

## 📜 License
MIT — see [LICENSE](./LICENSE).

---

## 🙌 Acknowledgements
This project was built as a **learning exercise in C**, focusing on file handling, random number generation, and XOR operations.

