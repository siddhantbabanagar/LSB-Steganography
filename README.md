# 🔐 LSB Image Steganography in C

## 📌 Overview

This project implements **Least Significant Bit (LSB) Steganography** in C to securely hide and extract secret data within BMP image files.

It demonstrates a strong understanding of:

* Bit-level manipulation
* File handling in C
* Data encoding & decoding

---

## 🎯 Features

* 🔒 Encode secret text into BMP image
* 🔓 Decode hidden message from image
* 📂 Supports `.txt` file embedding
* ⚡ Efficient and lossless data hiding
* 🧩 Modular code structure

---

## 🛠️ Tech Stack

* **Language:** C
* **Concepts:** File I/O, Bitwise Operations, Memory Handling

---

## 📁 Project Structure

```
lsb-steganography/
│── main.c
│── encode.c
│── decode.c
│── common.h
│── encode.h
│── decode.h
│── types.h
│── beautiful.bmp
│── secret.txt
│── stego.bmp
│── output.txt
```

---

## ⚙️ How It Works

LSB (Least Significant Bit) technique modifies the last bit of each pixel byte:

Example:

```
Original: 10110110  
Modified: 10110111
```

This change is **invisible to the human eye**, allowing secure data hiding.

---

## 🚀 How to Run

### 🔧 Compile

```bash
gcc *.c
```

### 🔐 Encode

```bash
./a.out -e beautiful.bmp secret.txt stego.bmp
```

### 🔓 Decode

```bash
./a.out -d stego.bmp output.txt
```

---

## 🖥️ Demo / Sample Output

### 🔐 Encoding Process

```
You chose encoding.
Read and validate is successful
Width of image ----> 1024
Height of image ---> 768
Checking capacity is successful
Magic string encoded successfully!
File extension encoded successfully!
File size encoded successfully!
File data encoded successfully!
The encoding of the file is successful
```

### 🔓 Decoding Process

```
You chose decoding.
Read and validate is successful for decoding
Magic String decoded successfully
Secret file extension decoded successfully
Secret file size is 54

Password is SECRET:
This is my private information

Decoding of the file is successful
```

---

## 📌 Applications

* Secure communication
* Digital watermarking
* Cybersecurity learning
* Data hiding techniques

---

## ⚠️ Limitations

* Works only with BMP images
* No encryption implemented
* Limited hiding capacity

---

## 🔮 Future Improvements

* 🔐 Add AES encryption before encoding
* 🖼️ Support PNG/JPEG formats
* 🔑 Password-based access
* 🖥️ GUI interface

---

## 👨‍💻 Author

**Siddhant Babanagar**
🎓 Electronics & Telecommunication Engineer (2025)
💡 Interested in Embedded Systems & Low-Level Programming

---

## ⭐ Why This Project Matters

This project highlights:

* Strong **C programming fundamentals**
* Understanding of **memory and bits**
* Real-world application of **data security concepts**

---

## 📬 Feedback & Contributions

Feel free to fork, improve, and raise issues!

---

<img width="1257" height="926" alt="s1" src="https://github.com/user-attachments/assets/906e755c-f066-4519-ad2e-ad24d871e089" />
<img width="1481" height="918" alt="s2" src="https://github.com/user-attachments/assets/4709efcb-6144-4185-b9ee-99b11e01a2a5" />
<img width="1487" height="900" alt="s3" src="https://github.com/user-attachments/assets/81501096-5138-4bf0-a7d9-6c4648a4f701" />
<img width="630" height="248" alt="s4" src="https://github.com/user-attachments/assets/f9128f1e-b6c8-4002-b833-558abccd5805" />
<img width="637" height="247" alt="s5" src="https://github.com/user-attachments/assets/c5d76041-d8a4-43be-bf3e-b3a6b83dcf53" />



